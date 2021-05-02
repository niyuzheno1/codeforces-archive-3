#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int S = 26;

int node, son[N][S], fa[N], ed[N], edp[N];
int n, ans, dnum, dfn[N], sz[N];
string s[N];
vector<int> e[N];

void ins(string s, int id){
    int p = 0;
    for(char it : s){
        if(!son[p][it-'a']) son[p][it-'a'] = ++ node;
        p = son[p][it-'a'];
    }
    ed[p] = id; edp[id] = p;
}

void build(){
    queue<int> q; 
    for(int i = 0; i < 26; ++i) if(son[0][i]) q.push(son[0][i]);
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int i = 0; i < 26; ++i){
            if(son[t][i]) q.push(son[t][i]), fa[son[t][i]] =son[fa[t]][i];
            else son[t][i] = son[fa[t]][i];
            ed[t] = ed[t]? ed[t] : ed[fa[t]];
            e[fa[t]].push_back(t);
        }
    }
}

void dfs(int id){
    dfn[id] = ++ dnum, sz[id] = 1;
    for(int it: e[id]) dfs(it), sz[id]+=sz[it];
}

int c[N], buc[N];

void add(int x, int v){
    while(x <= dnum) c[x] += v, x += x&-x;
}
int query(int x){
    int ans = 0;
    while(x) ans += c[x],x-=x&-x; return ans;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> s[i], ins(s[i],i);
    build(), dfs(0);
    for(int i = 1; i <= n; ++i){
        vector<int> pa, cnt;
        int p = 0, pre = 1e9;
        for(char it : s[i]){
            pa.push_back(p=son[p][it-'a']);
            add(dfn[p],1);           
        }
        for(int j = pa.size() -1; ~j; --j){
            int id = j == pa.size()-1? ed[fa[pa[j]]] : ed[pa[j]];
            if(!id) continue;
            int l = j - s[id].size();
            if(l < pre) pre = l, ++buc[id], cnt.push_back(id);
        }
        for(int it : cnt){
            if(!buc[it]) continue;
            int p = edp[it], ap = query(dfn[p]+sz[p]-1) - query(dfn[p]-1);
            if(ap == buc[it]) ++ ans; 
            buc[it] = 0;
        }
        for(int p : pa) add(dfn[p],-1);
    }
    cout << ans <<endl;
}
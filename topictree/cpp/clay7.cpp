//no-unlocked
const int MN = 2d5+10;
int n, a[MN], U[MN], V[MN], esz, NU[], NV[], res[];
vector<int> s[MN];
int allowed[MN], vis[MN], tsz, lt[];
graph g, t;

int idx = 0;
void dfs(int x, int p, int pm){
    if(allowed[x] != pm) return;
    if(vis[x] == pm) return;
    int cid = idx++;
    vis[x] = pm;
    if(p != -1){NU[esz] = p; NV[esz] = cid; ++esz;}
    rep[g.edge[x]](i, g.es[x]) dfs(i, cid, pm);
}
{
    rd(n, a(n), (U--,V--)(n-1));
    g.setEdge(n, n-1, U, V);
    rep(i, n) s[a[i]].push_back(i);
    int mx = max(a(n))+1;
    int psz = Prime(MN-5, res);
    int ans = -1;
    rep[res](pr,psz){
        tsz = 0;
        rep(i, pr, mx, pr){
            for(auto & x : s[i]) {
                allowed[x] = pr;
                lt[tsz++] = x;
            }
        }
        rep[lt](i, tsz){
            esz = 0;
            if(vis[i] != pr) {
                idx = 0;
                dfs(i, -1, pr);
                t.setEdge(esz+1, esz, NU, NV);
                ans >?= t.TreeDiameter();
            }
        }
    }
    wt(ans+1);
}
//no-unlocked
int n,m;
int A[2d5+10], B[], asz;
ll W[], ss[], a[];
wgraph<ll> g;
void dfs(int x){
    if(x == n-1) return;
    rep(i, g.es[x]){
        int y = g.edge[x][i];
        a[asz] = g.cost[x][i];
        ++asz;
        dfs(y);
    }
}
{
    rd(n,m, (A--,B--,W)(m));
    g.setDirectEdge(n,m, A, B, W);
    ll plen = m/g.es[0];
    ll ws = sum(W(m));
    ll flow = ws/plen;
    rep(i, g.es[0]){
        asz = 0;
        a[asz] = g.cost[0][i];
        ++asz;
        dfs(g.edge[0][i]);
        sortA(asz, a);
        rep(j, asz) ss[j] += a[j];
    }
    ll ans = 0;
    rep(i, asz){
        ans += max(0, flow-ss[i]);
    }
    wt(ans);
}
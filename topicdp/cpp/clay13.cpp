//no-unlocked
//working_memory=40MB
int n, m, T;
int F[5100][5100];
int dir[5100][5100];
int U[5100], V[5100], t[5100];
int res[], ans[], asz;
wgraph<int> g;
{
    rd(n, m, T, (U--,V--,t)(m));
    g.setDirectEdge(n,m, U, V, t);
    int isgood = g.g.TopologicalSort(res);
    rep(i, n) rep(j, n) F[i][j] = int_inf, dir[i][j] = -1;
    
    F[0][0] = 0;
    
    rep(xxx, n){
        int i = res[xxx];
        rep(j, xxx+1){
            if(F[i][j] >= int_inf) continue;
            rep(wu, g.es[i]){
                int k = g.edge[i][wu];
                int c = g.cost[i][wu];
                F[k][j+1] <?= F[i][j]+c;
                if(F[k][j+1] == F[i][j]+c) dir[k][j+1] = i;
            }
        }
    }
    int ansx = 0;
    rrep(i, n){
        if(F[n-1][i] <= T){
            ansx = (i+1);
            break;
        }
    }
    int x = n-1, y = ansx-1;
    while(x != -1){
        int nx = dir[x][y];
        int ny = y-1;
        ans[asz] = x;
        ++asz;
        (x, y) = (nx, ny);
    }
    reverse(ans, ans+asz);
    rep(i, asz) ans[i]++;
    wt(asz);
    wt(ans(asz));
}
//no-unlocked
const int MN = 1d5+10;
const int MX = 20;
modint f[MN][MX][3];
int vis[MN][MX][3], n, m, U[MN], V[MN], K, X, par[MN];

graph g;

void dfs(int x, int y){
    rep[g.edge[x]](z, g.es[x]){
        if(z == x) continue;
        par[z] = x;
        dfs(z, x);
    }
}

int poss[3][3];

modint Idic(int v){
    if(v == 0) return K-1;
    if(v == 1) return 1;
    return m-K;
}

modint dfs2(int x, int y, int z){
    if(vis[x][y][z]) return f[x][y][z];
    vis[x][y][z] = 1;
    
    rep(i, g.es[x]+2) rep(j, 0, y+10) dp[i][j] = 0;
    dp[0][0] = 1;
    int idx = 1;
    rep[g.edge[x]](v, g.es[x]){
        if(v == par[x]) continue;   
        rep(j, 0, 3){
            if(!poss[z][j]) continue;
            rep(k, y+1){
                modint mm = dfs2(v, k, j);
                f[x][y][z] 
                // rrep(w,k, y+1){
                //     dp[idx][w] += dp[idx-1][w-k] * mm;
                // }
            }
        }
        ++idx;
    } 

    --idx;
    if(z != 1)
        f[x][y][z]  *= Idic(z);   
    else    
        f[x][y][z]  *= (y-1 >= 0 ? 1 : 0) ;
    return f[x][y][z];
}


{
    poss[0][0] = 1;
    poss[0][1] = 1;
    poss[0][2] = 1;
    poss[1][0] = 1;
    poss[2][0] = 1;
    poss[2][2] = 1;
    rd(n, m, (U--,V--)(n-1), K, X);
    g.setEdgeRootedTree(n, n-1, U, V);
    dfs(0, -1);
    modint ans = 0;
    rep(i, X+1){
        auto r1 = dfs2(0, i, 0);
        auto r2 = dfs2(0, i, 1);
        auto r3 = dfs2(0, i, 2);
        ans += r1 + r2 + r3;
    }
    dfs2(0, 0, 2);
    wt(ans );
}
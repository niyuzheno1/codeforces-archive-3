//no-unlocked
int n, m, a[17][1d4+10];
int d[17][17], sd[17][17];
int f[16][16][1<<16];

int dfs(int x, int y, int z){
    if(z == (1<<n)-1) return sd[x][y];
    int & ret = f[x][y][z];
    if(ret != -1) return ret;
    ret = 0;
    rep(i, n){
        if( ((z >> i ) & 1) == 0){
            ret >?= min(d[y][i], dfs(x, i, z | (1 << i)));
        }
    }
    return ret;
}

{
    memset(f,0xff,sizeof(f));
    rd(n, m, a(n,m));
    rep(i, n) rep(j, n) sd[i][j] = d[i][j] = int_inf;
    rep(i, n) rep(j, i+1, n){
        rep(k, 0, m) d[i][j] <?= abs(a[i][k] - a[j][k]);
        d[j][i] = d[i][j];
    }
    rep(i, n) rep(j, n){
        
        rep(k, 0, m-1) sd[i][j] <?= abs(a[i][k+1] - a[j][k]);
    }
    int ans = 0;
    rep(i, n){
        ans >?= dfs(i, i, 1<<i);
    }
    wt(ans);
}
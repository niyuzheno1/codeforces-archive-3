//no-unlocked
#define pii pair<int,int>
#define mp make_pair
int n, k, c[1d3+10], p[], idxc[], idxt[], r[];
int dp[1d3+10][1d3+10];
pii dir[1d3+10][1d3+10];
int ans[1d3+10][2], asz;

{
    rd(n, (c,p)(n), k, r(k));
    iota(idxc, idxc+n, 1);
    iota(idxt, idxt+k, 1);
    sortA(n, c, p, idxc ); sortA(k, r, idxt);
    rep(i, 0, n) rep(j, 0, k) dir[i][j] = mp(-1,-1);
    rep(i, 0, n){
        rep(j, 0, k){
            if(c[i] <= r[j]){
                dp[i+1][j+1] >?= dp[i][j] + p[i];
                if(dp[i+1][j+1] == dp[i][j] + p[i]){
                    dir[i+1][j+1] = mp(i,j);
                }
            }
            dp[i+1][j] >?= dp[i][j];
            if(dp[i+1][j] == dp[i][j]) dir[i+1][j] = mp(i,j);
            dp[i][j+1] >?= dp[i][j];
            if(dp[i][j+1] == dp[i][j]) dir[i][j+1] = mp(i,j);
        }
    }
    int x = 0, y = 0;
    rep(i, n+1) rep(j, k+1) if(dp[x][y] < dp[i][j]){
        x = i;
        y = j;
    }
    int _x = x, _y = y;
    while(x != -1 && y != -1){
        int nx, ny;
        (nx, ny) = (dir[x][y].first, dir[x][y].second );
        if(x > nx && y > ny){
            if( (idxc[nx], idxt[ny]) == (0, 0)) break;
            
            ans[asz][0] = idxc[nx];
            ans[asz][1] = idxt[ny];
            ++asz;
        }
        (x,y) = (nx, ny);
    }
    x = _x; y = _y;
    wt(asz, dp[x][y]);
    rep(i, asz) wt(ans[i][0], ans[i][1]);
}

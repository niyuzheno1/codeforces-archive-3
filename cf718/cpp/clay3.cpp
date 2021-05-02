//no-unlocked
int n, p[510];
int ans[510][510];
bool within(int x, int y){
    return 0 <= x < n && 0 <= y < n;
}

{
    rd(n, p(n));
    rep(i, n) ans[i][i] = p[i];
    rep(i, n){
        int cnt = p[i]-1;
        int x=i, y = i;
        while(cnt){
            if(within(x,y-1) && ans[x][y-1] == 0){
                ans[x][y-1] = p[i];
                --y;
            }
            else if(within(x+1,y) && ans[x+1][y] == 0){
                ans[x+1][y] = p[i];
                ++x;
            }
            
            --cnt;
        }
    }
    rep(i,n){
        rep(j,i+1){
            int u = ans[i][j];
            wtF("{u} ");
        }
        wt("");
    }
}
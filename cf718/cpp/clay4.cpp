//no-unlocked 
int a[510][510], b[510][510], f[510][510], tmp[510][510], n,m,k, ans[510];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool within(int x, int y){
    return 0 <= x < n && 0 <= y < m;
}
{
    rd(n,m,k, a(n,m-1), b(n-1,m));
    if(k % 2){
        rep(i, m) ans[i] = -1;
        rep(i, n){
            wt(ans(m));
        }
        return 0;
    }
    k>>=1;
    rep(k){
        rep(i, n) rep(j, m) tmp[i][j]= int_inf;
        rep(i, n) rep(j, m) 
        {
            rep(w, 4){
                int ni = i + dx[w];
                int nj = j + dy[w];
                int mi = min(i,ni);
                int mj = min(j,nj);
                if(within(ni,nj)){
                    tmp[ni][nj] <?= f[i][j] + (abs(dx[w]) == 1?  b[mi][mj] : a[mi][mj]);
                }
            }
        }
        rep(i, n) rep(j, m) f[i][j] = tmp[i][j];
    }
    rep(i, n){
        rep(j,m) ans[j] = 2*f[i][j];
        wt(ans(m));
    }
}
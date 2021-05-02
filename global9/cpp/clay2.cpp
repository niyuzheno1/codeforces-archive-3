//no-unlocked
const int MN = 310;
int a[MN][MN], n, m;
int b[MN][MN];
{
    REP(rd_int()){
        rd(n,m, a(n,m));
        rep(i,n) rep(j,m) b[i][j] = 4;
        rep(i,n) rep(j,m) if(i == 0 || i == n-1 || j == 0 || j == m-1) b[i][j] = 3;
        b[0][m-1] = b[0][0] = 2;
        b[n-1][m-1] = b[n-1][0] = 2;
        bool possible = true;
        rep(i,n) rep(j,m) if(b[i][j] < a[i][j]) possible = false;
        if(!possible) wt("NO"), continue;
        wt("YES");
        wt(b(n,m));
    }
}
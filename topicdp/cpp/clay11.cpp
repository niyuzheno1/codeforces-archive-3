//no-unlocked
const int MN = 2d3+10;
mint f[MN][MN];
int n,k;
{
    rd(n,k);
    rep(i,1,n+1) f[1][i] = 1;
    rep(i, 1, k+2)
        rep(j, 1, n+1){
            rep(z, j, n+1, j){
                f[i+1][z] += f[i][j];
            }
        }
    wt(sum(f[k](n+1)));
}

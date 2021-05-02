//no-unlocked
const int MN = 1d3;
int n, a[MN];
{
    REP(rd_int()){
        rd(n,a(n));
        rep(i,n) a[i] = abs(a[i]);
        rep(i,n) if(i & 1) a[i] = -a[i];
        wt(a(n));
    }
}
//no-unlocked
const int MN = 2d5+10;
int n,a[MN];
{
    combination_mint comb ; 
    comb.init (MN) ;
    REP(rd_int()){
        rd(n,a(n));
        int aa = a[0];
        map<int,int> dis;
        rep(i,n) {
            aa &= a[i];
            ++dis[a[i]];
        }
        auto ans = comb.fac[n-2];
        ans *= comb.C(dis[aa],2);
        ans *=2;
        wt(ans);
    }
}
//no-unlocked
const int MN = 100;
ll a[MN];
{
    a[0] = 2050;
    rep(i,1, 15) a[i] = a[i-1]*10;
    REP(rd_int()){
        ll @n;
        int cnt = 0;
        rrep(j, 15){
            if(a[j] < 0 || (j != 0 && a[j] < a[j-1])) continue;
            while(n >= a[j]){
                n -= a[j];
                ++cnt;
            }
        }
        if(n){
            wt(-1);
        }else{
            wt(cnt);
        }
    }
}
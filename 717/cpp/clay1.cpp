//no-unlocked
int a[110];
{
    REP(rd_int()){
        int n,k;
        rd(n, k, a(n));
        int cnt = 0;
        rep(i, 0, n-1){
            int u = 0;
            if(a[i] > k){
                u = k;
                k = 0;
            }else{
                u = a[i];
                k -= a[i];
            }
            a[i] -= u;
            cnt += u;
            if(k == 0) break;
        }
        a[n-1] += cnt;
        wt(a(n));
    }
}
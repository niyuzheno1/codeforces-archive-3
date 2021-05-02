//no-unlocked
ll a[2d5+10];
ll ans[2d5+10], sz;
ll pre[2d5+10];
ll suf[2d5+10];
{
    REP(rd_int()){
        sz = 0;
        int @n;
        n = n+2;
        rd(a(n));
        sortA(n,a);
        rep(i,n+3) pre[i] = suf[i] = 0;
        rep(i,n){
            if(i != 0)  pre[i] = pre[i-1];
            pre[i] += a[i];
        }
        rrep(i,n){
            if(i != n-1) suf[i] = suf[i+1];
            suf[i] += a[i];
        }
        if(pre[n-3] == a[n-2] || pre[n-3] == a[n-1]){
           wt(a(n-2));
           continue; 
        }
        bool okay = false;
        rep(i,n-2){
            int snow = i > 0 ? pre[i-1]:0;
            snow += (i + 1) < n ? suf[i+1]: 0;
            snow -= a[n-1];
            if(snow == a[n-1]){
                okay = true;
                rep(j,n-1){
                    if(j == i) continue;
                    ans[sz] = a[j]; ++sz;
                }
                wt(ans(sz));
                break;
            }
        }
        if(!okay){
            wt(-1);
        }
    }
}
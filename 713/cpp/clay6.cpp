//no-unlocked
ll n, c, a[2d5+10],b[2d5+10];


{
    REP(rd_int()){
        rd(n,c, a(n),b(n-1));
        ll mday = c;
        ll cday = 0;
        ll allowance = 0;
        rep(i,n){
            ll ncday = cday;
            ncday += (c-allowance) /+ a[i];
            mday <?= ncday;
            if(i == n-1) break;
            auto p = (b[i]-allowance) /+ a[i];
            cday += p;
            allowance += p * a[i] - b[i];
            ++cday;
        }
        wt(mday);
    }
}
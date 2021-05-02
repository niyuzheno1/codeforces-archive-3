bool ok(ll csum){
    return 2*csum < tot;
}
void cpcp(ll _csum, vl tmp){
    vl cum = get_cum(tmp);
    vl cum2(sz(tmp)+1);
    rep(i, sz(tmp)){
        cum2[i+1] = tmp[i];
        if(i) cum2[i+1] += cum2[i-1];
    }
    rep(i, 1, sz(tmp)){
        ll csum = cum[i] + _csum;
        if(ok(csum)){
            int max_ok = (sz(tmp)-1-i)>>1;
            int num = lstTrue(0,max_ok, [&] (int x){
                return ok(csum + cum2[i+2*x]-csum2[i]);
            });
            ans += num+1;
        }
    }
}


void solve(int tc){
    rd(N); A.rsz(N); rd(A);
    vl cum = get_cum(A);
    tot = cum.bk;
    ans = 0;
    if( N <= 2){
        rep(i,N) if(cum[i] != tot-cum[i]) ++ans;
        wt(ans);
        return;
    }
    ans = 1;
    rep(i, 1, N) if(cum[N]- cum[i] < cum[i]) ++ans;
    rep(a, 2) rep(b, 2){
        vl tmp = A;
        ll csum = 0;
        if(a) tmp.erase(begin(tmp));
        if(b) sum += tmp.bk, tmp.pop_back();
        cpcp(csum, tmp);
    }
    wt(ans);
}
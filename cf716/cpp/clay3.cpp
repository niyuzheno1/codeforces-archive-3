//no-unlocked
int n;
int ans[1d5+10],asz;
{
    rd(n);
    rep(i,1, n){
        ll u = i;
        if(u != 1 && gcd(u,n) != 1) continue;
        ans[asz] = u;
        ++asz; 
    }
    ll c = 1;
    rep(i, asz){
        c *= ans[i];
        c %= n;
    }
    if(c != 1) --asz;
    wt(asz);
    wt(ans(asz));
}
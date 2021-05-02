//no-unlocked
#define MD 2147483647
ll C(ll x, ll y){
    ll prod = 1;
    rep(i, x-y+1, x+1){
        prod *= i;
    }
    rep(i,1, y+1) prod /= i;
    return prod;
}
int n,k;
{
    rd(n,k);
    ll ans = 0;
    if(k >= 1) ++ans;
    if(k >= 2) ans += C(n,2);
    if(k >= 3) ans += C(n,3) * 2;
    if(k >= 4) ans += C(n,4) * 9;
    wt(ans);
}
//no-unlocked
int n, m;

{
    rd(n,m);
    /*not counting the horizontal ones*/
    ll ans = 0;
    rep(i, n+1) rep(j, m+1){
        ll up = 2*min(m-j, j) + 1;
        ll down = min(i, n-i);
        ans += up * down;
    }
    rep(i, n+1) rep(j, m+1){
        ans += min(m-j, j);
    }
    wt(ans);
}
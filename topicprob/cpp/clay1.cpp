//no-unlocked
ll n, m, a[51][51];
ll col[2][51];
ll row[2][51];
{
    rd(n,m,a(n,m));
    rep(i,n) rep(j,m){
            ++col[a[i][j]][j];
            ++row[a[i][j]][i]; 
    }
    // rep(k, 2){
    //     wt(col[k](m));
    //     wt(row[k](n));
    // }
    ll ans = 0;
    // count the row
    rep(k, 2){
        rep(i, n) ans += (1LL<<row[k][i]), --ans;
    }
    rep(k,2){
        rep(i, m) ans += 1LL << col[k][i];
        rep(i, m) ans -= col[k][i]+1LL;
    }
    wt(ans);
}
//no-unlocked
int s[3100], c[], a[], b[];
int n;
{
    rd(n, s(n),c(n));
    rep(i,n) a[i] = b[i] = int_inf;
    rep(i,n) rep(j,i+1,n) {
        if(s[i] >= s[j]) continue;
        a[i] <?= c[j];
        b[j] <?= c[i];
    }
    int ans = int_inf;
    rep(i,n) {
        if(a[i] >= int_inf || b[i] >= int_inf) continue;
        ans <?= a[i]+b[i]+c[i];
    }
    if(ans >= int_inf) wt(-1);
    else wt(ans);
}
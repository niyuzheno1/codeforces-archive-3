//no-unlocked
int n;
ll p, L[1d5+10], R[];
double ans = 0;
{
    rd(n, p, (L, R)(n));
    rep(i, n){
        int nx = (i+1)%n;
        ll cnt1 = R[i]/p - (L[i]-1)/p;
        ll cnt2 = R[nx]/p - (L[nx]-1)/p;
        double c1 = double(cnt1)/double(R[i]-L[i]+1);
        double c2 = double(cnt2)/double(R[nx]-L[nx]+1);
        double prob = c1 +  c2 - c1 * c2;
        ans += prob * 2000.0;
    }
    wt(ans);
}
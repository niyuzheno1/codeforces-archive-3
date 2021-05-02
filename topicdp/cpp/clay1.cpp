//no-unlocked
ll g[62];
ll zero = 0;
ll * f(int x){
    if(x < 0) return &zero;
    return &g[x];
}
int n;
{
    g[2] = 2;
    rep(i,3,61){
        *f(i) = ((*f(i-2))<<1) ;
    }
    rd(n); wt(*f(n));
}
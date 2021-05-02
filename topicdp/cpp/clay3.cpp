//no-unlocked
int n;
int c[1d3+30], v[1d3+30];
ll f[2d5];
char s[30];
int tov(int n){
    int ret = 0;
    rep(i, n){
        int u = s[i]-'A';
        ret |= (1<<u);
    }
    return ret;
}
{
    rd(n);
    rep(i, 1<<3) f[i] = 1e9;
    rep(i,n){
        int m = 0 ;
        rd(c[i], s@m);
        v[i] = tov(m);
        f[v[i]] <?= c[i];
    }
    rep(i,1<<3){
        rep(j,n)
        {
            f[i | v[j]] <?= f[i] + c[j];
        }
    }
    if(f[(1<<3)-1] >= 1e9) wt(-1), exit(0);
    wt(f[(1<<3)-1]);
}
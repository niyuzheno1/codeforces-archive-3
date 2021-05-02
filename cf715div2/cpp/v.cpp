//no-unlocked
ll s[2d3+10], n;
{
    rd(n,s(n));
    ll sd = 0, ma=0,mi = 1LL << 51;
    rep(i,n){
        mi <?= s[i];
        ma >?= s[i];
        sd += ma - mi;
    }
    wt(sd);
}
//no-unlocked
ll s[2d3+10], n;
ll s1[2d3+10], s2[2d3+10], sz;
{
    rd(n,s(n));
    map<int,int> cnt;
    rep(i, n) ++cnt[s[i]];
    sz = 0;
    for(auto x: cnt){
        s1[sz] = -x.second;
        s2[sz] = x.first;
        ++sz;
    }
    sortA(sz, s1, s2);
    ll ans = 0;
    ll ma = 0, mi = 1LL<<50;
    rep(i, sz){
        ll x = s2[i];
        ma >?= x;
        mi <?= x;
        ans += (ma-mi) * -s1[i];
    }
    ll ans2 = 0;
    sz = 0;
    ma = 0, mi = 1LL<<50;
    for(auto x: cnt){
        s1[sz] = -x.second;
        s2[sz] = -x.first;
        ++sz;
    }
    sortA(sz, s1, s2);
    rep(i, sz){
        ll x = -s2[i];
        ma >?= x;
        mi <?= x;
        ans2 += (ma-mi) * -s1[i];
    }
    wt(min(ans,ans2));
}
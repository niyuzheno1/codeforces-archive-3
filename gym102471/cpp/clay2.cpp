//no-unlocked
ll vis[1d5+30], a[], b[], c[], d[], dsz, sz, n;
ll cnt(){
    ll scores = 0;
    rep(i, dsz) scores += a[d[i]-1];
    rep(i, dsz){
        rep(j, dsz){
            if(i == j) continue;
            bool sub = false;
            ll tmp = 1;
            rep(k, 0, 35){
                tmp *= d[i];
                if(tmp > n) break;
                if(tmp == d[j]) sub = true;
            }
            if(sub) scores -= b[d[j]-1];
        }
    }
    return scores;
}
ll binenum(){
    ll ans = 0;
    rep(i, 1<<sz){
        dsz = 0;
        rep(j, sz) 
        if( (i>>j) & 1){
            d[dsz] = c[j];
            dsz++;
        }
        ll r1 = cnt();
        ans >?= r1;
    }
    return ans;
}

{
    rd(n, a(n), b(n));
    rep(i,2, n){
        if(i * i > n) break;
        ll j = i * i;
        while(j <= n){
            vis[j] = 1;
            j *= i;
        }
    }
    ll ans = a[0];
    rep(i, 2, n+1){
        if(vis[i]) continue;
        if(i * i <= n){
            sz = 0;
            ll j = i;
            while(j <= n){
                c[sz++] = j;
                j *= i;
            }
            ans += binenum();
        }else{
            ans += a[i-1];
        }
    }
    wt(ans);
}
//no-unlocked
ll n, l, r, s;
const int MAXN = 510;
ll ans[MAXN];
ll con[MAXN];

bool out(){
    rep(i, 0, n+2) con[i] = 0;
    rep(i, 1, n+1){
        if(ans[i] != 0){
             ++con[ans[i]];
             if(con[ans[i]] > 1) return false;
        }
    }
    int l = 1;
    rep(i,1,n+1){
        
        while(con[l]) ++l;
        if(ans[i] != 0) continue;
        ++con[l];
        ans[i] = l;
    }
    ll * aans = &ans[1];
    wt(aans(n));
    return true;
}

bool dfs(ll cpos, ll s, ll maxm){
    if(cpos > r){
        if(s > 0) return false;
        return out();
    }
    if(s <= 0 || maxm <= 0){
        return false;
    }

    ll sx = 0,  cmax = maxm;
    rep(i,cpos, r+1){
        sx += cmax;
        --cmax;
    }
    if(s - sx > 0) return false; 
    bool ret = false;
    rrep(i,1, maxm+1){
        if(s - i < 0) continue;
        ans[cpos] = i;
        ret = dfs(cpos+1, s-i, i-1);
        if(ret) break;
    }
    return ret;
}

void solve(ll cpos, ll s, ll maxm){
    ll d = (r-l+1), minm = 1;
    rep(i, l, r+1){
        bool flagset = false;
        rep(j,minm, n+1){
            
        }
    }

    if(!out()){
        wt(-1);
    }
    if(cpos > r){
        if(s > 0) return false;
        return out();
    }
    if(s <= 0 || maxm <= 0){
        return false;
    }

    ll sx = 0,  cmax = maxm;
    rep(i,cpos, r+1){
        sx += cmax;
        --cmax;
    }
    if(s - sx > 0) return false; 
    bool ret = false;
    rrep(i,1, maxm+1){
        if(s - i < 0) continue;
        ans[cpos] = i;
        ret = dfs(cpos+1, s-i, i-1);
        if(ret) break;
    }
}

{
    REP(rd_int()){
        rd(n,l,r,s);
        solve(l, s, n);
        
        rep(i,0, n+3) ans[i] = 0;
    }
}
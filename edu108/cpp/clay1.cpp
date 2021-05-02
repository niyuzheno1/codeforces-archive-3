//no-unlocked
ll r, b, d;
bool dfs(ll  x, ll y, ll d){
    if(x > y) swap(x,y);
   
    if(x == 0) return y == 0;
     if( abs(x-y) <= d) return true;
    ll a = bsearch_max[ll, k, 0, x] ( k + k * d <= y);
    if(a == 0) return false;
    return dfs(x - a, y - (a + a * d), d );
}
{
    REP(rd_int()){
        rd(r,b,d);
        if(r > b) swap(r,b);
        if(r + r * d < b) wt("NO");
        else wt("YES");
        //wt(dfs(r,b,d) ? "YES ": "NO"); 
    }
}
//no-unlocked
ll pre[5100], pos[], a[], b[], n;
ll getpre(int x){ return x < 0? 0 : pre[x];}
ll getpos(int x){ return x >= n? 0 : pos[x];}
ll f[5100][5100];
ll rev(int x , int y){
    if(f[x][y]) return f[x][y];
    ll & ret = f[x][y];
    if(x == y) return ret=a[x]*b[x];
    if(x + 1 == y) return ret=(a[x]*b[y]) + a[y]*b[x];
    return ret=rev(x+1,y-1) + a[x]*b[y] + a[y]*b[x];
}
{  
    rd(n, a(n), b(n));
    rep(i, n){
        pre[i] = (i == 0? 0 : pre[i-1]) + a[i]*b[i];
    }
    rrep(i, n){
        pos[i] = (i+1 == n? 0 : pos[i+1]) + a[i]*b[i];
    }
    ll ans = 0;
    rep(i, n){
        rep(j, i, n){
            ll tmp = getpre(i-1) + getpos(j+1) + rev(i,j);
            ans >?= tmp;
        }
    }
    wt(ans);
}
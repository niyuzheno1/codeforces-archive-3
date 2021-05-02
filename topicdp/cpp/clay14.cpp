//no-unlocked
int n, k, a[3d5+10], b[3d5+10], c[3d5+10]; 
{
    rd(n, k, a(n));
    rep(i,n) c[i] = a[i];
    rep(i,n) a[i] ^= 1;
    
    a[n] = k+100;
    ++n;
    partial_sum(a,a+n, b);
    auto gr = [&] (int l, int r){
        if(l == 0) return b[r];
        return b[r]-b[l-1];
    };
    int ans = 0,  idx = 0;
    rep(i, n-1){
        int u =bsearch_max[int, md, i, n](gr(i, md) <= k );
        if(gr(i,u) > k) continue;
        int len = u-i+1;
        ans >?= len;
        if(ans == len) idx = i;
    }
    wt(ans);
    --n;
    rep(i, idx, idx + ans) c[i] = 1;
    wt(c(n));
}
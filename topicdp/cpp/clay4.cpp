//no-unlocked
int n,k;
const int MN = 1d5+20;
int pre[MN],  t[MN], a[MN], b[MN];
int range_pre(int x, int y){
    //TODO: compute the sum of pre from interval [l,r]
    if(y < 0) return 0;
    if(x == 0) return pre[y];
    return pre[y]-((x==0)?0:pre[x-1]);
}
int range_sum(int x, int y){
    if(y < 0) return 0;
    if(x == 0) return b[y];
    return b[y] - ((x==0)?0:b[x-1]);
}
{
    rd(n,k,a(n), t(n));
    rep(i,n) b[i] = ((i == 0)? 0 : b[i-1]) + a[i];
    rep(i,n) pre[i] = ((i == 0)? 0 : pre[i-1]) + ((t[i]==1)?a[i]:0);
    int ans = 0;
    rep(i,n-k+1){
        ans >?= range_pre(0,i-1) + range_sum(i,i+k-1) + range_pre(i+k,n-1);
    }
    wt(ans);
}
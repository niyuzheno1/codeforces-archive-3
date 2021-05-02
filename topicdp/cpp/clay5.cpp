//no-unlocked
const int MN = 2100;
ll dp[MN][MN];
int a[MN], b[];
int n,k;
ll p;
ll dist(int x, int y){
    // TODO: compute the total time of travel for person x to key y and return to office
    return abs(a[x]-b[y])+abs(b[y]-p);
}
ll zero = ll_inf;
ll * f(int x , int y){
    if(x < 0 || y < 0 || x > n || y > k) return &zero;
    return &dp[x][y];
}
{
    rd(n,k,p, a(n), b(k));
    sortA(n, a);
    sortA(k, b);
    rep(i,n+2) rep(j,k+2) (*f(i,j)) = ll_inf;
    *f(0,0) = 0;
    rep(i,n+1){
        rep(j,k){
            *f(i,j+1) <?= *f(i,j);
            *f(i+1,j+1) <?= max(*f(i,j),dist(i,j));
        }
    }
    wt(*f(n,k));   
}
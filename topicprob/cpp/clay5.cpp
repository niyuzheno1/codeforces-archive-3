//no-unlocked
double p1[2d3+10], p2[];
int n, t;
double p;
{
    rd(n, p, t);
    p1[0] = 1;
    rep(i, t){
        rep(j, 0, n+1){
            if(j == 0) p2[j] = p1[j]*(1.0-p);
            else if(j == n) p2[j] = p1[j] + p1[j-1]*p;
            else p2[j] = p1[j] * (1-p) + p1[j-1] * p;
        }
        rep(j,0,n+1) p1[j] = p2[j];
    }
    double ans = 0;
    rep(j,0,n+1) ans += double(j) * p1[j];
    wt(ans); 
}
//no-unlocked
int n,m;
const int MN = 2d5+10;
char a[MN];
int allowed[300];
ll f[MN];
ll g[MN];
char b[MN];
{
    rd(n,m, a);
    rep(i,m) rd(b), allowed[b[0]] = 1;
    rep(i,1,n+1) g[i] = g[i-1] + i;
    ll ans = 0 ;
    rep(i,n+1){
        if(i == 0){
            f[i] = allowed[a[i]] ;
        }else{
            if(!allowed[a[i]]){
                
                ans += g[f[i-1]];
                f[i] = 0;
            }else{
                f[i] = f[i-1]+1;
            }
        }
    } 
    wt(ans);
}
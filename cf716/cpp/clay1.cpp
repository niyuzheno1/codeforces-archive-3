//no-unlocked
int n, a[110];
{
    REP(rd_int()){
        rd(n, a(n));
        bool flag = false;
        rep(i, n){
            int u = (int)sqrt(a[i]);
            if(u*u != a[i] && (u+1)*(u+1) != a[i]){
                flag = true;
            }
        }
        if(flag) wt("YES");
        else wt("NO");
    }
}
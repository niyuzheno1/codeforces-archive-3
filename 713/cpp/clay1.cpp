//no-unlocked
int a[110];
{
    REP(rd_int()){
        int n;
        rd(n,a(n));
        rep(i,n){
            bool flag = true;
            rep(j,n){
                if(i != j && a[i] == a[j]) flag = false;
            }
            if(flag){
                wt(i+1);
                break;
            }
        }
    }
}
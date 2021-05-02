//no-unlocked
int a[2100],b[2100],n;
{
    REP(rd_int()){
        rd(n, a(n));
        int l = 0, r = n-1;
        rep(i, 0, n){
            if(a[i] % 2 == 0){
                b[l++] = a[i];
            }else{
                b[r--] = a[i];
            }
        }
        wt(b(n));
    }
}
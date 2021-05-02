//no-unlocked
int r[51];
{
    REP(rd_int()){
        int @n;
        rd(r(n));
        int ans= 0;
        rep(i,n){
            if(r[i] == 1 || r[i] == 3){
                ++ans;
            }
        }
        wt(ans);
    }
}
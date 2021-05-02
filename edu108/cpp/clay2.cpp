//no-unlocked
#define bs bitset<10010> 
bs f[110][110];
{
    f[1][1] = 1;
    rep(i, 1, 110){
         rep(j,1, 110){
             if(i == 1 && j == 1) continue;
             f[i][j] = (f[i-1][j] << j) | (f[i][j-1] << i); 
        }
    }
    REP(rd_int()){
        int @n, @m, @k;
        wt(f[n][m].test(k) ? "YES" : "NO");
    }
}
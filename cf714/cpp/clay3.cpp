//no-unlocked
const int MN = 100, MM = 2d5+10;
mint g[MM][10];
char s[MN];
{
    rep(i,0,10) g[0][i] = 1;
    rep(j,0,MM-5)    
    rep(i,0,10){
            if(i != 9)
                g[j+1][i] = g[j][i+1];
            else
                g[j+1][i] = g[j][0]+g[j][1];
    }
    

    REP(rd_int()){
        int n,m;
        rd(s@n,m);
        mint len = 0;
        rep(i,0,n){
            len += g[m][s[i]-'0'];
        }
        wt(len);

    }
}
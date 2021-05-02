//no-unlocked
const int MN = 1d7+10;
int a[MN];
int sx[MN];
{
    rep(i, 1, MN){ 
        rep(j,i, MN, i){ a[j] += i;}
        if(a[i] <= 1d7 && sx[a[i]] == 0 )sx[a[i]] =i;
    }
    REP(rd_int()){
        int @x;
        wt(sx[x]-(!sx[x]));
    }
}
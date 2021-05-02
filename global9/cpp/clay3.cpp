//no-unlocked
const int MN = 3d5+10;
int n, smin[MN], pmax[MN], a[MN];
{
    REP(rd_int()){
        rd(n,a(n));
        // rep(i,0,n){
        //     if(i == 0){
        //         pmax[i] = a[i];
        //     }else{
        //         pmax[i] = pmax[i-1];
        //         if(a[i] < a[i-1]) pmax[i] >?= a[i];
        //     }
        // }
        bool ok = false;
        rep(i,0,n){
            if((i == n-1 || a[i] < a[n-1]) && (i == 0 || a[i] > a[0])){
                ok = true;
            }
        }
        if(ok) wt("YES");
        else wt("NO");

    }
}
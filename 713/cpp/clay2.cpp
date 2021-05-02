//no-unlocked
char a[410][410];
int minx, miny, maxx, maxy;
{
    REP(rd_int()){
        int n;
        rd(n,a(n));
        minx = 1e9;
        miny = 1e9;
        maxx = 0;
        maxy = 0;
        rep(i,n) rep(j,n) if(a[i][j] == '*'){ minx <?= i; miny <?= j; maxx >?= i; maxy >?= j;}
        if(minx == maxx){
            if(minx == 0){
                a[n-1][miny] = '*';
                a[n-1][maxy] = '*';

            }else{
                a[0][miny] = '*';
                a[0][maxy] = '*';

            }
        }else if(miny == maxy){
            if(miny == 0){
                a[minx][n-1] = '*';
                a[maxx][n-1] = '*';
            }else{
                a[minx][0] = '*';
                a[maxx][0] = '*';
            }
        }else{
            a[minx][miny] = '*';
            a[minx][maxy] = '*';
            a[maxx][miny] = '*';
            a[maxx][maxy] = '*';
        }
        rep(i,n) wt(a[i]);
    }
}
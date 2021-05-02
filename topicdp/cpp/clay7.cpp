//no-unlocked
int v1,v2, t,d;
int a[100];
int b[100];
ll f[110][20*110];
const int inf = -ll_inf+30;
{
    rd(v1,v2,t,d);
    rep(i, t+2) rep(j, (t+2)*d+v1+v2){
        f[i][j] = inf;
    }
    int t1 = v1, t2 = v1;
    rep(i, t){
        a[i] = t1;
        b[i] = t2;
        t1 += d;
        t2 -= d;
        t2 >?= 0;
    }
    f[0][v1] = 0;
    rep(i, t){
        rep(j,b[i], a[i]+1){
            if(f[i][j] <= inf) continue;
            rep(k, -d, d+1){
                if(k+j < 0) continue;
                f[i+1][j+k] >?= f[i][j] + j;
            }
        }
    }
    wt(f[t-1][v2]+v2);
}
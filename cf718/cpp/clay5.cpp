//no-unlocked
#include <cstring>
int n, q;
int a[1d5+20];
int que[1d5+10][2];
int fs[1d5+20], fsz;
int closest[1d5+20];
{
    
    rd(n, q, a(n), que(q, 2));
    IntMap f(n+2);
    memset(closest, 0xff, sizeof(closest));
    rep(i, n+2) f[i] = n;
    rrep(i, n){
        fsz = Factor( a[i], fs);
        rep(j, fsz){
            int x = fs[j];
            if(closest[x] != -1) f[i] <?= closest[x];
            closest[x] = i;
        }
    }
    rrep(i,n) f[i] <?= f[i+1];
    rep(i, q){
        int l,r;
        (l,r) = (que[i][0]-1,que[i][1]);
        int cnt = bsearch_max[int, k, 0 ,1d5+1] (f.getNext(l,k) < r);
        wt(cnt+1);
    }
}
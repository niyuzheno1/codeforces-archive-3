//no-unlocked
const int MN = 1d5+10;
int dll[MN];
int nxt[MN],pre[MN], n, a[MN], ap[MN];
int q[MN], rdx[MN], qtot, ans[MN], atot;
int dbg = 0;
void del(int x){
    a[x] = 0;
    int u = nxt[x], v = pre[x];
    nxt[v] = u;
    pre[u] = v;
}
void push(int x, int y){
    arrInsert(qtot, qtot, q, x, rdx, y);
}

void pusha(int x){
    arrInsert(atot, atot, ans, x+1);
}
void init_t(){
    qtot = atot = 0;
    rep(i, n) pre[i] = i-1, nxt[i] = i + 1;
    nxt[n-1] = 0;
    pre[0] = n-1;
}
{
    int @Tcases;
    //if(Tcases > 50) dbg = 1;
    int cntn = 0;
    REP(T,Tcases){
        rd(n, a(n));
        if(dbg){
            rep(i,n){
                ap[i] = a[i];
            }
        }
        init_t();
        
        int i = 0;
        while(i < n){
            int ci = i;
            if(gcd(a[i], a[nxt[i]]) == 1) {
                push(nxt[i], 0);
                i = nxt[nxt[i]];
                if(i <= ci) rdx[qtot-1] = 1, break;
            }else{
                i = nxt[i];
                if(i <= ci) break;
            }
        }
        int np = -10, nrd = 0, lowl = 0;
        rep(i, qtot){
            int x = q[i], crd = rdx[i];
            //if(x == 7) __asm int 3;
            if( gcd(a[pre[x]], a[x]) != 1)  continue;
            if( (x == np && crd <= nrd) ){
                //np = -10;
                //push(x, crd+1);
                continue;
            }
            pusha(x);
            del(x);
            np = nxt[x];
            nrd >?= crd;
            if(gcd(a[pre[x]],a[nxt[x]]) == 1){
                if(nxt[x] < x) {
                    
                    push(nxt[x], nrd+2);
                    ++ nrd;
                }
                else
                    push(nxt[x], nrd+1);
            }
        }
        if(dbg == 0){
            wt(atot, ans(atot));
        }else{
            cntn += atot + 1;
            if(cntn >=  214){
                wt(n, ap(n));
                return 0;
            }
        }
    }
}
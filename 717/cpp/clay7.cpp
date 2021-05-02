//no-unlocked
int n;
int a[110];
const int MS = 110*2100;
bitset<MS> t;
void process(bitset<MS> & x ){
    x.reset();
    x[0] = 1;
    rep(i, 0, n) x |= (x << a[i]);
}

{
    rd(n, a(n));
    process(t);
    int u = sum(a(n));
    if(u % 2 == 1){
        wt(0);
        return 0;
    }
    if(t[u>>1]){
        int idx = 0;
        rep(i,n){
            if(a[i] < a[idx]){
                idx = i;
            }
        }
        wt(1);
        wt(idx+1);
    }else{
        wt(0);
        return 0;
    }
}
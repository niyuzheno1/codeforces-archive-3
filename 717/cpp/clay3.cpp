//no-unlocked
int n;
int a[110], idx[110];
const int MS = 110*2100;
bitset<MS> t;
void process(bitset<MS> & x ){
    x.reset();
    x[0] = 1;
    rep(i, 0, n) x |= (x << a[i]);
}
void process(bitset<MS> & x,int skip){
    x.reset();
    x[0] = 1;
    rep(i, 0, n) if(i != skip) x |= (x << a[i]);
}

{
    rd(n, a(n));
    rep(i, n) idx[i] = i+1;
    sortA(n,a, idx);
    process(t);
    int u = sum(a(n));
    if(u % 2 == 1){
        wt(0);
        return 0;
    }
    if(t[u>>1]){
        int ret = 0;
        rep(i,n){
            int v = u - a[i];
            if( v % 2 == 1) {ret = idx[i]; break;}
            process(t, i);
            if(t[v >> 1] == 0){
                ret = idx[i];
                break;
            }
            
        }
        wt(1);
        wt(ret);
    }else{
        wt(0);
        return 0;
    }
}
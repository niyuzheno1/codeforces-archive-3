//no-unlocked
const int MN = 1d5+10;
int n,m, a[MN], L[MN], R[MN], E[MN], osz, K[MN];
int P[MN], V[MN], C[MN], csz, cnt[MN], g[MN], ans[MN];
int lb[5*MN], rb[5*MN];
int b[MN], xord[5*MN];
int * ord = xord + MN;
int * slb = lb+3;
int * srb = rb+3;
class getmindist{
public:   
    int mx;
    getmindist(){
        mx = 0;
    }
    int& ct(int x){
    }
    int& glb(int x){
        return lb[x+3];
    }
    int& grb(int x){
        return rb[x+3];
    }
    int len(int x){
        return grb(x)-glb(x)+1;
    }
    int plen(int x)
    {
        if(len(x) > 0)
         return grb(x)-glb(x)+1;
        return 0;
    }
    void addval(int x){
        int c = g[x];
        ++ord[glb(c)];
        grb(c+1) = glb(c);
        if(glb(c+1) == n) glb(c+1) = glb(c);
        if(glb(c) == grb(c)) glb(c) = n-1;
        ++glb(c);
        ++g[x];
    }   
    void delval(int x){
        int c = g[x];
        --ord[grb(c)];
        if(glb(c-1) == n) grb(c-1) = grb(c);
        glb(c-1) = grb(c);
        if(glb(c) == grb(c)) glb(c) = n;
        --grb(c);
        --g[x];
    }
    void change(int pos, int x){
        if(x == 1){
            x = a[pos];
            addval(x);
        }else{
            x = a[pos];
            delval(x);
        }
    }
    void modify(int pos, int x, int l, int r){
        if(x == 1){
            x = P[pos];
            if(l <= x <= r) delval(a[x]);
            a[x] = C[pos];
            if(l <= x <= r) addval(a[x]);
        }else{
            x = P[pos];
            if(l <= x <= r) delval(a[x]);
            a[x] = V[pos];
            if(l <= x <= r) addval(a[x]);
        }
    }
    int computeAns(int l, int r, int k){
        int res = n;
        int i = 0, j = 0, su = 0;
        while(i < n && ord[i] > 0){
            while(j < n && ord[j] > 0 && su < k){
                su += len(ord[j]);
                j = grb(ord[j])+1;
            }
            if(su >= k) res <?= ord[i] - ord[j-1];
            su -= len(ord[i]);
            i = grb(ord[i]) + 1;
        }
        if(res == n) return -1;
        return res;
    }
    void reset(){
        glb(0) = 0;
        grb(0) = n-1;
        rep(i, 1, n) glb(i) =  n, grb(i) = 0;
    }
};
{
    rd(n,m,a(n));
    rep(i, m){
        int @type;
        if(type == 1){
            int @l, @r, @k;
            (L[osz], R[osz], K[osz]) = (l-1,r-1,k);
            E[osz] = csz;
            ++osz;
        }else{
            int @p, @x;
            ++csz;
            (P[csz], C[csz]) = (p-1,x);
        }
    }
    rep(i, 1, csz+1){
        V[i] = a[P[i]];
        a[P[i]] = C[i];
    }
    int l = 0, r = -1, cl = 0, cr = 0, t = csz, px = 0;   
    sqrt_decomp<getmindist> sqde;
    sqde.sinit(osz+10, (int)pow(n,2.0/3.0), 1);
    sqde.transfer(osz, L, R, E);
    sqde.a->reset();
    while( (px = sqde.next(l,r,cl,cr, t) ) != -1){
        int ret = sqde.a->computeAns(L[px],R[px], K[px]);
        ans[px] = ret;
    }
    rep(i, osz) wt(ans[i]);
}
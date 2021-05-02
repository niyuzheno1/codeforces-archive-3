//no-unlocked
const int MN = 1d5+10;
const int MM = 2d5+10;
int f[MN];
int a[MM], ans[MN];
int l[MN], r[MN], c[MN];
int tot,tota, n , m;
void push(int x){
    arrInsert(tot,tot, a, x);
}
void pusha(int x){
    arrInsert(tota,tota, ans,x);
}

void clr(){
    rep(i,tot)  f[a[i]] = 0;
}

{
    REP(T,rd_int()){
        //if(T == 5){ __asm int 3;}
        tot = 0;
        tota = 0;
        rd(n,m);
        rep(i,m){
            int @k;
            l[i] = 1e9, r[i] = 0;
            rep(j,k){
                int @x;
                l[i] <?= tot;
                r[i] >?= tot;
                push(x);
            }
            ++r[i];
        }
        rep(i,m) ++f[a[l[i]]], c[i] = l[i];
        rep(i,m){
            int j = l[i]+1;
            while(f[a[c[i]]]  > (m /+ 2) && j < r[i] ){
                --f[a[c[i]]];
                ++f[a[j]];
                c[i] = j;
                ++j;
            }
        }
        bool flag = true;
        rep(i,m) rep(j, l[i],r[i]) if(f[a[j]] > (m/+2)) flag = false;
        if(!flag) wt("NO"),clr(), continue;
        rep(i,m) pusha(a[c[i]]);
        wt("YES");
        wt(ans(m));
        clr();       
        
    }
}
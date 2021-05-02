//no-unlocked
int a[2100];
int pre[2100];
int getrange(int x, int y){
    if(x == 0){
        return pre[y];
    }
    return pre[x-1] ^ pre[y];
}
{
    REP(rd_int()){
        int @n;
        rd(a(n));
        rep(i, n){
            if(i == 0) pre[i] = 0;
            else pre[i] = pre[i-1];
            pre[i] ^= a[i];
        }
        bool ret = false;
        rep(i,n-1){
            if(getrange(0,i) == getrange(i+1,n-1)) ret = true;
            rep(j,i+1, n-1){
                if(getrange(0,i) == getrange(i+1,j) && getrange(j+1, n-1) == getrange(i+1,j)) ret = true;
            }
        }

        if(ret) wt("YES");
        else wt("NO");
    }
}
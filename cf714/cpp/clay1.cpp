//no-unlocked
const int MAXN = 110;
int ans[MAXN], s[MAXN];
{
    REP(rd_int()){
        int @n,@k, kk,i = 1 ;
        rep(i,0,n+3) s[i] = ans[i] = 0;
        int  c = n;
        kk = k;
        i = 1;
        while(k > 0 && i < n){
            ans[i] = c;
            s[c] = 1;
            i += 2;
            --c;
            --k;
        }
        if(k > 0){
            wt(-1); continue;
        }
        c = 1;
        rep(i,0,n){
            if(ans[i] != 0) continue;
            while(s[c]) ++c;
            ans[i] = c;
            s[c] = 1;
        }
        int cnt = 0;
        rep(i,1,n-1){
            if(ans[i] > ans[i-1] && ans[i] > ans[i+1]) cnt = cnt + 1;
        }
        if(cnt == kk){
            wt(ans(n));
        }else{
            wt(-1);
        }
    }
}
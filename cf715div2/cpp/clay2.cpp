//no-unlocked
int n;
char s[1d5+10];
{
    REP(rd_int()){
        rd(n, s);
        bool ok = true;
        int cnt = n/3, cntm = 0, cntt = 0;
        rep(i,n) if(s[i] == 'M') {++ cntm;}
        if(cntm != cnt) ok = false;
        cntt = 0;
        if(s[0] != 'T' || s[n-1] != 'T') ok = false; 
        cntm = 0, cntt = 0;
        rep(i,n){
            if(s[i] == 'M') ++ cntm;
            if(s[i] == 'T') ++ cntt;
            if(cntm > cntt) ok = false;
        }
        cntm = 0, cntt = 0;
        rrep(i,n){
            if(s[i] == 'M') ++ cntm;
            if(s[i] == 'T') ++ cntt;
            if(cntm > cntt) ok = false;
        }
        if(ok) wt("YES");
        else wt("NO");
    }
}
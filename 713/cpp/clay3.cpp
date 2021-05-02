//no-unlocked
char s[2d5+10];
int minx, miny, maxx, maxy;
{
    REP(rd_int()){
        int a,b,n;
        rd(a,b,s@n);
        int m[] = {a,b};
        rep(i,n) if(s[i] == '?' && s[n-i-1] != '?') s[i] = s[n-i-1];
        rep(i,n) if('0' <= s[i] <= '9')--m[s[i]-'0'];
        bool okay = true;
        if(n % 2 == 0){
            rep(i,n) if(s[i] == '?' && s[n-i-1] == '?'){
                if(m[0] > 0){
                    s[i] = s[n-i-1] = '0';
                    m[0] -= 2;
                }else{
                    s[i] = s[n-i-1] = '1';
                    m[1] -= 2;
                }
            }
            if(m[0] != 0 || m[1] != 0){
                okay = false;
            }
        }else{
            okay = false;
            int md = 0;
            rep(i,n) if(i == n-i-1) md = i;
            rep(i,n) if(i != n-i-1 && s[i] == '?' && s[n-i-1] == '?'){
                if(m[0] > 1){
                    s[i] = s[n-i-1] = '0';
                    m[0] -= 2;
                }else if(m[1] > 1){
                    s[i] = s[n-i-1] = '1';
                    m[1] -= 2;
                }
            }
            if(m[0] == 0 && m[1] == 0){
                okay = true;
            }
            if(m[0] == 0 && m[1] == 1){
                okay = true;
                s[md] = '1';
            }else if(m[0] == 1 && m[1] == 0){
                okay = true;
                s[md] = '0';
            }
        }
        rep(i,n) if(s[i] != s[n-i-1]) okay = false;
        if(!okay) wt(-1); else wt(s);
    }
}
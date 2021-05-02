//no-unlocked
char rans[2d5+10];
{
    int @n, @k;
    string ans;
    rep(i,k){
        ans += ('a'+i);
        if(i == k-1) break;
        ans += ('a'+i);
        rep(j, i+1, k){
            ans += 'a'+j;
            if(j != k-1){
                ans += 'a'+i;
            }
        }
    }
    int m = ans.length();
    rep(i,n){
        rans[i] = ans[i%m];
    }
    wt(rans);
}


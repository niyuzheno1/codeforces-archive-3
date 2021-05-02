//no-unlocked
int n;
ll u[4d5],s[];
ll pre[], stp[], ed[], len[], ans[];

vector<int> b;
ll rang(int x, int y){
    if( x > y) return 0;
    if(x == 0) return pre[y];
    return pre[y] - pre[x-1];
} 
{
    REP(rd_int()){
        b.clear();
        rd(n, u(n), s(n));
        rep(i, n) s[i] = -s[i];
        sortA(n, u, s);
        rep(i, n) s[i] = -s[i];
        rep(i, n) pre[i] = (i==0? 0 : pre[i-1]) + s[i];
        rep(i, n+1) len[i] = 0, ed[i] = -1, stp[i] = int_inf;
        rep(i, n) stp[u[i]] <?= i, ed[u[i]] >?= i, ++len[u[i]];
        rep(i, n+1) if(stp[i] != int_inf) b.push_back(i);
        ll permsum = 0;
        rep(asz, n){
            int k = asz+1;
            auto tmpans = pre[n-1];
            int bsz = b.size();
            tmpans -= permsum;
            rep[b](i,bsz){
                int tmp = len[i] % k;
                tmpans -= rang(ed[i]-tmp+1, ed[i]);
            }
            rep(i, b.size()){
                int x = b[i];
                if(k > len[x]){
                    b.erase(b.begin() + i);
                    
                    permsum += rang(stp[x], ed[x]);
                    --i;
                }
            }
            ans[asz] = tmpans;
        }
        wt(ans(n));
    }
}
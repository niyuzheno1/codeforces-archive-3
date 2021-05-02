//no-unlocked
int n;
ll u[4d5],s[];
ll pre[], stp[], ans[];
int b[], bsz;
ll rang(int x, int y){
    if(x == 0) return pre[y];
    return pre[y] - pre[x-1];
} 
{
    REP(rd_int()){
        bsz = 0;
        rd(n, u(n), s(n));
        rep(i, n) s[i] = -s[i];
        sortA(n, u, s);
        rep(i, n) s[i] = -s[i];
        
        rep(i, n+1) stp[i] = int_inf;
        rep(i, n) stp[u[i]] <?= i;
        rep(i, n) pre[i] = (i==0? 0 : pre[i-1]) + s[i];
        rep(i, n+1) if(stp[i] != int_inf) b[bsz++] = i;
        rep(asz, n){
            int k = asz+1;
            ll tmpans = 0;
            rep[b](i,bsz){
                if(stp[i] == int_inf) continue;
                int xx = bsearch_max[int, md, 0, n+1]( stp[i] + k * md < n && u[stp[i] + k * md] == i );
                xx -= 2;
                xx = max(xx, 0);
                while(stp[i] + xx * k -1  < n && u[max(stp[i], stp[i] + k * xx -1) ] == i ) ++xx;
                --xx;
                if(xx == 0) continue;
                tmpans += rang(stp[i], max(stp[i], stp[i] + k * xx -1) );
            }
            ans[asz] = tmpans;
        }
        wt(ans(n));
    }
}
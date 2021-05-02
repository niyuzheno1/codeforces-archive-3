//no-unlocked
const int lim = 2d7+7;
ll dv[1d4], dsz = 0, num[lim];
ll lo[lim];
int p[lim];
int psz = 0;
{
    psz = Prime(lim,p);
    rep[p](i,psz) rep(j,i,lim,i) if(lo[j] == 0) lo[j] = i;
    rep(i,2, lim){
        int k = i;
        while(k % lo[i] == 0){
            k /= lo[i];
        }
        num[i] = num[k]+1;
    }
    REP(rd_int()){
        ll c,d,x;
        rd(c,d,x);
        ll ans = 0; 
        dsz = Divisor(x,dv);
        rep(i, dsz){
            ll y = dv[i];
            ll cm = x/y + d;
            if(cm % c) continue;
            ll m = cm/c; 
            ans += (1<<num[m]);
        }
        wt(ans);
    }
}
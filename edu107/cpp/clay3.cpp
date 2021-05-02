//no-unlocked
const int MN = 3d5+10;
int n, q, a[MN], t[MN], ans[MN];
int pos[100];
{
    rd(n,q, a(n), t(q));
    rep(i, 0, 53) pos[i] = -1;
    rep(i, 0, n){
        if(pos[a[i]] != -1) continue;
        pos[a[i]] = i;
    }
    rep(i,0,q){
        ans[i] = pos[t[i]]+1;
        if(pos[t[i]] == 0) continue;
        int cpos = pos[t[i]];
        pos[t[i]] = 0;
        rep(j,0,51){
            if(pos[j] == -1) continue;
            if(j == t[i]) continue;
            if(pos[j] >= cpos) continue; 
            ++pos[j];
        }
    }
    wt(ans(q));
}
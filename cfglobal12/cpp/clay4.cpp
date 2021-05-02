//no-unlocked
int Tcases;
const int MN = 3d5+20;
int n;
int a[MN];
int freq[MN];
char ans[MN];
char ans2[MN];
{
    rd(Tcases);
    rep(Tcases){
        rd(n, a(n));
        rep(i,n) --a[i];
        rep(i,n+2) freq[i] = 0;
        rep(i,n-1,n+2) ans[i] = 0;
        rep(i,n) ++freq[a[i]];
        int mv = min(freq(n));
        bool okay = freq[0] > 0;
        ans[0] = okay + '0';
        ans[n-1] = '0'+mv;
        int l = 0, r = n-1;
        rep(i,n-2){
            if(freq[i] > 1){
                okay = false;
            }
            if(freq[i+1] == 0){
                okay = false;
            }
            if(a[l] == i){
                ++l;
            }
            else if(a[r] == i){
                --r;
            }else{
                okay = false;
            }
            ans[i+1] = int(okay) + '0';
        }
        rep(i,n){
            ans2[i] = ans[n-i-1];
        }
        ans2[n] = 0;
        wt(ans2);
    }
}
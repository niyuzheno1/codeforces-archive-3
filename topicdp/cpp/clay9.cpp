//no-unlocked
int n,m,q;
int qu[5100][2];
int a[510][510];
int mr[510];
int le[510][510];

void update_row(int i){
        rep(j, m){
            if(j == 0){
                le[i][j] = (a[i][j] == 1);
            }else{
                le[i][j] = a[i][j] * (le[i][j-1]+1);
            }
        }
}

{
    rd(n,m, q, a(n,m), qu(q,2) );
    rep(i, n) {
        update_row(i);
        mr[i] = max(le[i](m));
    }
    rep(i, q){
        int x, y;
        (x,y) = (qu[i][0],qu[i][1]);
        --x, --y;
        a[x][y] ^= 1;
        update_row(x);
        mr[x] = max(le[x](m));
        int ans = 0;
        rep(j, n) ans >?= mr[j];
        wt(ans); 
    }

}
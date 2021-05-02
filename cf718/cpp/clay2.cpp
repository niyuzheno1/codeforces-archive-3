//no-unlocked
int b[110][110];
int L[110], R[110];
int ans[110][110];
int cnt[110];
#define mp make_pair
#define pq_type priority_queue<pair<int,int> >
#define X first
#define Y second
{
    REP(rd_int()){
        int @n, @m;
        rd(b(n,m));
        rep(i, n) R[i] = m-1, L[i] = 0;
        pq_type pq;
        rep(i, n) rep(j,m) pq.push(mp(-b[i][j],i));
        rep(i, n) cnt[i] = 0;
        rep(i, n) sortA(m, b[i]);
        while(!pq.empty()){
            auto y = pq.top(); pq.pop();
            auto x = mp(-y.X, y.Y);
            int i = x.Y;
            if(L[i] > R[i]) continue;
            ans[i][cnt[i]] = x.X; ++ cnt[i]; ++ L[i];
            rep(j, n) if(j != i) ans[j][cnt[j]]=b[j][R[j]], ++cnt[j], --R[j];
        }
        rep(i,n) wt(ans[i](m));
    }
}
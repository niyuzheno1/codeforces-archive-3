int N, M, X[4d3], Y[4d3], B[4d3];
int mn[200], mx[200];
int res[200], opt, tmp;
graph g;
{
    rd(N,M,(X--,Y--,B)(M));
    g.setEdge(N,M,X,Y);
    if(g.bipartite() == 0) wt("NO"), return 0;
    
    rep(i,M) (X[M+i],Y[M+i],B[M+i]) = (Y[i], X[i], -B[i]);
    M *= 2;

    opt = -int_inf;
    rep(r,N){
        rep(i,N) mn[i] = -int_inf, mx[i] = int_inf;
        mn[r] = mx[r] = 0;
        for(;;){
            int fg = 0;
            rep(i,M){
                if(mn[X[i]] == -int_inf) continue;
                if(B[i] == 0 && mn[Y[i]] < mn[X[i]]-1) mn[Y[i]] = mn[X[i]]-1,++fg;
                if(B[i] == 0 && mx[Y[i]] > mx[Y[i]]+1) mx[Y[i]] = mx[X[i]]+1,++fg;
                if(B[i] != 0 && mn[Y[i]] < mn[X[i]]+B[i]) mn[Y[i]] = mn[X[i]]+B[i], ++fg;
                if(B[i] != 0 && mx[Y[i]] > mx[X[i]]+B[i]) mx[Y[i]] = mx[X[i]]+B[i], ++fg;
            }
            rep(i,N) if(mx[i] < mn[i] || mx[i] < 0) break_break_continue;
            if(!fg) break;
        }
        if(opt < max(mx(N))){
            opt = max(mx(N));
            rep(i,N) res[i] = mx[i];
        }
    }
    if(opt == -int_inf) wt("NO"), return 0;
    wt("YES");
    wt(opt);
    wt(res(N));
}
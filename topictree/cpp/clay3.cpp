//no-unlocked
int n, P[1d5+10], A[], Q[], qsz;
ll S[], a[],cur;
graph g;
{
    rd(n, (P--)(n-1), S(n));
    iota(A, A+n-1, 1);
    g.setEdgeRootedTree(n, n-1, A, P);
    Q[qsz++] = 0;
    a[0] = S[0];
    int res = 1;
    while(cur < qsz){
        int x = Q[cur++];
        if(g.es[x] == 0){
            if(S[x] == -1){
                a[x] = 0;
            }
            continue;
        }
        rep[g.edge[x]](i, g.es[x]){
            Q[qsz++] = i;
        }
        if(S[x] == -1){
            ll mi = ll_inf;        
            rep[g.edge[x]](i, g.es[x]){
                mi <?= S[i]-S[P[x-1]];
            }
            a[x] = mi;
            if(mi < 0) res = 0;
            rep[g.edge[x]](i, g.es[x]){
                a[i] = S[i]-a[x]-S[P[x-1]];
                if(a[i] < 0) res = 0;
            }
        }
    }
    if(!res) wt(-1),exit(0);
    wt(sum(a(n)));
}
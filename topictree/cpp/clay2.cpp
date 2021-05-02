//no-unlocked
const int MN = 100010;
int A[MN],B[MN], Q[MN], cur , qsz, n;
double P[MN], L[MN]; 
graph g;
{
    rd(n, (A--,B--)(n-1));
    g.setEdgeRootedTree(n, n-1, A, B);
    Q[qsz++] = 0;
    L[0] = 0;
    P[0] = 1;
    while(cur < qsz){
        int x = Q[cur++];
        double es = g.es[x];
        es = 1/es;
        rep[g.edge[x]](i, g.es[x]){
            P[i] = P[x]*es;
            L[i] = L[x]+1;
            Q[qsz++] = i;
        }
    }
    double ans = 0;
    rep(i, n){
        if(g.es[i] != 0) continue;
        ans += P[i] * L[i];
    }
    wt(ans);
}
//no-unlocked
int A[1d5+10], P[1d5+10], C[1d5+10], n, sz;
int D[1d5+10], dsz; 
graph g;
{
    int root= 0;
    rd(n);
    rep(i,0, n){
        int @x, @y;
        if(x == -1) root = i;
        else P[sz] = x-1, A[sz] = i, ++sz;
        C[i] = y;
    }
    g.setEdgeRootedTree(n, n-1, A, P, root);
    rep(i,0,n){
        bool alldis = C[i];
        rep[g.edge[i]](j, g.es[i]){
            if(C[j] == 0) alldis = 0;
        }
        if(alldis){D[dsz++] = i;}
    }
    if(!dsz) wt(-1), exit(0);
    rep(i, dsz) ++D[i];
    wt(D(dsz));
}
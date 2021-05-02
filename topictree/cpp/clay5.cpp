//no-unlocked
const int MN = 2d5+10;
int  U[MN], V[MN], n, Q[], qsz;
ll a[MN],sz[], ss[], ab[], ad[], tt[];
graph g;
{
    rd(n, a(n), (U--,V--)(n-1));
    g.setEdgeRootedTree(n, n-1, U, V);
    Q[qsz++] = 0;
    rep[Q](x, qsz) rep[g.edge[x]](i, g.es[x]) Q[qsz++] = i;
    rrep[Q](x, qsz){
        sz[x] = a[x];
        rep[g.edge[x]](i, g.es[x]) sz[x] += sz[i];
        rep[g.edge[x]](i, g.es[x]) ss[x] += ss[i];
       
        ss[x] += sz[x]-a[x];
    }
    rep[Q](x, qsz){
        //int delta = sz[0] - sz[x];
         rep[g.edge[x]](i, g.es[x]){
            ab[i] = ss[x] - ss[i] - sz[i] + sz[0] - sz[i] + ab[x];
         }
    }
    rep(i, n) tt[i] = ss[i] + ab[i];    
    wt(max(tt(n)));
}
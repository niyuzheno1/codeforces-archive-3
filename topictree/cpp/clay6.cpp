//no-unlocked
const int MN = 2d5+10;
int  U[MN], V[MN], n, m, a[MN]; 
graph g;
HLD hld;
{
     rd(n, m, (U--,V--)(n-1));
     g.setEdgeRootedTree(n, n-1, U, V);
     hld.init(g);
     rep(i, m){
         int k;
         rd(k, (a--)(k));
         
         sort(a, a+k, [&] (const int & x, const int & y){ return hld.depth(x) > hld.depth(y); });
         bool good = true;
         rep(j, 1, k){
             int x = hld.lca(a[0], a[j]);
             if(abs(hld.depth(x)- hld.depth(a[j])) >= 2) good = false;
         }
         if(!good) wt("NO");
         else wt("YES");
     }
}
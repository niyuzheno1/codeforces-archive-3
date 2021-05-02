//no-unlocked
const int MN = 3d5+10;
int n,q, P[MN], A[], Q[], Que[], D[], qsz,cur, sz[], cen[], wor[];

graph g;
{
    rd(n, q, (P--)(n-1), (Que--)(q));
    iota(A, A+n-1, 1);
    D[MN-3] = MN+10;
    g.setEdgeRootedTree(n, n-1, A, P);
    Q[qsz++] = 0;

    while(cur < qsz){
        int x = Q[cur++];
        rep[g.edge[x]](i, g.es[x]){
            Q[qsz++] = i;
        }
    }
    rep(xxx, qsz){
        auto x = Q[xxx];
        if(x == 0) continue;
        D[x] = D[P[x-1]]+1;
    }
    rrep(xxxx, qsz){
        auto x = Q[xxxx];
        ++sz[x];
        rep[g.edge[x]](i, g.es[x]){
            sz[x] += sz[i];
        }
        bool goodroot = true;
        int msz = 0;
        rep[g.edge[x]](i, g.es[x]){
            msz >?= sz[i];
        }
        int req = sz[x]>>1;
        wor[x] = msz;
        if(msz <= req) cen[x] = x, continue;
        
        rep[g.edge[x]](i, g.es[x]){
            
            int c = cen[i];
            while(c != x){
                int above = sz[x] - sz[c];
                int below = wor[c];
                if(max(above, below) <= req) cen[x] = c, break;
                c = P[c-1];
            }
        }

     
    }
    rep(i, q){
        wt(1+cen[Que[i]]);
    }
}
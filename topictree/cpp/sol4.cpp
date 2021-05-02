#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
}
;
const int MN = 300000+10;
int n;
int q;
int P[MN];
int A[MN];
int Q[MN];
int Que[MN];
int D[MN];
int qsz;
int cur;
int sz[MN];
int cen[MN];
int wor[MN];
graph g;
int main(){
  int i, xxx, xxxx;
  wmem = memarr;
  rd(n);
  rd(q);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n-1);PiIOrLma++){
      rd(P[PiIOrLma]);P[PiIOrLma] += (-1);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(q);GIHf_YD2++){
      rd(Que[GIHf_YD2]);Que[GIHf_YD2] += (-1);
    }
  }
  iota(A, A+n-1, 1);
  D[MN-3] = MN+10;
  g.setEdgeRootedTree(n, n-1, A, P);
  Q[qsz++] = 0;
  while(cur < qsz){
    int C3F7XFP2;
    int x = Q[cur++];
    for(C3F7XFP2=(0);C3F7XFP2<(g.es[x]);C3F7XFP2++){
      auto&i = g.edge[x][C3F7XFP2];
      Q[qsz++] = i;
    }
  }
  for(xxx=(0);xxx<(qsz);xxx++){
    auto x = Q[xxx];
    if(x == 0){
      continue;
    }
    D[x] = D[P[x-1]]+1;
  }
  for(xxxx=(qsz)-1;xxxx>=(0);xxxx--){
    int o8AZ1iEn, oGwDY68s, vAq4Dd79;
    auto x = Q[xxxx];
    ++sz[x];
    for(o8AZ1iEn=(0);o8AZ1iEn<(g.es[x]);o8AZ1iEn++){
      auto&i = g.edge[x][o8AZ1iEn];
      sz[x] += sz[i];
    }
    bool goodroot = true;
    int msz = 0;
    for(vAq4Dd79=(0);vAq4Dd79<(g.es[x]);vAq4Dd79++){
      auto&i = g.edge[x][vAq4Dd79];
      chmax(msz, sz[i]);
    }
    int req = sz[x]>>1;
    wor[x] = msz;
    if(msz <= req){
      cen[x] = x;
      continue;
    }
    for(oGwDY68s=(0);oGwDY68s<(g.es[x]);oGwDY68s++){
      auto&i = g.edge[x][oGwDY68s];
      int c = cen[i];
      while(c != x){
        int above = sz[x] - sz[c];
        int below = wor[c];
        if(max_L(above, below)<= req){
          cen[x] = c;
          break;
        }
        c = P[c-1];
      }
    }
  }
  for(i=(0);i<(q);i++){
    wt_L(1+cen[Que[i]]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 3d5+10;
// int n,q, P[MN], A[], Q[], Que[], D[], qsz,cur, sz[], cen[], wor[];
// 
// graph g;
// {
//     rd(n, q, (P--)(n-1), (Que--)(q));
//     iota(A, A+n-1, 1);
//     D[MN-3] = MN+10;
//     g.setEdgeRootedTree(n, n-1, A, P);
//     Q[qsz++] = 0;
// 
//     while(cur < qsz){
//         int x = Q[cur++];
//         rep[g.edge[x]](i, g.es[x]){
//             Q[qsz++] = i;
//         }
//     }
//     rep(xxx, qsz){
//         auto x = Q[xxx];
//         if(x == 0) continue;
//         D[x] = D[P[x-1]]+1;
//     }
//     rrep(xxxx, qsz){
//         auto x = Q[xxxx];
//         ++sz[x];
//         rep[g.edge[x]](i, g.es[x]){
//             sz[x] += sz[i];
//         }
//         bool goodroot = true;
//         int msz = 0;
//         rep[g.edge[x]](i, g.es[x]){
//             msz >?= sz[i];
//         }
//         int req = sz[x]>>1;
//         wor[x] = msz;
//         if(msz <= req) cen[x] = x, continue;
//         
//         rep[g.edge[x]](i, g.es[x]){
//             
//             int c = cen[i];
//             while(c != x){
//                 int above = sz[x] - sz[c];
//                 int below = wor[c];
//                 if(max(above, below) <= req) cen[x] = c, break;
//                 c = P[c-1];
//             }
//         }
// 
//         // rep[g.edge[x]](i, g.es[x]){
//         //     if((sz[x] - sz[cen[i]]) * 2 <= sz[x] && D[cen[x]] > D[cen[i]] ) cen[x] = cen[i];
//         // }
//         // rep[g.edge[x]](i, g.es[x]){
//         //     if((sz[x] - sz[i]) * 2 <= sz[x] && D[cen[x]] > D[i] ) cen[x] = i;
//         // }
//     }
//     rep(i, q){
//         wt(1+cen[Que[i]]);
//     }
// }
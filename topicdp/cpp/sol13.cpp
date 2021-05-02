#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[41943040];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
  graph reverse(void **mem = &wmem){
    int i;
    int j;
    int k;
    graph g;
    g.N = N;
    walloc1d(&g.es, N, mem);
    walloc1d(&g.edge, N, mem);
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        g.es[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      walloc1d(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        g.edge[k][g.es[k]++] = i;
      }
    }
    return g;
  }
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int*deg;
    int*q;
    int qs = 0;
    int qe = 0;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setDirectEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      cost[A[i]][es[A[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
int n;
int m;
int T;
int F[5100][5100];
int dir[5100][5100];
int U[5100];
int V[5100];
int t[5100];
int res[5100];
int ans[5100];
int asz;
wgraph<int> g;
int main(){
  int i, xxx;
  wmem = memarr;
  rd(n);
  rd(m);
  rd(T);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(m);PiIOrLma++){
      rd(U[PiIOrLma]);U[PiIOrLma] += (-1);
      rd(V[PiIOrLma]);V[PiIOrLma] += (-1);
      rd(t[PiIOrLma]);
    }
  }
  g.setDirectEdge(n,m, U, V, t);
  int isgood = g.g.TopologicalSort(res);
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(n);j++){
      F[i][j] = 1073709056;
      dir[i][j] = -1;
    }
  }
  F[0][0] = 0;
  for(xxx=(0);xxx<(n);xxx++){
    int j;
    int i = res[xxx];
    for(j=(0);j<(xxx+1);j++){
      int wu;
      if(F[i][j] >= 1073709056){
        continue;
      }
      for(wu=(0);wu<(g.es[i]);wu++){
        int k = g.edge[i][wu];
        int c = g.cost[i][wu];
        chmin(F[k][j+1], F[i][j]+c);
        if(F[k][j+1] == F[i][j]+c){
          dir[k][j+1] = i;
        }
      }
    }
  }
  int ansx = 0;
  for(i=(n)-1;i>=(0);i--){
    if(F[n-1][i] <= T){
      ansx = (i+1);
      break;
    }
  }
  int x = n-1;
  int y = ansx-1;
  while(x != -1){
    int nx = dir[x][y];
    int ny = y-1;
    ans[asz] = x;
    ++asz;
    auto lo08wcHZ = ((nx));
    auto vAq4Dd79 = (( ny));
    x=lo08wcHZ;
    y=vAq4Dd79;
  }
  reverse(ans, ans+asz);
  for(i=(0);i<(asz);i++){
    ans[i]++;
  }
  wt_L(asz);
  wt_L('\n');
  {
    int oGwDY68s;
    if(asz==0){
      wt_L('\n');
    }
    else{
      for(oGwDY68s=(0);oGwDY68s<(asz-1);oGwDY68s++){
        wt_L(ans[oGwDY68s]);
        wt_L(' ');
      }
      wt_L(ans[oGwDY68s]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=40MB
// int n, m, T;
// int F[5100][5100];
// int dir[5100][5100];
// int U[5100], V[5100], t[5100];
// int res[], ans[], asz;
// wgraph<int> g;
// {
//     rd(n, m, T, (U--,V--,t)(m));
//     g.setDirectEdge(n,m, U, V, t);
//     int isgood = g.g.TopologicalSort(res);
//     rep(i, n) rep(j, n) F[i][j] = int_inf, dir[i][j] = -1;
//     
//     F[0][0] = 0;
//     
//     rep(xxx, n){
//         int i = res[xxx];
//         rep(j, xxx+1){
//             if(F[i][j] >= int_inf) continue;
//             rep(wu, g.es[i]){
//                 int k = g.edge[i][wu];
//                 int c = g.cost[i][wu];
//                 F[k][j+1] <?= F[i][j]+c;
//                 if(F[k][j+1] == F[i][j]+c) dir[k][j+1] = i;
//             }
//         }
//     }
//     int ansx = 0;
//     rrep(i, n){
//         if(F[n-1][i] <= T){
//             ansx = (i+1);
//             break;
//         }
//     }
//     int x = n-1, y = ansx-1;
//     while(x != -1){
//         int nx = dir[x][y];
//         int ny = y-1;
//         ans[asz] = x;
//         ++asz;
//         (x, y) = (nx, ny);
//     }
//     reverse(ans, ans+asz);
//     rep(i, asz) ans[i]++;
//     wt(asz);
//     wt(ans(asz));
// }
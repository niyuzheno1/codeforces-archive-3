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
inline void rd(long long &x){
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
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
const int MN = 200000+10;
int U[MN];
int V[MN];
int n;
int Q[MN];
int qsz;
long long a[MN];
long long sz[MN];
long long ss[MN];
long long ab[MN];
long long ad[MN];
long long tt[MN];
graph g;
int main(){
  int Yd8JT4OW, i, oGwDY68s, rbGYC8dh;
  wmem = memarr;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n-1);GIHf_YD2++){
      rd(U[GIHf_YD2]);U[GIHf_YD2] += (-1);
      rd(V[GIHf_YD2]);V[GIHf_YD2] += (-1);
    }
  }
  g.setEdgeRootedTree(n, n-1, U, V);
  Q[qsz++] = 0;
  for(rbGYC8dh=(0);rbGYC8dh<(qsz);rbGYC8dh++){
    int EZ0PmQmu;
    auto&x = Q[rbGYC8dh];
    for(EZ0PmQmu=(0);EZ0PmQmu<(g.es[x]);EZ0PmQmu++){
      auto&i = g.edge[x][EZ0PmQmu];
      Q[qsz++] = i;
    }
  }
  for(Yd8JT4OW=(qsz)-1;Yd8JT4OW>=(0);Yd8JT4OW--){
    int o8AZ1iEn, vAq4Dd79;
    auto&x = Q[Yd8JT4OW];
    sz[x] = a[x];
    for(o8AZ1iEn=(0);o8AZ1iEn<(g.es[x]);o8AZ1iEn++){
      auto&i = g.edge[x][o8AZ1iEn];
      sz[x] += sz[i];
    }
    for(vAq4Dd79=(0);vAq4Dd79<(g.es[x]);vAq4Dd79++){
      auto&i = g.edge[x][vAq4Dd79];
      ss[x] += ss[i];
    }
    ss[x] += sz[x]-a[x];
  }
  for(oGwDY68s=(0);oGwDY68s<(qsz);oGwDY68s++){
    int a3PBjchb;
    auto&x = Q[oGwDY68s];
    for(a3PBjchb=(0);a3PBjchb<(g.es[x]);a3PBjchb++){
      auto&i = g.edge[x][a3PBjchb];
      ab[i] = ss[x] - ss[i] - sz[i] + sz[0] - sz[i] + ab[x];
    }
  }
  for(i=(0);i<(n);i++){
    tt[i] = ss[i] + ab[i];
  }
  int LiLe88qh;
  cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type gYUVurHt;
  if(n==0){
    gYUVurHt = 0;
  }
  else{
    gYUVurHt = tt[0];
    for(LiLe88qh=(1);LiLe88qh<(n);LiLe88qh++){
      gYUVurHt = max_L(gYUVurHt, tt[LiLe88qh]);
    }
  }
  wt_L(gYUVurHt);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 2d5+10;
// int  U[MN], V[MN], n, Q[], qsz;
// ll a[MN],sz[], ss[], ab[], ad[], tt[];
// graph g;
// {
//     rd(n, a(n), (U--,V--)(n-1));
//     g.setEdgeRootedTree(n, n-1, U, V);
//     Q[qsz++] = 0;
//     rep[Q](x, qsz) rep[g.edge[x]](i, g.es[x]) Q[qsz++] = i;
//     rrep[Q](x, qsz){
//         sz[x] = a[x];
//         rep[g.edge[x]](i, g.es[x]) sz[x] += sz[i];
//         rep[g.edge[x]](i, g.es[x]) ss[x] += ss[i];
//        
//         ss[x] += sz[x]-a[x];
//     }
//     rep[Q](x, qsz){
//         //int delta = sz[0] - sz[x];
//          rep[g.edge[x]](i, g.es[x]){
//             ab[i] = ss[x] - ss[i] - sz[i] + sz[0] - sz[i] + ab[x];
//          }
//     }
//     rep(i, n) tt[i] = ss[i] + ab[i];    
//     wt(max(tt(n)));
// }
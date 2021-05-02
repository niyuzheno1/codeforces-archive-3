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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int A[200000+10];
int B[200000+10];
int asz;
long long W[200000+10];
long long ss[200000+10];
long long a[200000+10];
wgraph<long long> g;
void dfs(int x){
  int i;
  if(x == n-1){
    return;
  }
  for(i=(0);i<(g.es[x]);i++){
    int y = g.edge[x][i];
    a[asz] = g.cost[x][i];
    ++asz;
    dfs(y);
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(m);
  {
    int FJNsjZ7B;
    for(FJNsjZ7B=(0);FJNsjZ7B<(m);FJNsjZ7B++){
      rd(A[FJNsjZ7B]);A[FJNsjZ7B] += (-1);
      rd(B[FJNsjZ7B]);B[FJNsjZ7B] += (-1);
      rd(W[FJNsjZ7B]);
    }
  }
  g.setDirectEdge(n,m, A, B, W);
  long long plen = m/g.es[0];
  int Z8lEHcvz;
  long long rbGYC8dh;
  if(m==0){
    rbGYC8dh = 0;
  }
  else{
    rbGYC8dh = W[0];
    for(Z8lEHcvz=(1);Z8lEHcvz<(m);Z8lEHcvz++){
      rbGYC8dh += W[Z8lEHcvz];
    }
  }
  long long ws = rbGYC8dh;
  long long flow = ws/plen;
  for(i=(0);i<(g.es[0]);i++){
    int j;
    asz = 0;
    a[asz] = g.cost[0][i];
    ++asz;
    dfs(g.edge[0][i]);
    sortA_L(asz, a);
    for(j=(0);j<(asz);j++){
      ss[j] += a[j];
    }
  }
  long long ans = 0;
  for(i=(0);i<(asz);i++){
    ans +=max_L(0, flow-ss[i]);
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n,m;
// int A[2d5+10], B[], asz;
// ll W[], ss[], a[];
// wgraph<ll> g;
// void dfs(int x){
//     if(x == n-1) return;
//     rep(i, g.es[x]){
//         int y = g.edge[x][i];
//         a[asz] = g.cost[x][i];
//         ++asz;
//         dfs(y);
//     }
// }
// {
//     rd(n,m, (A--,B--,W)(m));
//     g.setDirectEdge(n,m, A, B, W);
//     ll plen = m/g.es[0];
//     ll ws = sum(W(m));
//     ll flow = ws/plen;
//     rep(i, g.es[0]){
//         asz = 0;
//         a[asz] = g.cost[0][i];
//         ++asz;
//         dfs(g.edge[0][i]);
//         sortA(asz, a);
//         rep(j, asz) ss[j] += a[j];
//     }
//     ll ans = 0;
//     rep(i, asz){
//         ans += max(0, flow-ss[i]);
//     }
//     wt(ans);
// }
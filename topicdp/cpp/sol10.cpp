#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
void*wmem;
char memarr[96000000];
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
struct modint{
  static unsigned md;
  unsigned val;
  modint(){
    val=0;
  }
  modint(int a){
    val = ord(a);
  }
  modint(unsigned a){
    val = ord(a);
  }
  modint(long long a){
    val = ord(a);
  }
  modint(unsigned long long a){
    val = ord(a);
  }
  void setmod(unsigned m){
    md = m;
  }
  unsigned ord(unsigned a){
    return a%md;
  }
  unsigned ord(int a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned ord(unsigned long long a){
    return a%md;
  }
  unsigned ord(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return a;
  }
  unsigned get(){
    return val;
  }
  inline modint &operator++(){
    val++;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  inline modint &operator--(){
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline modint operator++(int a){
    modint res(*this);
    val++;
    if(val >= md){
      val -= md;
    }
    return res;
  }
  inline modint operator--(int a){
    modint res(*this);
    if(val == 0){
      val = md - 1;
    }
    else{
      --val;
    }
    return res;
  }
  modint &operator+=(modint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  modint &operator-=(modint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  modint &operator*=(modint a){
    val = ((unsigned long long)val*a.val)%md;
    return *this;
  }
  modint &operator/=(modint a){
    return *this *= a.inverse();
  }
  modint operator+(modint a){
    return modint(*this)+=a;
  }
  modint operator-(modint a){
    return modint(*this)-=a;
  }
  modint operator*(modint a){
    return modint(*this)*=a;
  }
  modint operator/(modint a){
    return modint(*this)/=a;
  }
  modint operator+(int a){
    return modint(*this)+=modint(a);
  }
  modint operator-(int a){
    return modint(*this)-=modint(a);
  }
  modint operator*(int a){
    return modint(*this)*=modint(a);
  }
  modint operator/(int a){
    return modint(*this)/=modint(a);
  }
  modint operator+(long long a){
    return modint(*this)+=modint(a);
  }
  modint operator-(long long a){
    return modint(*this)-=modint(a);
  }
  modint operator*(long long a){
    return modint(*this)*=modint(a);
  }
  modint operator/(long long a){
    return modint(*this)/=modint(a);
  }
  modint operator-(void){
    modint res;
    if(val){
      res.val=md-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  operator bool(void){
    return val!=0;
  }
  operator int(void){
    return get();
  }
  operator long long(void){
    return get();
  }
  modint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += md;
    }
    res.val = u;
    return res;
  }
  modint pw(unsigned long long b){
    modint a(*this);
    modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  bool operator==(int a){
    return ord(a)==val;
  }
  bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
unsigned modint::md;
modint operator+(int a, modint b){
  return modint(a)+=b;
}
modint operator-(int a, modint b){
  return modint(a)-=b;
}
modint operator*(int a, modint b){
  return modint(a)*=b;
}
modint operator/(int a, modint b){
  return modint(a)/=b;
}
modint operator+(long long a, modint b){
  return modint(a)+=b;
}
modint operator-(long long a, modint b){
  return modint(a)-=b;
}
modint operator*(long long a, modint b){
  return modint(a)*=b;
}
modint operator/(long long a, modint b){
  return modint(a)/=b;
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
inline void wt_L(modint x){
  int i;
  i = (int)x;
  wt_L(i);
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
const int MN = 100000+10;
const int MX = 20;
modint f[MN][MX][3];
int vis[MN][MX][3];
int n;
int m;
int U[MN];
int V[MN];
int K;
int X;
int par[MN];
graph g;
void dfs(int x, int y){
  int PiIOrLma;
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    auto&z = g.edge[x][PiIOrLma];
    if(z == x){
      continue;
    }
    par[z] = x;
    dfs(z, x);
  }
}
int poss[3][3];
modint Idic(int v){
  if(v == 0){
    return K-1;
  }
  if(v == 1){
    return 1;
  }
  return m-K;
}
modint dfs2(int x, int y, int z){
  int NN9wFlop, i;
  if(vis[x][y][z]){
    return f[x][y][z];
  }
  vis[x][y][z] = 1;
  int dp[x][X+10];
  return f[x][y][z];
}
int main(){
  int i;
  wmem = memarr;
  {
    modint x;
    x.setmod(MD);
  }
  poss[0][0] = 1;
  poss[0][1] = 1;
  poss[0][2] = 1;
  poss[1][0] = 1;
  poss[2][0] = 1;
  poss[2][2] = 1;
  rd(n);
  rd(m);
  {
    int Btiq50RC;
    for(Btiq50RC=(0);Btiq50RC<(n-1);Btiq50RC++){
      rd(U[Btiq50RC]);U[Btiq50RC] += (-1);
      rd(V[Btiq50RC]);V[Btiq50RC] += (-1);
    }
  }
  rd(K);
  rd(X);
  g.setEdgeRootedTree(n, n-1, U, V);
  dfs(0, -1);
  modint ans = 0;
  for(i=(0);i<(X+1);i++){
    auto r1 = dfs2(0, i, 0);
    auto r2 = dfs2(0, i, 1);
    auto r3 = dfs2(0, i, 2);
    ans += r1 + r2 + r3;
  }
  dfs2(0, 0, 2);
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5+10;
// const int MX = 20;
// modint f[MN][MX][3];
// int vis[MN][MX][3], n, m, U[MN], V[MN], K, X, par[MN];
// 
// graph g;
// 
// void dfs(int x, int y){
//     rep[g.edge[x]](z, g.es[x]){
//         if(z == x) continue;
//         par[z] = x;
//         dfs(z, x);
//     }
// }
// 
// int poss[3][3];
// 
// modint Idic(int v){
//     if(v == 0) return K-1;
//     if(v == 1) return 1;
//     return m-K;
// }
// 
// modint dfs2(int x, int y, int z){
//     if(vis[x][y][z]) return f[x][y][z];
//     vis[x][y][z] = 1;
//     modint dp[g.es[x]+2][X+10];
//     rep(i, g.es[x]+2) rep(j, 0, y+10) dp[i][j] = 0;
//     dp[0][0] = 1;
//     int idx = 1;
//     rep[g.edge[x]](v, g.es[x]){
//         if(v == par[x]) continue;   
//         rep(j, 0, 3){
//             if(!poss[z][j]) continue;
//             rep(k, y+1){
//                 modint mm = dfs2(v, k, j);
//                 rrep(w,k, y+1){
//                     dp[idx][w] += dp[idx-1][w-k] * mm;
//                 }
//             }
//         }
//         ++idx;
//     } 
//     --idx;
//     if(z != 1)
//         f[x][y][z] = dp[idx][y] * Idic(z);   
//     else    
//         f[x][y][z] = (y-1 >= 0 ? 1 : 0) * dp[idx][y-1];
//     return f[x][y][z];
// }
// 
// 
// {
//     poss[0][0] = 1;
//     poss[0][1] = 1;
//     poss[0][2] = 1;
//     poss[1][0] = 1;
//     poss[2][0] = 1;
//     poss[2][2] = 1;
//     rd(n, m, (U--,V--)(n-1), K, X);
//     g.setEdgeRootedTree(n, n-1, U, V);
//     dfs(0, -1);
//     modint ans = 0;
//     rep(i, X+1){
//         auto r1 = dfs2(0, i, 0);
//         auto r2 = dfs2(0, i, 1);
//         auto r3 = dfs2(0, i, 2);
//         ans += r1 + r2 + r3;
//     }
//     dfs2(0, 0, 2);
//     wt(ans );
// }
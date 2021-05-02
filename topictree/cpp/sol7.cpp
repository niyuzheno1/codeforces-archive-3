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
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
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
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
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
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  void getDist(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  int getDist(int a, int b, void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    int*d;
    if(a==b){
      return 0;
    }
    walloc1d(&d, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      d[i] = -1;
    }
    d[a] = 0;
    s = 0;
    z = 1;
    q[0] = a;
    while(z){
      i = q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(d[k] >= 0){
          continue;
        }
        d[k] = d[i] + 1;
        if(k==b){
          return d[k];
        }
        q[s+z++] = k;
      }
    }
    return -1;
  }
  int TreeDiameter(int &a, int &b, void *mem = wmem){
    int i;
    int mx;
    int*d;
    walloc1d(&d, N, &mem);
    getDist(0, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        a = i;
      }
    }
    getDist(a, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        b = i;
      }
    }
    return mx;
  }
  int TreeDiameter(void *mem = wmem){
    int a;
    int b;
    return TreeDiameter(a, b, mem);
  }
}
;
const int MN = 200000+10;
int n;
int a[MN];
int U[MN];
int V[MN];
int esz;
int NU[MN];
int NV[MN];
int res[MN];
vector<int> s[MN];
int allowed[MN];
int vis[MN];
int tsz;
int lt[MN];
graph g;
graph t;
int idx = 0;
void dfs(int x, int p, int pm){
  int PiIOrLma;
  if(allowed[x] != pm){
    return;
  }
  if(vis[x] == pm){
    return;
  }
  int cid = idx++;
  vis[x] = pm;
  if(p != -1){
    NU[esz] = p;
    NV[esz] = cid;
    ++esz;
  }
  for(PiIOrLma=(0);PiIOrLma<(g.es[x]);PiIOrLma++){
    auto&i = g.edge[x][PiIOrLma];
    dfs(i, cid, pm);
  }
}
int main(){
  int i, o8AZ1iEn;
  wmem = memarr;
  rd(n);
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      rd(a[GIHf_YD2]);
    }
  }
  {
    int rbGYC8dh;
    for(rbGYC8dh=(0);rbGYC8dh<(n-1);rbGYC8dh++){
      rd(U[rbGYC8dh]);U[rbGYC8dh] += (-1);
      rd(V[rbGYC8dh]);V[rbGYC8dh] += (-1);
    }
  }
  g.setEdge(n, n-1, U, V);
  for(i=(0);i<(n);i++){
    s[a[i]].push_back(i);
  }
  int VL854U43;
  int Yd8JT4OW;
  if(n==0){
    Yd8JT4OW = 0;
  }
  else{
    Yd8JT4OW = a[0];
    for(VL854U43=(1);VL854U43<(n);VL854U43++){
      Yd8JT4OW = max_L(Yd8JT4OW, a[VL854U43]);
    }
  }
  int mx = Yd8JT4OW+1;
  int psz =Prime_L(MN-5, res);
  int ans = -1;
  for(o8AZ1iEn=(0);o8AZ1iEn<(psz);o8AZ1iEn++){
    int WpmOCj1U;
    auto&pr = res[o8AZ1iEn];
    tsz = 0;
    for(i=(pr);i<(mx);i+=(pr)){
      for(auto & x : s[i]){
        allowed[x] = pr;
        lt[tsz++] = x;
      }
    }
    for(WpmOCj1U=(0);WpmOCj1U<(tsz);WpmOCj1U++){
      auto&i = lt[WpmOCj1U];
      esz = 0;
      if(vis[i] != pr){
        idx = 0;
        dfs(i, -1, pr);
        t.setEdge(esz+1, esz, NU, NV);
        chmax(ans, t.TreeDiameter());
      }
    }
  }
  wt_L(ans+1);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 2d5+10;
// int n, a[MN], U[MN], V[MN], esz, NU[], NV[], res[];
// vector<int> s[MN];
// int allowed[MN], vis[MN], tsz, lt[];
// graph g, t;
// 
// int idx = 0;
// void dfs(int x, int p, int pm){
//     if(allowed[x] != pm) return;
//     if(vis[x] == pm) return;
//     int cid = idx++;
//     vis[x] = pm;
//     if(p != -1){NU[esz] = p; NV[esz] = cid; ++esz;}
//     rep[g.edge[x]](i, g.es[x]) dfs(i, cid, pm);
// }
// {
//     rd(n, a(n), (U--,V--)(n-1));
//     g.setEdge(n, n-1, U, V);
//     rep(i, n) s[a[i]].push_back(i);
//     int mx = max(a(n))+1;
//     int psz = Prime(MN-5, res);
//     int ans = -1;
//     rep[res](pr,psz){
//         tsz = 0;
//         rep(i, pr, mx, pr){
//             for(auto & x : s[i]) {
//                 allowed[x] = pr;
//                 lt[tsz++] = x;
//             }
//         }
//         rep[lt](i, tsz){
//             esz = 0;
//             if(vis[i] != pr) {
//                 idx = 0;
//                 dfs(i, -1, pr);
//                 t.setEdge(esz+1, esz, NU, NV);
//                 ans >?= t.TreeDiameter();
//             }
//         }
//     }
//     wt(ans+1);
// }
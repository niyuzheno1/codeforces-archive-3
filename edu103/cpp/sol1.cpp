#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class EnterExit> class sqrt_decomp{
  public:
  EnterExit* a;
  int* L;
  int* R;
  int* E;
  int* IDX;
  int qsz;
  int lmt;
  int blocksz;
  int _init;
  int cur;
  int solid_state;
  int _update;
  void init(bool enable_wmem, int isupdated){
    int i;
    _update = 0;
    _init = 1;
    if(isupdated){
      _update = 1;
    }
    if(enable_wmem){
      walloc1d(&L, qsz, &wmem);
      walloc1d(&R, qsz, &wmem);
      if(isupdated){
        walloc1d(&E, qsz, &wmem);
      }
      walloc1d(&IDX, qsz, &wmem);
      this->solid_state = 1;
    }
    else{
      L = new int[qsz];
      R = new int[qsz];
      if(isupdated){
        E = new int[qsz];
      }
      IDX = new int[qsz];
      this->solid_state = 0;
    }
    for(i=(0);i<(qsz);i++){
      L[i] = R[i]   = 0;
    }
    if(isupdated){
      E[i] = 0;
    }
  }
  sqrt_decomp(){
    a = new EnterExit();
    this-> _init = 0;
  }
  void sinit(int qsz, int blocksz, int allow_update){
    if(this->_init){
      return;
    }
    this->cur = 0;
    this->qsz = qsz;
    this->blocksz = blocksz;
    this->lmt = 0;
    this->solid_state = 0;
    init(true, allow_update);
  }
  void hinit(int qsz, int blocksz, int allow_update){
    if(this->_init){
      return;
    }
    this-> _init = 0;
    this->cur = 0;
    this->qsz = qsz;
    this->blocksz = blocksz;
    this->lmt = 0;
    this->solid_state = 0;
    init(false, allow_update);
  }
  void clear(){
    if(!this->solid_state && this->_init){
      this->_init = 0;
      delete [] L;
      delete [] R;
      if(_update){
        delete [] E;
      }
      delete [] IDX;
      L = R = E = IDX = NULL;
    }
  }
  ~sqrt_decomp(){
    delete a;
    clear();
  }
  void transfer(int sz, int * L, int * R, int * E){
    int i;
    for(i=(0);i<(sz);i++){
      this->IDX[i] = i;
    }
    if(E != NULL){
      _update = 1;
    }
    if(!_update){
      sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                return R[lhs] < R[rhs];
            });
    }
    else{
      sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                if(R[lhs]/blocksz != R[rhs]/blocksz) return R[lhs] < R[rhs];
                return E[lhs] < E[rhs];
            });
    }
    for(i=(0);i<(sz);i++){
      this->L[i] = L[this->IDX[i]];
      this->R[i] = R[this->IDX[i]];
    }
    if(_update){
      for(i=(0);i<(sz);i++){
        this->E[i] = E[this->IDX[i]];
      }
    }
    this->cur = 0;
    this->lmt = sz;
  }
  int next(int & l, int & r, int & cl, int & cr){
    if(this->cur >= this->lmt){
      return -1;
    }
    int i = this->cur;
    while(l < L[i]){
      a->change(l, -1);
      ++l;
    }
    while(l > L[i]){
      a->change(l-1, 1);
      --l;
    }
    while(r < R[i]){
      a->change(r+1,1);
      ++r;
    }
    while(r > R[i]){
      a->change(r,-1);
      --r;
    }
    auto P1jAuWt8 = ((L[i]));
    auto cYAGnodu = ((R[i]));
    cl=P1jAuWt8;
    cr=cYAGnodu;
    ++this->cur;
    return IDX[i];
  }
  int next(int & l, int & r, int cl, int & cr, int & t){
    if(this->cur >= this->lmt){
      return -1;
    }
    int i = this->cur;
    while(t < E[i]){
      a->modify(t+1,1, l, r);
      ++t;
    }
    while(t > E[i]){
      a->modify(t,-1, l, r);
      --t;
    }
    return next(l,r,cl,cr);
  }
}
;
const int MN = 100000+10;
int n;
int m;
int a[MN];
int L[MN];
int R[MN];
int E[MN];
int osz;
int K[MN];
int P[MN];
int V[MN];
int C[MN];
int csz;
int cnt[MN];
int g[MN];
int ans[MN];
int lb[5*MN];
int rb[5*MN];
int b[MN];
int xord[5*MN];
int* ord = xord + MN;
int* slb = lb+3;
int* srb = rb+3;
class getmindist{
  public:
  int mx;
  getmindist(){
    mx = 0;
  }
  int& ct(int x){
  }
  int& glb(int x){
    return lb[x+3];
  }
  int& grb(int x){
    return rb[x+3];
  }
  int len(int x){
    return grb(x)-glb(x)+1;
  }
  int plen(int x){
    if(len(x) > 0){
      return grb(x)-glb(x)+1;
    }
    return 0;
  }
  void addval(int x){
    int c = g[x];
    ++ord[glb(c)];
    grb(c+1) = glb(c);
    if(glb(c+1) == n){
      glb(c+1) = glb(c);
    }
    if(glb(c) == grb(c)){
      glb(c) = n-1;
    }
    ++glb(c);
    ++g[x];
  }
  void delval(int x){
    int c = g[x];
    --ord[grb(c)];
    if(glb(c-1) == n){
      grb(c-1) = grb(c);
    }
    glb(c-1) = grb(c);
    if(glb(c) == grb(c)){
      glb(c) = n;
    }
    --grb(c);
    --g[x];
  }
  void change(int pos, int x){
    if(x == 1){
      x = a[pos];
      addval(x);
    }
    else{
      x = a[pos];
      delval(x);
    }
  }
  void modify(int pos, int x, int l, int r){
    if(x == 1){
      x = P[pos];
      if(l <= x  &&  x <= r){
        delval(a[x]);
      }
      a[x] = C[pos];
      if(l <= x  &&  x <= r){
        addval(a[x]);
      }
    }
    else{
      x = P[pos];
      if(l <= x  &&  x <= r){
        delval(a[x]);
      }
      a[x] = V[pos];
      if(l <= x  &&  x <= r){
        addval(a[x]);
      }
    }
  }
  int computeAns(int l, int r, int k){
    int res = n;
    int i = 0;
    int j = 0;
    int su = 0;
    while(i < n && ord[i] > 0){
      while(j < n && ord[j] > 0 && su < k){
        su += len(ord[j]);
        j = grb(ord[j])+1;
      }
      if(su >= k){
        chmin(res, ord[i] - ord[j-1]);
      }
      su -= len(ord[i]);
      i = grb(ord[i]) + 1;
    }
    if(res == n){
      return -1;
    }
    return res;
  }
  void reset(){
    int i;
    glb(0) = 0;
    grb(0) = n-1;
    for(i=(1);i<(n);i++){
      glb(i) =  n;
      grb(i) = 0;
    }
  }
}
;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(m);
  {
    int rbGYC8dh;
    for(rbGYC8dh=(0);rbGYC8dh<(n);rbGYC8dh++){
      rd(a[rbGYC8dh]);
    }
  }
  for(i=(0);i<(m);i++){
    int type;
    rd(type);
    if(type == 1){
      int l;
      rd(l);
      int r;
      rd(r);
      int k;
      rd(k);
      auto VL854U43 = ((l-1));
      auto Yd8JT4OW = ((r-1));
      auto GN2MVvSr = ((k));
      L[osz]=VL854U43;
      R[osz]=Yd8JT4OW;
      K[osz]=GN2MVvSr;
      E[osz] = csz;
      ++osz;
    }
    else{
      int p;
      rd(p);
      int x;
      rd(x);
      ++csz;
      auto OUHHcm5g = ((p-1));
      auto o8AZ1iEn = ((x));
      P[csz]=OUHHcm5g;
      C[csz]=o8AZ1iEn;
    }
  }
  for(i=(1);i<(csz+1);i++){
    V[i] = a[P[i]];
    a[P[i]] = C[i];
  }
  int l = 0;
  int r = -1;
  int cl = 0;
  int cr = 0;
  int t = csz;
  int px = 0;
  sqrt_decomp<getmindist> sqde;
  sqde.sinit(osz+10, (int)pow(n,2.0/3.0), 1);
  sqde.transfer(osz, L, R, E);
  sqde.a->reset();
  while( (px = sqde.next(l,r,cl,cr, t) ) != -1){
    int ret = sqde.a->computeAns(L[px],R[px], K[px]);
    ans[px] = ret;
  }
  for(i=(0);i<(osz);i++){
    wt_L(ans[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5+10;
// int n,m, a[MN], L[MN], R[MN], E[MN], osz, K[MN];
// int P[MN], V[MN], C[MN], csz, cnt[MN], g[MN], ans[MN];
// int lb[5*MN], rb[5*MN];
// int b[MN], xord[5*MN];
// int * ord = xord + MN;
// int * slb = lb+3;
// int * srb = rb+3;
// class getmindist{
// public:   
//     int mx;
//     getmindist(){
//         mx = 0;
//     }
//     int& ct(int x){
//     }
//     int& glb(int x){
//         return lb[x+3];
//     }
//     int& grb(int x){
//         return rb[x+3];
//     }
//     int len(int x){
//         return grb(x)-glb(x)+1;
//     }
//     int plen(int x)
//     {
//         if(len(x) > 0)
//          return grb(x)-glb(x)+1;
//         return 0;
//     }
//     void addval(int x){
//         int c = g[x];
//         ++ord[glb(c)];
//         grb(c+1) = glb(c);
//         if(glb(c+1) == n) glb(c+1) = glb(c);
//         if(glb(c) == grb(c)) glb(c) = n-1;
//         ++glb(c);
//         ++g[x];
//     }   
//     void delval(int x){
//         int c = g[x];
//         --ord[grb(c)];
//         if(glb(c-1) == n) grb(c-1) = grb(c);
//         glb(c-1) = grb(c);
//         if(glb(c) == grb(c)) glb(c) = n;
//         --grb(c);
//         --g[x];
//     }
//     void change(int pos, int x){
//         if(x == 1){
//             x = a[pos];
//             addval(x);
//         }else{
//             x = a[pos];
//             delval(x);
//         }
//     }
//     void modify(int pos, int x, int l, int r){
//         if(x == 1){
//             x = P[pos];
//             if(l <= x <= r) delval(a[x]);
//             a[x] = C[pos];
//             if(l <= x <= r) addval(a[x]);
//         }else{
//             x = P[pos];
//             if(l <= x <= r) delval(a[x]);
//             a[x] = V[pos];
//             if(l <= x <= r) addval(a[x]);
//         }
//     }
//     int computeAns(int l, int r, int k){
//         int res = n;
//         int i = 0, j = 0, su = 0;
//         while(i < n && ord[i] > 0){
//             while(j < n && ord[j] > 0 && su < k){
//                 su += len(ord[j]);
//                 j = grb(ord[j])+1;
//             }
//             if(su >= k) res <?= ord[i] - ord[j-1];
//             su -= len(ord[i]);
//             i = grb(ord[i]) + 1;
//         }
//         if(res == n) return -1;
//         return res;
//     }
//     void reset(){
//         glb(0) = 0;
//         grb(0) = n-1;
//         rep(i, 1, n) glb(i) =  n, grb(i) = 0;
//     }
// };
// {
//     rd(n,m,a(n));
//     rep(i, m){
//         int @type;
//         if(type == 1){
//             int @l, @r, @k;
//             (L[osz], R[osz], K[osz]) = (l-1,r-1,k);
//             E[osz] = csz;
//             ++osz;
//         }else{
//             int @p, @x;
//             ++csz;
//             (P[csz], C[csz]) = (p-1,x);
//         }
//     }
//     rep(i, 1, csz+1){
//         V[i] = a[P[i]];
//         a[P[i]] = C[i];
//     }
//     int l = 0, r = -1, cl = 0, cr = 0, t = csz, px = 0;   
//     sqrt_decomp<getmindist> sqde;
//     sqde.sinit(osz+10, (int)pow(n,2.0/3.0), 1);
//     sqde.transfer(osz, L, R, E);
//     sqde.a->reset();
//     while( (px = sqde.next(l,r,cl,cr, t) ) != -1){
//         int ret = sqde.a->computeAns(L[px],R[px], K[px]);
//         ans[px] = ret;
//     }
//     rep(i, osz) wt(ans[i]);
// }
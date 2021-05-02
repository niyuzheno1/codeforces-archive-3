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
char memarr[62914560];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
int ps[100000];
int psz;
int n;
int q;
int a[100000+10];
int L[100000+10];
int R[100000+10];
int ans[100000+10];
int pre[100000+10];
int getrange(int x, int y){
  if(x == 0){
    return pre[y];
  }
  return  pre[y]-pre[x-1];
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
      L[i] = R[i] =  0;
    }
    if(isupdated){
      for(i=(0);i<(qsz);i++){
        E[i]  = 0;
      }
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
    auto vAq4Dd79 = ((L[i]));
    auto Y0H_suZr = ((R[i]));
    cl=vAq4Dd79;
    cr=Y0H_suZr;
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
int cnt[100000+10];
int g[100000+10];
int maxocc;
class getocc{
  public:
  void addval(int x){
    if(x == 1){
      return;
    }
    --cnt[g[x]];
    ++g[x];
    ++cnt[g[x]];
    chmax(maxocc, g[x]);
  }
  void delval(int x){
    if(x == 1){
      return;
    }
    bool flag = false;
    --cnt[g[x]];
    if(g[x] == maxocc && cnt[g[x]] == 0){
      flag = true;
    }
    --g[x];
    if(g[x] < 0){
      return;
    }
    ++cnt[g[x]];
    if(flag){
      maxocc = g[x];
    }
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
  }
  public:
  getocc(){
    maxocc = 0;
  }
}
;
int main(){
  int i;
  wmem = memarr;
  psz =Prime_L(100000, ps);
  rd(n);
  rd(q);
  {
    int a3PBjchb;
    for(a3PBjchb=(0);a3PBjchb<(n);a3PBjchb++){
      rd(a[a3PBjchb]);
    }
  }
  {
    int xkgQFmt1;
    for(xkgQFmt1=(0);xkgQFmt1<(q);xkgQFmt1++){
      rd(L[xkgQFmt1]);L[xkgQFmt1] += (-1);
      rd(R[xkgQFmt1]);R[xkgQFmt1] += (-1);
    }
  }
  for(i=(0);i<(psz);i++){
    int j;
    if(ps[i] * ps[i] > 100000){
      break;
    }
    for(j=(0);j<(n);j++){
      pre[j] = 0;
    }
    for(j=(0);j<(n);j++){
      if(a[j] % ps[i] == 0){
        pre[j] = 1;
        while(a[j] % ps[i] == 0){
          a[j] /= ps[i];
        }
      }
    }
    for(j=(1);j<(n);j++){
      pre[j] += pre[j-1];
    }
    for(j=(0);j<(q);j++){
      chmax(ans[j], getrange(L[j], R[j]));
    }
  }
  sqrt_decomp<getocc> sqde;
  sqde.sinit(q+10, (int)sqrt(n), 0);
  sqde.transfer(q, L, R, NULL);
  int px = 0;
  int l = 1;
  int r = 0;
  int cl = 0;
  int cr = 0;
  while( (px = sqde.next(l,r,cl,cr) ) != -1){
    chmax(ans[px], maxocc);
  }
  {
    int MkOXm_kt;
    if(q==0){
      wt_L('\n');
    }
    else{
      for(MkOXm_kt=(0);MkOXm_kt<(q-1);MkOXm_kt++){
        wt_L(ans[MkOXm_kt]);
        wt_L(' ');
      }
      wt_L(ans[MkOXm_kt]);
      wt_L('\n');
    }
  }
  exit(0);
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=60m
// int ps[1d5], psz;
// int n,q, a[1d5+10], L[], R[], ans[], pre[];
// int getrange(int x, int y){
//     if(x == 0){
//         return pre[y];
//     }
//     return  pre[y]-pre[x-1];
// }
// 
// template<class EnterExit> 
// class sqrt_decomp{    
// public:
//     EnterExit * a;
//     int * L, * R, * E,  * IDX;
//     int qsz, lmt, blocksz, _init, cur, solid_state, _update; 
//     void init(bool enable_wmem, int isupdated){
//         _update = 0;
//         _init = 1;
//         if(isupdated) {
//             _update = 1;
//         }
//         if(enable_wmem){
//             walloc1d(&L, qsz, &wmem);
//             walloc1d(&R, qsz, &wmem);
//             if(isupdated) walloc1d(&E, qsz, &wmem);
//             walloc1d(&IDX, qsz, &wmem);
//             this->solid_state = 1;
//         }else{
//             L = new int[qsz];
//             R = new int[qsz];
//             if(isupdated) E = new int[qsz];
//             IDX = new int[qsz];
//             this->solid_state = 0;
//         }
//         rep(i, 0, qsz) L[i] = R[i] =  0;
//         if(isupdated) rep(i, 0, qsz) E[i]  = 0;
//     }
//     sqrt_decomp(){
//         a = new EnterExit();
//         this-> _init = 0;
//     }
//     void sinit(int qsz, int blocksz, int allow_update){
//         if(this->_init) return;
//         this->cur = 0;
//         this->qsz = qsz;
//         this->blocksz = blocksz;
//         this->lmt = 0;
//         this->solid_state = 0;
//         init(true, allow_update);
//     }
//     void hinit(int qsz, int blocksz, int allow_update){
//         if(this->_init) return;
//         this-> _init = 0;
//         this->cur = 0;
//         this->qsz = qsz;
//         this->blocksz = blocksz;
//         this->lmt = 0;
//         this->solid_state = 0;
//         init(false, allow_update);
//     }
//     void clear(){
//         if(!this->solid_state && this->_init){
//             this->_init = 0;
//             delete [] L;
//             delete [] R;
//             if(_update) delete [] E;
//             delete [] IDX;
//             L = R = E = IDX = NULL;
//         }
//     }
//     
//     ~sqrt_decomp(){
//         delete a;  
//         clear();
//     }
//     void transfer(int sz, int * L, int * R, int * E){
//         rep(i, 0, sz)  this->IDX[i] = i;
//         if(E != NULL){
//             _update = 1;
//         }
//         if(!_update){
//             sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
//                 if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
//                 return R[lhs] < R[rhs];
//             });
//         }
//         else{
//             sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
//                 if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
//                 if(R[lhs]/blocksz != R[rhs]/blocksz) return R[lhs] < R[rhs];
//                 return E[lhs] < E[rhs];
//             });
//         }
//         rep(i, 0, sz){
//             this->L[i] = L[this->IDX[i]];
//             this->R[i] = R[this->IDX[i]];
//         }
//         if(_update) rep(i, 0, sz) this->E[i] = E[this->IDX[i]];
//         this->cur = 0;
//         this->lmt = sz;
//     }
//     int next(int & l, int & r, int & cl, int & cr){
//         if(this->cur >= this->lmt) return -1;
//         int i = this->cur;
//         while(l < L[i]) a->change(l, -1), ++l;
//         while(l > L[i]) a->change(l-1, 1), --l;
//         while(r < R[i]) a->change(r+1,1), ++r;
//         while(r > R[i]) a->change(r,-1), --r;
//         (cl, cr)= (L[i],R[i]);
//         ++this->cur;
//         return IDX[i];
//     }
//     int next(int & l, int & r, int cl, int & cr, int & t){
//         if(this->cur >= this->lmt) return -1;
//         int i = this->cur;
//         while(t < E[i]) a->modify(t+1,1, l, r), ++t;
//         while(t > E[i]) a->modify(t,-1, l, r), --t;
//         return next(l,r,cl,cr);
//     }
// };
// 
// int cnt[1d5+10];
// int g[1d5+10];
// int maxocc;
// class getocc{
// public:   
//     void addval(int x){
//         if(x == 1) return;
//         --cnt[g[x]]; 
//         ++g[x];
//         ++cnt[g[x]]; 
//         maxocc >?= g[x];
//     }
//     void delval(int x){
//         if(x == 1) return;
//         bool flag = false;
//         --cnt[g[x]]; 
//         if(g[x] == maxocc && cnt[g[x]] == 0) flag = true;
//         --g[x];
//         if(g[x] < 0) return;
//         ++cnt[g[x]]; 
//         if(flag) maxocc = g[x];
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
//        
//     }
// public:
// 
//     getocc(){
//         maxocc = 0;
//     }
// };
// 
// {
//     psz = Prime(1d5, ps);
//     rd(n, q, a(n), (L--,R--)(q));
//     rep(i, psz){
//         if(ps[i] * ps[i] > 1d5) break;
//         rep(j,n) pre[j] = 0;
//         rep(j,n){
//             if(a[j] % ps[i] == 0){
//                 pre[j] = 1;
//                 while(a[j] % ps[i] == 0) a[j] /= ps[i];
//             }
//         }
//         rep(j,1,n) pre[j] += pre[j-1];
//         rep(j, q){
//             ans[j] >?= getrange(L[j], R[j]);
//         }
//     }
//     sqrt_decomp<getocc> sqde;
//     sqde.sinit(q+10, (int)sqrt(n), 0);
//     sqde.transfer(q, L, R, NULL);
//     int px = 0;
//     int l = 1, r = 0, cl = 0, cr = 0;
//     while( (px = sqde.next(l,r,cl,cr) ) != -1){
//         ans[px] >?= maxocc;
//     }
//     wt(ans(q));
//     exit(0);
// }  
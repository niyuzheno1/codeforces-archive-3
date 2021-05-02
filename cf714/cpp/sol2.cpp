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
struct mint{
  static unsigned md;
  static unsigned W;
  static unsigned R;
  static unsigned Rinv;
  static unsigned mdninv;
  static unsigned RR;
  unsigned val;
  mint(){
    val=0;
  }
  mint(int a){
    val = mulR(a);
  }
  mint(unsigned a){
    val = mulR(a);
  }
  mint(long long a){
    val = mulR(a);
  }
  mint(unsigned long long a){
    val = mulR(a);
  }
  int get_inv(long long a, int md){
    long long t=a;
    long long s=md;
    long long u=1;
    long long v=0;
    long long e;
    while(s){
      e=t/s;
      t-=e*s;
      u-=e*v;
      swap(t,s);
      swap(u,v);
    }
    if(u<0){
      u+=md;
    }
    return u;
  }
  void setmod(unsigned m){
    int i;
    unsigned t;
    W = 32;
    md = m;
    R = (1ULL << W) % md;
    RR = (unsigned long long)R*R % md;
    switch(m){
      case 104857601:
      Rinv = 2560000;
      mdninv = 104857599;
      break;
      case 998244353:
      Rinv = 232013824;
      mdninv = 998244351;
      break;
      case 1000000007:
      Rinv = 518424770;
      mdninv = 2226617417U;
      break;
      case 1000000009:
      Rinv = 171601999;
      mdninv = 737024967;
      break;
      case 1004535809:
      Rinv = 234947584;
      mdninv = 1004535807;
      break;
      case 1007681537:
      Rinv = 236421376;
      mdninv = 1007681535;
      break;
      case 1012924417:
      Rinv = 238887936;
      mdninv = 1012924415;
      break;
      case 1045430273:
      Rinv = 254466304;
      mdninv = 1045430271;
      break;
      case 1051721729:
      Rinv = 257538304;
      mdninv = 1051721727;
      break;
      default:
      Rinv = get_inv(R, md);
      mdninv = 0;
      t = 0;
      for(i=(0);i<((int)W);i++){
        if(t%2==0){
          t+=md;
          mdninv |= (1U<<i);
        }
        t /= 2;
      }
    }
  }
  unsigned mulR(unsigned a){
    return (unsigned long long)a*R%md;
  }
  unsigned mulR(int a){
    if(a < 0){
      a = a%((int)md)+(int)md;
    }
    return mulR((unsigned)a);
  }
  unsigned mulR(unsigned long long a){
    return mulR((unsigned)(a%md));
  }
  unsigned mulR(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return mulR((unsigned)a);
  }
  unsigned reduce(unsigned T){
    unsigned m = T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned reduce(unsigned long long T){
    unsigned m = (unsigned)T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned get(){
    return reduce(val);
  }
  mint &operator+=(mint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  mint &operator-=(mint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  mint &operator*=(mint a){
    val = reduce((unsigned long long)val*a.val);
    return *this;
  }
  mint &operator/=(mint a){
    return *this *= a.inverse();
  }
  mint operator+(mint a){
    return mint(*this)+=a;
  }
  mint operator-(mint a){
    return mint(*this)-=a;
  }
  mint operator*(mint a){
    return mint(*this)*=a;
  }
  mint operator/(mint a){
    return mint(*this)/=a;
  }
  mint operator+(int a){
    return mint(*this)+=mint(a);
  }
  mint operator-(int a){
    return mint(*this)-=mint(a);
  }
  mint operator*(int a){
    return mint(*this)*=mint(a);
  }
  mint operator/(int a){
    return mint(*this)/=mint(a);
  }
  mint operator+(long long a){
    return mint(*this)+=mint(a);
  }
  mint operator-(long long a){
    return mint(*this)-=mint(a);
  }
  mint operator*(long long a){
    return mint(*this)*=mint(a);
  }
  mint operator/(long long a){
    return mint(*this)/=mint(a);
  }
  mint operator-(void){
    mint res;
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
  mint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    mint res;
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
    res.val = (unsigned long long)u*RR % md;
    return res;
  }
  mint pw(unsigned long long b){
    mint a(*this);
    mint res;
    res.val = R;
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
    return mulR(a)==val;
  }
  bool operator!=(int a){
    return mulR(a)!=val;
  }
}
;
unsigned mint::md;
unsigned mint::W;
unsigned mint::R;
unsigned mint::Rinv;
unsigned mint::mdninv;
unsigned mint::RR;
mint operator+(int a, mint b){
  return mint(a)+=b;
}
mint operator-(int a, mint b){
  return mint(a)-=b;
}
mint operator*(int a, mint b){
  return mint(a)*=b;
}
mint operator/(int a, mint b){
  return mint(a)/=b;
}
mint operator+(long long a, mint b){
  return mint(a)+=b;
}
mint operator-(long long a, mint b){
  return mint(a)-=b;
}
mint operator*(long long a, mint b){
  return mint(a)*=b;
}
mint operator/(long long a, mint b){
  return mint(a)/=b;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
inline void wt_L(mint x){
  int i;
  i = (int)x;
  wt_L(i);
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
struct combination_mint{
  mint*fac;
  mint*ifac;
  void init(int n, void **mem = &wmem){
    int i;
    walloc1d(&fac, n, mem);
    walloc1d(&ifac, n, mem);
    fac[0] = 1;
    for(i=(1);i<(n);i++){
      fac[i] = fac[i-1] * i;
    }
    ifac[n-1] = 1 / fac[n-1];
    for(i=n-2;i>=0;i--){
      ifac[i] = ifac[i+1] * (i+1);
    }
  }
  mint C(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    return fac[a]*ifac[b]*ifac[a-b];
  }
  mint P(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    return fac[a]*ifac[a-b];
  }
  mint H(int a, int b){
    if(a==0 && b==0){
      return 1;
    }
    if(a<=0 || b<0){
      return 0;
    }
    return C(a+b-1, b);
  }
}
;
const int MN = 200000+10;
int n;
int a[MN];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  {
    mint x;
    x.setmod(MD);
  }
  combination_mint comb ;
  comb.init (MN) ;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(n);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        rd(a[cTE1_r3A]);
      }
    }
    int aa = a[0];
    map<int,int> dis;
    for(i=(0);i<(n);i++){
      aa &= a[i];
      ++dis[a[i]];
    }
    auto ans = comb.fac[n-2];
    ans *= comb.C(dis[aa],2);
    ans *=2;
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 2d5+10;
// int n,a[MN];
// {
//     combination_mint comb ; 
//     comb.init (MN) ;
//     REP(rd_int()){
//         rd(n,a(n));
//         int aa = a[0];
//         map<int,int> dis;
//         rep(i,n) {
//             aa &= a[i];
//             ++dis[a[i]];
//         }
//         auto ans = comb.fac[n-2];
//         ans *= comb.C(dis[aa],2);
//         ans *=2;
//         wt(ans);
//     }
// }
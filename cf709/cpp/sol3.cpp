#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
#define Arguments ...Args
#define all_defined_y_combo     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
#define arguments_y_combo     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
#define template_for_y_comb template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<class Fun> class y_combinator_result{
  Fun fun_;
  public:
  all_defined_y_combo ;
  arguments_y_combo;
}
;
template_for_y_comb;
#define default_empty ={}
#define default_zero =0
#define get_query_value  T query_value(int a, int b){  return values[query_index(a, b)];}
template<typename T, bool maximum_mode = false> struct RMQ{
  int n = 0;
  vector<T> values;
  vector<vector<int>> range_low;
  RMQ(const vector<T> &_values default_empty){
    if (!_values.empty()){
      build(_values);
    }
  }
  RMQ(T * _values default_zero, int sz default_zero){
    int i;
    vector<T> _v;
    for(i=(0);i<(sz);i++){
      _v.push_back(_values[i]);
    }
    if(sz > 0){
      build(_v);
    }
  }
  static int highest_bit(int x){
    return x == 0 ? -1 : 31 - __builtin_clz(x);
  }
  int better_index(int a, int b){
    return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
  }
  void build(const vector<T> &_values){
    values = _values;
    n = int(values.size());
    int levels = highest_bit(n) + 1;
    range_low.resize(levels);
    for (int k = 0; k < levels; k++){
      range_low[k].resize(n - (1 << k) + 1);
    }
    for (int i = 0; i < n; i++){
      range_low[0][i] = i;
    }
    for (int k = 1; k < levels; k++){
      for (int i = 0; i <= n - (1 << k); i++){
        range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
      }
    }
  }
  int query_index(int a, int b){
    assert(0 <= a && a < b && b <= n);
    int level = highest_bit(b - a);
    return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
  }
  get_query_value;
}
;
const int MN = 300000+10;
long long n;
long long h[MN];
long long b[MN];
int main(){
  rd(n);
  {
    int KrdatlYV;
    for(KrdatlYV=(0);KrdatlYV<(n);KrdatlYV++){
      rd(h[KrdatlYV]);
    }
  }
  {
    int a2conNHc;
    for(a2conNHc=(0);a2conNHc<(n);a2conNHc++){
      rd(b[a2conNHc]);
    }
  }
  RMQ<long long> rmq(h,n);
  auto tmp = y_combinator(
        [&](auto solve, int l, int r) -> long long {
            
            if(l > r) return 0;
            auto x = rmq.query_index(l,r+1);
            
            auto lx = x-1;
            auto rx = x+1;
            auto leftx = solve(l, lx);
            auto rightx = solve(rx, r);
            auto ans = b[x] + leftx + rightx;
            if(l != 0) ans =max_L(ans, rightx);
            if(r != n-1) ans =max_L(ans, leftx);
            return ans;
        }
    );
  wt_L(tmp(0,n-1));
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// 
// #define Arguments ...Args
// #define all_defined_y_combo     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
// #define arguments_y_combo     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
// #define template_for_y_comb template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
// template<class Fun> class y_combinator_result {
//     Fun fun_;
// public:
//     all_defined_y_combo ;
//     arguments_y_combo;
// };
// 
// template_for_y_comb;
// // The following template is accredited to Neal Wu.
// // I have rewritten it so it fits more for cLay
// #define default_empty ={}
// #define default_zero =0
// #define get_query_value  T query_value(int a, int b){  return values[query_index(a, b)];}
// template<typename T, bool maximum_mode = false>
// struct RMQ {
//     int n = 0;
//     vector<T> values;
//     vector<vector<int>> range_low;
//     RMQ(const vector<T> &_values default_empty) {
//         if (!_values.empty())
//             build(_values);
//     }
//     RMQ(T * _values default_zero, int sz default_zero){
//         vector<T> _v;
//         rep(i,sz){
//             _v.push_back(_values[i]);
//         }
//         if(sz > 0)
//         {
//             build(_v);
//         }
//     }
//     static int highest_bit(int x) {
//         return x == 0 ? -1 : 31 - __builtin_clz(x);
//     }
// 
//     int better_index(int a, int b)  {
//         return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
//     }
//     void build(const vector<T> &_values) {
//         values = _values;
//         n = int(values.size());
//         int levels = highest_bit(n) + 1;
//         range_low.resize(levels);
//  
//         for (int k = 0; k < levels; k++)
//             range_low[k].resize(n - (1 << k) + 1);
//  
//         for (int i = 0; i < n; i++)
//             range_low[0][i] = i;
//  
//         for (int k = 1; k < levels; k++)
//             for (int i = 0; i <= n - (1 << k); i++)
//                 range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
//     }
//         // Note: breaks ties by choosing the largest index.
//     int query_index(int a, int b) {
//         assert(0 <= a && a < b && b <= n);
//         int level = highest_bit(b - a);
//         return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
//     }
//     get_query_value;
// 
// };
// const int MN = 3d5+10;
// ll n, h[MN], b[MN];
// 
// {
//     rd(n,h(n),b(n));
//     RMQ<ll> rmq(h,n);
//     auto tmp = y_combinator(
//         [&](auto solve, int l, int r) -> ll {
//             
//             if(l > r) return 0;
//             auto x = rmq.query_index(l,r+1);
//             
//             auto lx = x-1;
//             auto rx = x+1;
//             auto leftx = solve(l, lx);
//             auto rightx = solve(rx, r);
//             auto ans = b[x] + leftx + rightx;
//             if(l != 0) ans = max(ans,rightx);
//             if(r != n-1) ans = max(ans, leftx);
//             return ans;
//         }
//     );
//     wt(tmp(0,n-1));
// }
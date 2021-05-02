#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
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
#define Declare [&]( auto solve, int l, int r)
long long n;
long long p;
long long a[200000+20];
long long e[200000+20];
int main(){
  int KrdatlYV;
  int ao_dF3pO = rd_int();
  for(KrdatlYV=(0);KrdatlYV<(ao_dF3pO);KrdatlYV++){
    int i;
    rd(n);
    rd(p);
    {
      int hCmBdyQB;
      for(hCmBdyQB=(0);hCmBdyQB<(n);hCmBdyQB++){
        rd(a[hCmBdyQB]);
      }
    }
    RMQ<long long> rmq(a,n);
    for(i=(0);i<(n+2);i++){
      e[i] = p;
    }
    e[n-1] = 0;
    auto solution =  [&]( auto solve, int l, int r) {
            if(r <= l) return 0;
            int res =rmq.query_index(l,r);
            
            int tol = res, tor = res+1;
            while(tol >max_L(l-1, 0)&&GCD_L(a[tol-1], a[res])== a[res]) --tol;
            while(tor <min_L(r+1, n)&&GCD_L(a[tor], a[res])== a[res]) ++tor;
            rep(j, tol, tor)e[j] =min_L(e[j], a[res]);
            
            solve(l, tol) ;
            solve(tor,r) ;
            return 0;
        };
    auto tmp = y_combinator(solution)(0,n);
    {
      int jPV_0s1p;
      long long BUotOFBp;
      if(n==0){
        BUotOFBp = 0;
      }
      else{
        BUotOFBp = e[0];
        for(jPV_0s1p=(1);jPV_0s1p<(n);jPV_0s1p++){
          BUotOFBp += e[jPV_0s1p];
        }
      }
      wt_L(BUotOFBp);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
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
// 
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
//  
// #define Declare [&]( auto solve, int l, int r)
// ll n, p, a[2d5+20], e[2d5+20];
// {
//     REP(rd_int()){
//         rd(n,p,a(n));
//         RMQ<ll> rmq(a,n);
//         rep(i,n+2) e[i] = p;
//         e[n-1] = 0;
//         auto solution =  [&]( auto solve, int l, int r) {
//             if(r <= l) return 0;
//             int res =rmq.query_index(l,r);
//             
//             int tol = res, tor = res+1;
//             while(tol > max(l-1,0) && gcd(a[tol-1], a[res]) == a[res]) --tol;
//             while(tor < min(r+1,n) && gcd(a[tor], a[res]) == a[res]) ++tor;
//             rep(j, tol, tor)e[j] = min(e[j] ,a[res]);
//             
//             solve(l, tol) ;
//             solve(tor,r) ;
//             return 0;
//         };
//         auto tmp = y_combinator(solution)(0,n);
//         
//         wt(sum(e(n)));
//     }
//     
// }
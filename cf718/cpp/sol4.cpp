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
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
int a[510][510];
int b[510][510];
int f[510][510];
int tmp[510][510];
int n;
int m;
int k;
int ans[510];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool within(int x, int y){
  return 0 <= x  &&  x < n && 0 <= y  &&  y < m;
}
int main(){
  int Y0H_suZr, i;
  rd(n);
  rd(m);
  rd(k);
  {
    int PiIOrLma;
    int AuJVIghY;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      for(AuJVIghY=(0);AuJVIghY<(m-1);AuJVIghY++){
        rd(a[PiIOrLma][AuJVIghY]);
      }
    }
  }
  {
    int rbGYC8dh;
    int NN9wFlop;
    for(rbGYC8dh=(0);rbGYC8dh<(n-1);rbGYC8dh++){
      for(NN9wFlop=(0);NN9wFlop<(m);NN9wFlop++){
        rd(b[rbGYC8dh][NN9wFlop]);
      }
    }
  }
  if(k % 2){
    int i;
    for(i=(0);i<(m);i++){
      ans[i] = -1;
    }
    for(i=(0);i<(n);i++){
      {
        int Btiq50RC;
        if(m==0){
          wt_L('\n');
        }
        else{
          for(Btiq50RC=(0);Btiq50RC<(m-1);Btiq50RC++){
            wt_L(ans[Btiq50RC]);
            wt_L(' ');
          }
          wt_L(ans[Btiq50RC]);
          wt_L('\n');
        }
      }
    }
    return 0;
  }
  k>>=1;
  for(Y0H_suZr=(0);Y0H_suZr<(k);Y0H_suZr++){
    int i;
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        tmp[i][j]= 1073709056;
      }
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        int w;
        for(w=(0);w<(4);w++){
          int ni = i + dx[w];
          int nj = j + dy[w];
          int mi =min_L(i, ni);
          int mj =min_L(j, nj);
          if(within(ni,nj)){
            chmin(tmp[ni][nj], f[i][j] + (abs(dx[w]) == 1?  b[mi][mj] : a[mi][mj]));
          }
        }
      }
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        f[i][j] = tmp[i][j];
      }
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(m);j++){
      ans[j] = 2*f[i][j];
    }
    {
      int MkOXm_kt;
      if(m==0){
        wt_L('\n');
      }
      else{
        for(MkOXm_kt=(0);MkOXm_kt<(m-1);MkOXm_kt++){
          wt_L(ans[MkOXm_kt]);
          wt_L(' ');
        }
        wt_L(ans[MkOXm_kt]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked 
// int a[510][510], b[510][510], f[510][510], tmp[510][510], n,m,k, ans[510];
// 
// const int dx[] = {-1, 1, 0, 0};
// const int dy[] = {0, 0, -1, 1};
// bool within(int x, int y){
//     return 0 <= x < n && 0 <= y < m;
// }
// {
//     rd(n,m,k, a(n,m-1), b(n-1,m));
//     if(k % 2){
//         rep(i, m) ans[i] = -1;
//         rep(i, n){
//             wt(ans(m));
//         }
//         return 0;
//     }
//     k>>=1;
//     rep(k){
//         rep(i, n) rep(j, m) tmp[i][j]= int_inf;
//         rep(i, n) rep(j, m) 
//         {
//             rep(w, 4){
//                 int ni = i + dx[w];
//                 int nj = j + dy[w];
//                 int mi = min(i,ni);
//                 int mj = min(j,nj);
//                 if(within(ni,nj)){
//                     tmp[ni][nj] <?= f[i][j] + (abs(dx[w]) == 1?  b[mi][mj] : a[mi][mj]);
//                 }
//             }
//         }
//         rep(i, n) rep(j, m) f[i][j] = tmp[i][j];
//     }
//     rep(i, n){
//         rep(j,m) ans[j] = 2*f[i][j];
//         wt(ans(m));
//     }
// }
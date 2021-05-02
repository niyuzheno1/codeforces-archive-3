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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int n;
int m;
int a[17][10000+10];
int d[17][17];
int sd[17][17];
int f[16][16][1<<16];
int dfs(int x, int y, int z){
  int i;
  if(z == (1<<n)-1){
    return sd[x][y];
  }
  int& ret = f[x][y][z];
  if(ret != -1){
    return ret;
  }
  ret = 0;
  for(i=(0);i<(n);i++){
    if( ((z >> i ) & 1) == 0){
      chmax(ret, min_L(d[y][i], dfs(x, i, z | (1 << i))));
    }
  }
  return ret;
}
int main(){
  int i;
  memset(f,0xff,sizeof(f));
  rd(n);
  rd(m);
  {
    int GIHf_YD2;
    int djQeACzd;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      for(djQeACzd=(0);djQeACzd<(m);djQeACzd++){
        rd(a[GIHf_YD2][djQeACzd]);
      }
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(n);j++){
      sd[i][j] = d[i][j] = 1073709056;
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(i+1);j<(n);j++){
      int k;
      for(k=(0);k<(m);k++){
        chmin(d[i][j], abs(a[i][k] - a[j][k]));
      }
      d[j][i] = d[i][j];
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(n);j++){
      int k;
      for(k=(0);k<(m-1);k++){
        chmin(sd[i][j], abs(a[i][k+1] - a[j][k]));
      }
    }
  }
  int ans = 0;
  for(i=(0);i<(n);i++){
    chmax(ans, dfs(i, i, 1<<i));
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m, a[17][1d4+10];
// int d[17][17], sd[17][17];
// int f[16][16][1<<16];
// 
// int dfs(int x, int y, int z){
//     if(z == (1<<n)-1) return sd[x][y];
//     int & ret = f[x][y][z];
//     if(ret != -1) return ret;
//     ret = 0;
//     rep(i, n){
//         if( ((z >> i ) & 1) == 0){
//             ret >?= min(d[y][i], dfs(x, i, z | (1 << i)));
//         }
//     }
//     return ret;
// }
// 
// {
//     memset(f,0xff,sizeof(f));
//     rd(n, m, a(n,m));
//     rep(i, n) rep(j, n) sd[i][j] = d[i][j] = int_inf;
//     rep(i, n) rep(j, i+1, n){
//         rep(k, 0, m) d[i][j] <?= abs(a[i][k] - a[j][k]);
//         d[j][i] = d[i][j];
//     }
//     rep(i, n) rep(j, n){
//         
//         rep(k, 0, m-1) sd[i][j] <?= abs(a[i][k+1] - a[j][k]);
//     }
//     int ans = 0;
//     rep(i, n){
//         ans >?= dfs(i, i, 1<<i);
//     }
//     wt(ans);
// }
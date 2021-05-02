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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int n;
int m;
int q;
int qu[5100][2];
int a[510][510];
int mr[510];
int le[510][510];
void update_row(int i){
  int j;
  for(j=(0);j<(m);j++){
    if(j == 0){
      le[i][j] = (a[i][j] == 1);
    }
    else{
      le[i][j] = a[i][j] * (le[i][j-1]+1);
    }
  }
}
int main(){
  int i;
  rd(n);
  rd(m);
  rd(q);
  {
    int FJNsjZ7B;
    int GIHf_YD2;
    for(FJNsjZ7B=(0);FJNsjZ7B<(n);FJNsjZ7B++){
      for(GIHf_YD2=(0);GIHf_YD2<(m);GIHf_YD2++){
        rd(a[FJNsjZ7B][GIHf_YD2]);
      }
    }
  }
  {
    int C3F7XFP2;
    int EZ0PmQmu;
    for(C3F7XFP2=(0);C3F7XFP2<(q);C3F7XFP2++){
      for(EZ0PmQmu=(0);EZ0PmQmu<(2);EZ0PmQmu++){
        rd(qu[C3F7XFP2][EZ0PmQmu]);
      }
    }
  }
  for(i=(0);i<(n);i++){
    update_row(i);
    int Btiq50RC;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type lo08wcHZ;
    if(m==0){
      lo08wcHZ = 0;
    }
    else{
      lo08wcHZ = le[i][0];
      for(Btiq50RC=(1);Btiq50RC<(m);Btiq50RC++){
        lo08wcHZ = max_L(lo08wcHZ, le[i][Btiq50RC]);
      }
    }
    mr[i] =lo08wcHZ;
  }
  for(i=(0);i<(q);i++){
    int j;
    int x;
    int y;
    auto WpmOCj1U = ((qu[i][0]));
    auto cDHiUAlz = ((qu[i][1]));
    x=WpmOCj1U;
    y=cDHiUAlz;
    --x;
    --y;
    a[x][y] ^= 1;
    update_row(x);
    int a3PBjchb;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type j4Ja_un4;
    if(m==0){
      j4Ja_un4 = 0;
    }
    else{
      j4Ja_un4 = le[x][0];
      for(a3PBjchb=(1);a3PBjchb<(m);a3PBjchb++){
        j4Ja_un4 = max_L(j4Ja_un4, le[x][a3PBjchb]);
      }
    }
    mr[x] =j4Ja_un4;
    int ans = 0;
    for(j=(0);j<(n);j++){
      chmax(ans, mr[j]);
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n,m,q;
// int qu[5100][2];
// int a[510][510];
// int mr[510];
// int le[510][510];
// 
// void update_row(int i){
//         rep(j, m){
//             if(j == 0){
//                 le[i][j] = (a[i][j] == 1);
//             }else{
//                 le[i][j] = a[i][j] * (le[i][j-1]+1);
//             }
//         }
// }
// 
// {
//     rd(n,m, q, a(n,m), qu(q,2) );
//     rep(i, n) {
//         update_row(i);
//         mr[i] = max(le[i](m));
//     }
//     rep(i, q){
//         int x, y;
//         (x,y) = (qu[i][0],qu[i][1]);
//         --x, --y;
//         a[x][y] ^= 1;
//         update_row(x);
//         mr[x] = max(le[x](m));
//         int ans = 0;
//         rep(j, n) ans >?= mr[j];
//         wt(ans); 
//     }
// 
// }
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int k;
const int MN = 100000+20;
int pre[MN];
int t[MN];
int a[MN];
int b[MN];
int range_pre(int x, int y){
  if(y < 0){
    return 0;
  }
  if(x == 0){
    return pre[y];
  }
  return pre[y]-((x==0)?0:pre[x-1]);
}
int range_sum(int x, int y){
  if(y < 0){
    return 0;
  }
  if(x == 0){
    return b[y];
  }
  return b[y] - ((x==0)?0:b[x-1]);
}
int main(){
  int i;
  rd(n);
  rd(k);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      rd(t[GIHf_YD2]);
    }
  }
  for(i=(0);i<(n);i++){
    b[i] = ((i == 0)? 0 : b[i-1]) + a[i];
  }
  for(i=(0);i<(n);i++){
    pre[i] = ((i == 0)? 0 : pre[i-1]) + ((t[i]==1)?a[i]:0);
  }
  int ans = 0;
  for(i=(0);i<(n-k+1);i++){
    chmax(ans, range_pre(0,i-1) + range_sum(i,i+k-1) + range_pre(i+k,n-1));
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n,k;
// const int MN = 1d5+20;
// int pre[MN],  t[MN], a[MN], b[MN];
// int range_pre(int x, int y){
//     //TODO: compute the sum of pre from interval [l,r]
//     if(y < 0) return 0;
//     if(x == 0) return pre[y];
//     return pre[y]-((x==0)?0:pre[x-1]);
// }
// int range_sum(int x, int y){
//     if(y < 0) return 0;
//     if(x == 0) return b[y];
//     return b[y] - ((x==0)?0:b[x-1]);
// }
// {
//     rd(n,k,a(n), t(n));
//     rep(i,n) b[i] = ((i == 0)? 0 : b[i-1]) + a[i];
//     rep(i,n) pre[i] = ((i == 0)? 0 : pre[i-1]) + ((t[i]==1)?a[i]:0);
//     int ans = 0;
//     rep(i,n-k+1){
//         ans >?= range_pre(0,i-1) + range_sum(i,i+k-1) + range_pre(i+k,n-1);
//     }
//     wt(ans);
// }
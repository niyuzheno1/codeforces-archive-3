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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int s[3100];
int c[3100];
int a[3100];
int b[3100];
int n;
int main(){
  int i;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(s[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      rd(c[GIHf_YD2]);
    }
  }
  for(i=(0);i<(n);i++){
    a[i] = b[i] = 1073709056;
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(i+1);j<(n);j++){
      if(s[i] >= s[j]){
        continue;
      }
      chmin(a[i], c[j]);
      chmin(b[j], c[i]);
    }
  }
  int ans = 1073709056;
  for(i=(0);i<(n);i++){
    if(a[i] >= 1073709056 || b[i] >= 1073709056){
      continue;
    }
    chmin(ans, a[i]+b[i]+c[i]);
  }
  if(ans >= 1073709056){
    wt_L(-1);
    wt_L('\n');
  }
  else{
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int s[3100], c[], a[], b[];
// int n;
// {
//     rd(n, s(n),c(n));
//     rep(i,n) a[i] = b[i] = int_inf;
//     rep(i,n) rep(j,i+1,n) {
//         if(s[i] >= s[j]) continue;
//         a[i] <?= c[j];
//         b[j] <?= c[i];
//     }
//     int ans = int_inf;
//     rep(i,n) {
//         if(a[i] >= int_inf || b[i] >= int_inf) continue;
//         ans <?= a[i]+b[i]+c[i];
//     }
//     if(ans >= int_inf) wt(-1);
//     else wt(ans);
// }
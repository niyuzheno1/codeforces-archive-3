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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int a[2100];
int pre[2100];
int getrange(int x, int y){
  if(x == 0){
    return pre[y];
  }
  return pre[x-1] ^ pre[y];
}
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    int n;
    rd(n);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(a[djQeACzd]);
      }
    }
    for(i=(0);i<(n);i++){
      if(i == 0){
        pre[i] = 0;
      }
      else{
        pre[i] = pre[i-1];
      }
      pre[i] ^= a[i];
    }
    bool ret = false;
    for(i=(0);i<(n-1);i++){
      int j;
      if(getrange(0,i) == getrange(i+1,n-1)){
        ret = true;
      }
      for(j=(i+1);j<(n-1);j++){
        if(getrange(0,i) == getrange(i+1,j) && getrange(j+1, n-1) == getrange(i+1,j)){
          ret = true;
        }
      }
    }
    if(ret){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int a[2100];
// int pre[2100];
// int getrange(int x, int y){
//     if(x == 0){
//         return pre[y];
//     }
//     return pre[x-1] ^ pre[y];
// }
// {
//     REP(rd_int()){
//         int @n;
//         rd(a(n));
//         rep(i, n){
//             if(i == 0) pre[i] = 0;
//             else pre[i] = pre[i-1];
//             pre[i] ^= a[i];
//         }
//         bool ret = false;
//         rep(i,n-1){
//             if(getrange(0,i) == getrange(i+1,n-1)) ret = true;
//             rep(j,i+1, n-1){
//                 if(getrange(0,i) == getrange(i+1,j) && getrange(j+1, n-1) == getrange(i+1,j)) ret = true;
//             }
//         }
// 
//         if(ret) wt("YES");
//         else wt("NO");
//     }
// }
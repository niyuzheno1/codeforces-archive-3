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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int v1;
int v2;
int t;
int d;
int a[100];
int b[100];
long long f[110][20*110];
const int inf = -4611686016279904256LL+30;
int main(){
  int i;
  rd(v1);
  rd(v2);
  rd(t);
  rd(d);
  for(i=(0);i<(t+2);i++){
    int j;
    for(j=(0);j<((t+2)*d+v1+v2);j++){
      f[i][j] = inf;
    }
  }
  int t1 = v1;
  int t2 = v1;
  for(i=(0);i<(t);i++){
    a[i] = t1;
    b[i] = t2;
    t1 += d;
    t2 -= d;
    chmax(t2, 0);
  }
  f[0][v1] = 0;
  for(i=(0);i<(t);i++){
    int j;
    for(j=(b[i]);j<(a[i]+1);j++){
      int k;
      if(f[i][j] <= inf){
        continue;
      }
      for(k=(-d);k<(d+1);k++){
        if(k+j < 0){
          continue;
        }
        chmax(f[i+1][j+k], f[i][j] + j);
      }
    }
  }
  wt_L(f[t-1][v2]+v2);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int v1,v2, t,d;
// int a[100];
// int b[100];
// ll f[110][20*110];
// const int inf = -ll_inf+30;
// {
//     rd(v1,v2,t,d);
//     rep(i, t+2) rep(j, (t+2)*d+v1+v2){
//         f[i][j] = inf;
//     }
//     int t1 = v1, t2 = v1;
//     rep(i, t){
//         a[i] = t1;
//         b[i] = t2;
//         t1 += d;
//         t2 -= d;
//         t2 >?= 0;
//     }
//     f[0][v1] = 0;
//     rep(i, t){
//         rep(j,b[i], a[i]+1){
//             if(f[i][j] <= inf) continue;
//             rep(k, -d, d+1){
//                 if(k+j < 0) continue;
//                 f[i+1][j+k] >?= f[i][j] + j;
//             }
//         }
//     }
//     wt(f[t-1][v2]+v2);
// }
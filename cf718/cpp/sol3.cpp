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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int n;
int p[510];
int ans[510][510];
bool within(int x, int y){
  return 0 <= x  &&  x < n && 0 <= y  &&  y < n;
}
int main(){
  int i;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(p[PiIOrLma]);
    }
  }
  for(i=(0);i<(n);i++){
    ans[i][i] = p[i];
  }
  for(i=(0);i<(n);i++){
    int cnt = p[i]-1;
    int x=i;
    int y = i;
    while(cnt){
      if(within(x,y-1) && ans[x][y-1] == 0){
        ans[x][y-1] = p[i];
        --y;
      }
      else if(within(x+1,y) && ans[x+1][y] == 0){
        ans[x+1][y] = p[i];
        ++x;
      }
      --cnt;
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(i+1);j++){
      int u = ans[i][j];
      wt_L(u);
      wt_L(" ");
    }
    wt_L("");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, p[510];
// int ans[510][510];
// bool within(int x, int y){
//     return 0 <= x < n && 0 <= y < n;
// }
// 
// {
//     rd(n, p(n));
//     rep(i, n) ans[i][i] = p[i];
//     rep(i, n){
//         int cnt = p[i]-1;
//         int x=i, y = i;
//         while(cnt){
//             if(within(x,y-1) && ans[x][y-1] == 0){
//                 ans[x][y-1] = p[i];
//                 --y;
//             }
//             else if(within(x+1,y) && ans[x+1][y] == 0){
//                 ans[x+1][y] = p[i];
//                 ++x;
//             }
//             
//             --cnt;
//         }
//     }
//     rep(i,n){
//         rep(j,i+1){
//             int u = ans[i][j];
//             wtF("{u} ");
//         }
//         wt("");
//     }
// }
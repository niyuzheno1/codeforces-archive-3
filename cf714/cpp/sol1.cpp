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
const int MAXN = 110;
int ans[MAXN];
int s[MAXN];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int n;
    rd(n);
    int k;
    rd(k);
    int kk;
    int i = 1 ;
    for(i=(0);i<(n+3);i++){
      s[i] = ans[i] = 0;
    }
    int c = n;
    kk = k;
    i = 1;
    while(k > 0 && i < n){
      ans[i] = c;
      s[c] = 1;
      i += 2;
      --c;
      --k;
    }
    if(k > 0){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    c = 1;
    for(i=(0);i<(n);i++){
      if(ans[i] != 0){
        continue;
      }
      while(s[c]){
        ++c;
      }
      ans[i] = c;
      s[c] = 1;
    }
    int cnt = 0;
    for(i=(1);i<(n-1);i++){
      if(ans[i] > ans[i-1] && ans[i] > ans[i+1]){
        cnt = cnt + 1;
      }
    }
    if(cnt == kk){
      {
        int hCmBdyQB;
        if(n==0){
          wt_L('\n');
        }
        else{
          for(hCmBdyQB=(0);hCmBdyQB<(n-1);hCmBdyQB++){
            wt_L(ans[hCmBdyQB]);
            wt_L(' ');
          }
          wt_L(ans[hCmBdyQB]);
          wt_L('\n');
        }
      }
    }
    else{
      wt_L(-1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MAXN = 110;
// int ans[MAXN], s[MAXN];
// {
//     REP(rd_int()){
//         int @n,@k, kk,i = 1 ;
//         rep(i,0,n+3) s[i] = ans[i] = 0;
//         int  c = n;
//         kk = k;
//         i = 1;
//         while(k > 0 && i < n){
//             ans[i] = c;
//             s[c] = 1;
//             i += 2;
//             --c;
//             --k;
//         }
//         if(k > 0){
//             wt(-1); continue;
//         }
//         c = 1;
//         rep(i,0,n){
//             if(ans[i] != 0) continue;
//             while(s[c]) ++c;
//             ans[i] = c;
//             s[c] = 1;
//         }
//         int cnt = 0;
//         rep(i,1,n-1){
//             if(ans[i] > ans[i-1] && ans[i] > ans[i+1]) cnt = cnt + 1;
//         }
//         if(cnt == kk){
//             wt(ans(n));
//         }else{
//             wt(-1);
//         }
//     }
// }
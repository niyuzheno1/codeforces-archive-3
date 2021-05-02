#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int Tcases;
const int MN = 300000+20;
int n;
int a[MN];
int freq[MN];
char ans[MN];
char ans2[MN];
int main(){
  int Lj4PdHRW;
  rd(Tcases);
  for(Lj4PdHRW=(0);Lj4PdHRW<(Tcases);Lj4PdHRW++){
    int i;
    rd(n);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(a[e98WHCEY]);
      }
    }
    for(i=(0);i<(n);i++){
      --a[i];
    }
    for(i=(0);i<(n+2);i++){
      freq[i] = 0;
    }
    for(i=(n-1);i<(n+2);i++){
      ans[i] = 0;
    }
    for(i=(0);i<(n);i++){
      ++freq[a[i]];
    }
    int hCmBdyQB;
    int V9aVTaxx;
    if(n==0){
      V9aVTaxx = 0;
    }
    else{
      V9aVTaxx = freq[0];
      for(hCmBdyQB=(1);hCmBdyQB<(n);hCmBdyQB++){
        V9aVTaxx = min_L(V9aVTaxx, freq[hCmBdyQB]);
      }
    }
    int mv = V9aVTaxx;
    bool okay = freq[0] > 0;
    ans[0] = okay + '0';
    ans[n-1] = '0'+mv;
    int l = 0;
    int r = n-1;
    for(i=(0);i<(n-2);i++){
      if(freq[i] > 1){
        okay = false;
      }
      if(freq[i+1] == 0){
        okay = false;
      }
      if(a[l] == i){
        ++l;
      }
      else if(a[r] == i){
        --r;
      }
      else{
        okay = false;
      }
      ans[i+1] = int(okay) + '0';
    }
    for(i=(0);i<(n);i++){
      ans2[i] = ans[n-i-1];
    }
    ans2[n] = 0;
    wt_L(ans2);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int Tcases;
// const int MN = 3d5+20;
// int n;
// int a[MN];
// int freq[MN];
// char ans[MN];
// char ans2[MN];
// {
//     rd(Tcases);
//     rep(Tcases){
//         rd(n, a(n));
//         rep(i,n) --a[i];
//         rep(i,n+2) freq[i] = 0;
//         rep(i,n-1,n+2) ans[i] = 0;
//         rep(i,n) ++freq[a[i]];
//         int mv = min(freq(n));
//         bool okay = freq[0] > 0;
//         ans[0] = okay + '0';
//         ans[n-1] = '0'+mv;
//         int l = 0, r = n-1;
//         rep(i,n-2){
//             if(freq[i] > 1){
//                 okay = false;
//             }
//             if(freq[i+1] == 0){
//                 okay = false;
//             }
//             if(a[l] == i){
//                 ++l;
//             }
//             else if(a[r] == i){
//                 --r;
//             }else{
//                 okay = false;
//             }
//             ans[i+1] = int(okay) + '0';
//         }
//         rep(i,n){
//             ans2[i] = ans[n-i-1];
//         }
//         ans2[n] = 0;
//         wt(ans2);
//     }
// }
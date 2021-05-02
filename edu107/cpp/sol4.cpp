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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
char rans[200000+10];
int main(){
  int i;
  int n;
  rd(n);
  int k;
  rd(k);
  string ans;
  for(i=(0);i<(k);i++){
    int j;
    ans += ('a'+i);
    if(i == k-1){
      break;
    }
    ans += ('a'+i);
    for(j=(i+1);j<(k);j++){
      ans += 'a'+j;
      if(j != k-1){
        ans += 'a'+i;
      }
    }
  }
  int m = ans.length();
  for(i=(0);i<(n);i++){
    rans[i] = ans[i%m];
  }
  wt_L(rans);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char rans[2d5+10];
// {
//     int @n, @k;
//     string ans;
//     rep(i,k){
//         ans += ('a'+i);
//         if(i == k-1) break;
//         ans += ('a'+i);
//         rep(j, i+1, k){
//             ans += 'a'+j;
//             if(j != k-1){
//                 ans += 'a'+i;
//             }
//         }
//     }
//     int m = ans.length();
//     rep(i,n){
//         rans[i] = ans[i%m];
//     }
//     wt(rans);
// }
// 

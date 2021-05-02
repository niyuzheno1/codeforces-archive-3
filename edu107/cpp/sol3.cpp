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
const int MN = 300000+10;
int n;
int q;
int a[MN];
int t[MN];
int ans[MN];
int pos[100];
int main(){
  int i;
  rd(n);
  rd(q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(n);Lj4PdHRW++){
      rd(a[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(q);e98WHCEY++){
      rd(t[e98WHCEY]);
    }
  }
  for(i=(0);i<(53);i++){
    pos[i] = -1;
  }
  for(i=(0);i<(n);i++){
    if(pos[a[i]] != -1){
      continue;
    }
    pos[a[i]] = i;
  }
  for(i=(0);i<(q);i++){
    int j;
    ans[i] = pos[t[i]]+1;
    if(pos[t[i]] == 0){
      continue;
    }
    int cpos = pos[t[i]];
    pos[t[i]] = 0;
    for(j=(0);j<(51);j++){
      if(pos[j] == -1){
        continue;
      }
      if(j == t[i]){
        continue;
      }
      if(pos[j] >= cpos){
        continue;
      }
      ++pos[j];
    }
  }
  {
    int hCmBdyQB;
    if(q==0){
      wt_L('\n');
    }
    else{
      for(hCmBdyQB=(0);hCmBdyQB<(q-1);hCmBdyQB++){
        wt_L(ans[hCmBdyQB]);
        wt_L(' ');
      }
      wt_L(ans[hCmBdyQB]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 3d5+10;
// int n, q, a[MN], t[MN], ans[MN];
// int pos[100];
// {
//     rd(n,q, a(n), t(q));
//     rep(i, 0, 53) pos[i] = -1;
//     rep(i, 0, n){
//         if(pos[a[i]] != -1) continue;
//         pos[a[i]] = i;
//     }
//     rep(i,0,q){
//         ans[i] = pos[t[i]]+1;
//         if(pos[t[i]] == 0) continue;
//         int cpos = pos[t[i]];
//         pos[t[i]] = 0;
//         rep(j,0,51){
//             if(pos[j] == -1) continue;
//             if(j == t[i]) continue;
//             if(pos[j] >= cpos) continue; 
//             ++pos[j];
//         }
//     }
//     wt(ans(q));
// }
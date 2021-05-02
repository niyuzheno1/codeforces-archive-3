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
const int MN = 1000;
int n;
int a[MN];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(n);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        rd(a[cTE1_r3A]);
      }
    }
    for(i=(0);i<(n);i++){
      a[i] = abs(a[i]);
    }
    for(i=(0);i<(n);i++){
      if(i & 1){
        a[i] = -a[i];
      }
    }
    {
      int ao_dF3pO;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(n-1);ao_dF3pO++){
          wt_L(a[ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(a[ao_dF3pO]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 1d3;
// int n, a[MN];
// {
//     REP(rd_int()){
//         rd(n,a(n));
//         rep(i,n) a[i] = abs(a[i]);
//         rep(i,n) if(i & 1) a[i] = -a[i];
//         wt(a(n));
//     }
// }
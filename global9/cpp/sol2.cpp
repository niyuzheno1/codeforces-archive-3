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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
const int MN = 310;
int a[MN][MN];
int n;
int m;
int b[MN][MN];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(n);
    rd(m);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(m);RZTsC2BF++){
          rd(a[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        b[i][j] = 4;
      }
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        if(i == 0 || i == n-1 || j == 0 || j == m-1){
          b[i][j] = 3;
        }
      }
    }
    b[0][m-1] = b[0][0] = 2;
    b[n-1][m-1] = b[n-1][0] = 2;
    bool possible = true;
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        if(b[i][j] < a[i][j]){
          possible = false;
        }
      }
    }
    if(!possible){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    {
      int AlM5nNnR;
      int XJIcIBrW;
      for(AlM5nNnR=(0);AlM5nNnR<(n);AlM5nNnR++){
        if(m==0){
          wt_L('\n');
        }
        else{
          for(XJIcIBrW=(0);XJIcIBrW<(m-1);XJIcIBrW++){
            wt_L(b[AlM5nNnR][XJIcIBrW]);
            wt_L(' ');
          }
          wt_L(b[AlM5nNnR][XJIcIBrW]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 310;
// int a[MN][MN], n, m;
// int b[MN][MN];
// {
//     REP(rd_int()){
//         rd(n,m, a(n,m));
//         rep(i,n) rep(j,m) b[i][j] = 4;
//         rep(i,n) rep(j,m) if(i == 0 || i == n-1 || j == 0 || j == m-1) b[i][j] = 3;
//         b[0][m-1] = b[0][0] = 2;
//         b[n-1][m-1] = b[n-1][0] = 2;
//         bool possible = true;
//         rep(i,n) rep(j,m) if(b[i][j] < a[i][j]) possible = false;
//         if(!possible) wt("NO"), continue;
//         wt("YES");
//         wt(b(n,m));
//     }
// }
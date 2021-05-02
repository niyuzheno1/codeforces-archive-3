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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
char a[410][410];
int minx;
int miny;
int maxx;
int maxy;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int n;
    rd(n);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        rd(a[cTE1_r3A]);
      }
    }
    minx = 1e9;
    miny = 1e9;
    maxx = 0;
    maxy = 0;
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n);j++){
        if(a[i][j] == '*'){
          chmin(minx, i);
          chmin(miny, j);
          chmax(maxx, i);
          chmax(maxy, j);
        }
      }
    }
    if(minx == maxx){
      if(minx == 0){
        a[n-1][miny] = '*';
        a[n-1][maxy] = '*';
      }
      else{
        a[0][miny] = '*';
        a[0][maxy] = '*';
      }
    }
    else if(miny == maxy){
      if(miny == 0){
        a[minx][n-1] = '*';
        a[maxx][n-1] = '*';
      }
      else{
        a[minx][0] = '*';
        a[maxx][0] = '*';
      }
    }
    else{
      a[minx][miny] = '*';
      a[minx][maxy] = '*';
      a[maxx][miny] = '*';
      a[maxx][maxy] = '*';
    }
    for(i=(0);i<(n);i++){
      wt_L(a[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char a[410][410];
// int minx, miny, maxx, maxy;
// {
//     REP(rd_int()){
//         int n;
//         rd(n,a(n));
//         minx = 1e9;
//         miny = 1e9;
//         maxx = 0;
//         maxy = 0;
//         rep(i,n) rep(j,n) if(a[i][j] == '*'){ minx <?= i; miny <?= j; maxx >?= i; maxy >?= j;}
//         if(minx == maxx){
//             if(minx == 0){
//                 a[n-1][miny] = '*';
//                 a[n-1][maxy] = '*';
// 
//             }else{
//                 a[0][miny] = '*';
//                 a[0][maxy] = '*';
// 
//             }
//         }else if(miny == maxy){
//             if(miny == 0){
//                 a[minx][n-1] = '*';
//                 a[maxx][n-1] = '*';
//             }else{
//                 a[minx][0] = '*';
//                 a[maxx][0] = '*';
//             }
//         }else{
//             a[minx][miny] = '*';
//             a[minx][maxy] = '*';
//             a[maxx][miny] = '*';
//             a[maxx][maxy] = '*';
//         }
//         rep(i,n) wt(a[i]);
//     }
// }
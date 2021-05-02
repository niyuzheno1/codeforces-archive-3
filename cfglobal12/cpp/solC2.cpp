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
int n;
char grid[310][310];
int main(){
  int Lj4PdHRW;
  rd(Tcases);
  for(Lj4PdHRW=(0);Lj4PdHRW<(Tcases);Lj4PdHRW++){
    int i;
    rd(n);
    for(i=(0);i<(n);i++){
      rd(grid[i]);
    }
    int b[3] = {0,0,0};
    int w[3] = {0,0,0};
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n);j++){
        if(grid[i][j] == 'X'){
          ++b[(i+j)%3];
        }
        if(grid[i][j] == 'O'){
          ++w[(i+j)%3];
        }
      }
    }
    int KrdatlYV;
    remove_reference<decltype(b[KrdatlYV])>::type ao_dF3pO;
    int tU__gIr_ = 0;
    int a2conNHc;
    if((0) > ((3)-1)){
      ao_dF3pO = 0;
    }
    else{
      for(KrdatlYV = 0; KrdatlYV <= (3)-1; KrdatlYV++){
        if(tU__gIr_ == 0){
          ao_dF3pO = b[KrdatlYV];
          a2conNHc = KrdatlYV;
          tU__gIr_ = 1;
          continue;
        }
        const auto hCmBdyQB = b[KrdatlYV];
        if(ao_dF3pO > hCmBdyQB){
          ao_dF3pO = hCmBdyQB;
          a2conNHc = KrdatlYV;
        }
      }
    }
    int idx1 = a2conNHc;
    int idx2 = -1;
    for(i=(0);i<(3);i++){
      if(i == idx1){
        continue;
      }
      if(idx2 == -1 || w[idx2] > w[i]){
        idx2 = i;
      }
    }
    int scheme1 = b[idx1] + w[idx2];
    int ZIeRIny5;
    remove_reference<decltype(w[ZIeRIny5])>::type iMWUTgY_;
    int AlM5nNnR = 0;
    int XJIcIBrW;
    if((0) > ((3)-1)){
      iMWUTgY_ = 0;
    }
    else{
      for(ZIeRIny5 = 0; ZIeRIny5 <= (3)-1; ZIeRIny5++){
        if(AlM5nNnR == 0){
          iMWUTgY_ = w[ZIeRIny5];
          XJIcIBrW = ZIeRIny5;
          AlM5nNnR = 1;
          continue;
        }
        const auto jPV_0s1p = w[ZIeRIny5];
        if(iMWUTgY_ > jPV_0s1p){
          iMWUTgY_ = jPV_0s1p;
          XJIcIBrW = ZIeRIny5;
        }
      }
    }
    int idx3 = XJIcIBrW;
    int idx4 = -1;
    for(i=(0);i<(3);i++){
      if(i == idx3){
        continue;
      }
      if(idx4 == -1 || b[idx4] > b[i]){
        idx4 = i;
      }
    }
    int scheme2 = w[idx3]+b[idx4];
    if(scheme1 > scheme2){
      idx1 = idx4;
      idx2 = idx3;
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n);j++){
        if((i+j)%3 == idx1 && grid[i][j] == 'X'){
          grid[i][j] = 'O';
        }
        else if((i+j)%3 == idx2 && grid[i][j] == 'O'){
          grid[i][j] = 'X';
        }
      }
    }
    for(i=(0);i<(n);i++){
      wt_L(grid[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int Tcases;
// int n;
// char grid[310][310];
// {
//     rd(Tcases);
//     rep(Tcases){
//         rd(n);
//         rep(i,n){
//             rd(grid[i]);
//         }
//         int b[3] = {0,0,0};
//         int w[3] = {0,0,0};
//         rep(i,n)
//         {
//             rep(j,n){
//                 if(grid[i][j] == 'X')
//                     ++b[(i+j)%3];
//                 if(grid[i][j] == 'O')
//                     ++w[(i+j)%3];
//             }
//         }
//         int idx1 = argmin(b(3));
//         int idx2 = -1;
//         rep(i,3){
//             if(i == idx1) continue;
//             if(idx2 == -1 || w[idx2] > w[i]) idx2 = i;
//         }
//         int scheme1 = b[idx1] + w[idx2];
//         int idx3 = argmin(w(3));
//         int idx4 = -1;
//         rep(i,3){
//             if(i == idx3) continue;
//             if(idx4 == -1 || b[idx4] > b[i]) idx4 = i;
//         }
//         int scheme2 = w[idx3]+b[idx4];
//         if(scheme1 > scheme2){
//             idx1 = idx4;
//             idx2 = idx3;
//         }
//        
//         rep(i,n)
//             rep(j,n){
//                 if((i+j)%3 == idx1 && grid[i][j] == 'X'){
//                     grid[i][j] = 'O';
//                 }
//                 else if((i+j)%3 == idx2 && grid[i][j] == 'O'){
//                     grid[i][j] = 'X';
//                 }
//             }
//         rep(i,n){
//             wt(grid[i]);
//         }
//     }
// }
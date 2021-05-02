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
int n;
int m;
const int MN = 200000+10;
char a[MN];
int allowed[300];
long long f[MN];
long long g[MN];
char b[MN];
int main(){
  int i;
  rd(n);
  rd(m);
  rd(a);
  for(i=(0);i<(m);i++){
    rd(b);
    allowed[b[0]] = 1;
  }
  for(i=(1);i<(n+1);i++){
    g[i] = g[i-1] + i;
  }
  long long ans = 0 ;
  for(i=(0);i<(n+1);i++){
    if(i == 0){
      f[i] = allowed[a[i]] ;
    }
    else{
      if(!allowed[a[i]]){
        ans += g[f[i-1]];
        f[i] = 0;
      }
      else{
        f[i] = f[i-1]+1;
      }
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n,m;
// const int MN = 2d5+10;
// char a[MN];
// int allowed[300];
// ll f[MN];
// ll g[MN];
// char b[MN];
// {
//     rd(n,m, a);
//     rep(i,m) rd(b), allowed[b[0]] = 1;
//     rep(i,1,n+1) g[i] = g[i-1] + i;
//     ll ans = 0 ;
//     rep(i,n+1){
//         if(i == 0){
//             f[i] = allowed[a[i]] ;
//         }else{
//             if(!allowed[a[i]]){
//                 
//                 ans += g[f[i-1]];
//                 f[i] = 0;
//             }else{
//                 f[i] = f[i-1]+1;
//             }
//         }
//     } 
//     wt(ans);
// }
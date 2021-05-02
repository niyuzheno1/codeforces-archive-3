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
inline void rd(long long &x){
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
long long pre[5100];
long long pos[5100];
long long a[5100];
long long b[5100];
long long n;
long long getpre(int x){
  return x < 0? 0 : pre[x];
}
long long getpos(int x){
  return x >= n? 0 : pos[x];
}
long long f[5100][5100];
long long rev(int x , int y){
  if(f[x][y]){
    return f[x][y];
  }
  long long& ret = f[x][y];
  if(x == y){
    return ret=a[x]*b[x];
  }
  if(x + 1 == y){
    return ret=(a[x]*b[y]) + a[y]*b[x];
  }
  return ret=rev(x+1,y-1) + a[x]*b[y] + a[y]*b[x];
}
int main(){
  int i;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(n);GIHf_YD2++){
      rd(b[GIHf_YD2]);
    }
  }
  for(i=(0);i<(n);i++){
    pre[i] = (i == 0? 0 : pre[i-1]) + a[i]*b[i];
  }
  for(i=(n)-1;i>=(0);i--){
    pos[i] = (i+1 == n? 0 : pos[i+1]) + a[i]*b[i];
  }
  long long ans = 0;
  for(i=(0);i<(n);i++){
    int j;
    for(j=(i);j<(n);j++){
      long long tmp = getpre(i-1) + getpos(j+1) + rev(i,j);
      chmax(ans, tmp);
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll pre[5100], pos[], a[], b[], n;
// ll getpre(int x){ return x < 0? 0 : pre[x];}
// ll getpos(int x){ return x >= n? 0 : pos[x];}
// ll f[5100][5100];
// ll rev(int x , int y){
//     if(f[x][y]) return f[x][y];
//     ll & ret = f[x][y];
//     if(x == y) return ret=a[x]*b[x];
//     if(x + 1 == y) return ret=(a[x]*b[y]) + a[y]*b[x];
//     return ret=rev(x+1,y-1) + a[x]*b[y] + a[y]*b[x];
// }
// {  
//     rd(n, a(n), b(n));
//     rep(i, n){
//         pre[i] = (i == 0? 0 : pre[i-1]) + a[i]*b[i];
//     }
//     rrep(i, n){
//         pos[i] = (i+1 == n? 0 : pos[i+1]) + a[i]*b[i];
//     }
//     ll ans = 0;
//     rep(i, n){
//         rep(j, i, n){
//             ll tmp = getpre(i-1) + getpos(j+1) + rev(i,j);
//             ans >?= tmp;
//         }
//     }
//     wt(ans);
// }
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
long long n;
long long m;
long long a[51][51];
long long col[2][51];
long long row[2][51];
int main(){
  int i, k;
  rd(n);
  rd(m);
  {
    int PiIOrLma;
    int AuJVIghY;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      for(AuJVIghY=(0);AuJVIghY<(m);AuJVIghY++){
        rd(a[PiIOrLma][AuJVIghY]);
      }
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(m);j++){
      ++col[a[i][j]][j];
      ++row[a[i][j]][i];
    }
  }
  long long ans = 0;
  for(k=(0);k<(2);k++){
    for(i=(0);i<(n);i++){
      ans += (1LL<<row[k][i]);
      --ans;
    }
  }
  for(k=(0);k<(2);k++){
    for(i=(0);i<(m);i++){
      ans += 1LL << col[k][i];
    }
    for(i=(0);i<(m);i++){
      ans -= col[k][i]+1LL;
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll n, m, a[51][51];
// ll col[2][51];
// ll row[2][51];
// {
//     rd(n,m,a(n,m));
//     rep(i,n) rep(j,m){
//             ++col[a[i][j]][j];
//             ++row[a[i][j]][i]; 
//     }
//     // rep(k, 2){
//     //     wt(col[k](m));
//     //     wt(row[k](n));
//     // }
//     ll ans = 0;
//     // count the row
//     rep(k, 2){
//         rep(i, n) ans += (1LL<<row[k][i]), --ans;
//     }
//     rep(k,2){
//         rep(i, m) ans += 1LL << col[k][i];
//         rep(i, m) ans -= col[k][i]+1LL;
//     }
//     wt(ans);
// }
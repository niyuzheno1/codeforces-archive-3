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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
long long b[5];
long long r[5];
int main(){
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(5);PiIOrLma++){
      rd(b[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(5);GIHf_YD2++){
      rd(r[GIHf_YD2]);
    }
  }
  int rbGYC8dh;
  long long NN9wFlop;
  if(5==0){
    NN9wFlop = 0;
  }
  else{
    NN9wFlop = b[0];
    for(rbGYC8dh=(1);rbGYC8dh<(5);rbGYC8dh++){
      NN9wFlop += b[rbGYC8dh];
    }
  }
  long long x = NN9wFlop+1;
  int zxsUT70f;
  long long VL854U43;
  if(5==0){
    VL854U43 = 0;
  }
  else{
    VL854U43 = r[0];
    for(zxsUT70f=(1);zxsUT70f<(5);zxsUT70f++){
      VL854U43 += r[zxsUT70f];
    }
  }
  long long y = VL854U43;
  if(x > y){
    wt_L("Blue");
    wt_L('\n');
  }
  else{
    wt_L("Red");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll b[5], r[5];
// {
//     rd(b(5), r(5));
//     ll x = sum(b(5))+1;
//     ll y = sum(r(5));
//     if(x > y) wt("Blue");
//     else wt("Red");
// }
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int n;
int k;
int a[300000+10];
int b[300000+10];
int c[300000+10];
int main(){
  int i;
  rd(n);
  rd(k);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  for(i=(0);i<(n);i++){
    c[i] = a[i];
  }
  for(i=(0);i<(n);i++){
    a[i] ^= 1;
  }
  a[n] = k+100;
  ++n;
  partial_sum(a,a+n, b);
  auto gr = [&] (int l, int r){
        if(l == 0) return b[r];
        return b[r]-b[l-1];
    };
  int ans = 0;
  int idx = 0;
  for(i=(0);i<(n-1);i++){
    int EZ0PmQmu;
    int zxsUT70f;
    int VL854U43;
    EZ0PmQmu = i;
    zxsUT70f = n;
    while(EZ0PmQmu < zxsUT70f){
      if((EZ0PmQmu + zxsUT70f)%2==0){
        VL854U43 = (EZ0PmQmu + zxsUT70f) / 2;
      }
      else{
        VL854U43 = (EZ0PmQmu + zxsUT70f + 1) / 2;
      }
      if(gr(i, VL854U43) <= k ){
        EZ0PmQmu = VL854U43;
      }
      else{
        zxsUT70f = VL854U43 - 1;
      }
    }
    int u =zxsUT70f;
    if(gr(i,u) > k){
      continue;
    }
    int len = u-i+1;
    chmax(ans, len);
    if(ans == len){
      idx = i;
    }
  }
  wt_L(ans);
  wt_L('\n');
  --n;
  for(i=(idx);i<(idx + ans);i++){
    c[i] = 1;
  }
  {
    int Btiq50RC;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(Btiq50RC=(0);Btiq50RC<(n-1);Btiq50RC++){
        wt_L(c[Btiq50RC]);
        wt_L(' ');
      }
      wt_L(c[Btiq50RC]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, k, a[3d5+10], b[3d5+10], c[3d5+10]; 
// {
//     rd(n, k, a(n));
//     rep(i,n) c[i] = a[i];
//     rep(i,n) a[i] ^= 1;
//     
//     a[n] = k+100;
//     ++n;
//     partial_sum(a,a+n, b);
//     auto gr = [&] (int l, int r){
//         if(l == 0) return b[r];
//         return b[r]-b[l-1];
//     };
//     int ans = 0,  idx = 0;
//     rep(i, n-1){
//         int u =bsearch_max[int, md, i, n](gr(i, md) <= k );
//         if(gr(i,u) > k) continue;
//         int len = u-i+1;
//         ans >?= len;
//         if(ans == len) idx = i;
//     }
//     wt(ans);
//     --n;
//     rep(i, idx, idx + ans) c[i] = 1;
//     wt(c(n));
// }
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
template<class T> int Factor_L(T N, T fac[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    N /= 2;
    while(N%2==0){
      N /= 2;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      N /= i;
      while(N%i==0){
        N /= i;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct IntMap{
  int n;
  int mem;
  int logn;
  int*dat;
  int**nx;
  int calc_nx;
  int numCycle;
  int*cycleLen;
  int**cycle;
  int*int2c;
  int*int2cInd;
  IntMap(){
    n = mem = logn = 0;
    calc_nx = 0;
    numCycle = 0;
  }
  IntMap(int nn){
    n = mem = nn;
    for(logn=0; (1<<logn)<n; logn++){
      ;
    }
    logn++;
    if(mem > 0){
      dat = new int[mem];
    }
    calc_nx = 0;
    numCycle = 0;
  }
  ~IntMap(){
    if(mem){
      delete[] dat;
    }
    if(calc_nx){
      int i;
      for(i=(0);i<(logn);i++){
        delete[] nx[i];
      }
      delete[] nx;
    }
    if(numCycle > 0){
      int i;
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
    }
  }
  void changeSize(const int nn){
    int old_logn = logn;
    n = nn;
    for(logn=0; (1<<logn)<n; logn++){
      ;
    }
    logn++;
    if(mem < n){
      if(mem){
        delete [] dat;
      }
      mem = n;
      dat = new int [mem];
    }
    if(calc_nx){
      int i;
      for(i=(0);i<(old_logn);i++){
        delete[] nx[i];
      }
      delete[] nx;
      calc_nx = 0;
    }
    if(numCycle > 0){
      int i;
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
      numCycle = 0;
    }
  }
  int calcCycle(void){
    int i;
    int j;
    int k;
    if(numCycle){
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
      numCycle = 0;
    }
    int2c = new int[n];
    int2cInd = new int[n];
    for(i=(0);i<(n);i++){
      int2c[i] = -2;
    }
    for(i=(0);i<(n);i++){
      int2cInd[i] = -1;
    }
    numCycle = 0;
    for(i=(0);i<(n);i++){
      if(int2c[i] == -2){
        j = i;
        for(;;){
          if(int2c[j] != -2){
            break;
          }
          int2c[j] = -3;
          j = dat[j];
        }
        if(int2c[j] == -3){
          k = 0;
          for(;;){
            if(int2c[j] != -3){
              break;
            }
            int2c[j] = numCycle;
            int2cInd[j] = k++;
            j = dat[j];
          }
          numCycle++;
        }
        j = i;
        for(;;){
          if(int2c[j] != -3){
            break;
          }
          int2c[j] = -1;
          j = dat[j];
        }
      }
    }
    cycleLen = new int[numCycle];
    for(i=(0);i<(numCycle);i++){
      cycleLen[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(int2c[i] >= 0){
        cycleLen[int2c[i]]++;
      }
    }
    cycle = new int*[numCycle];
    for(i=(0);i<(numCycle);i++){
      cycle[i] = new int[cycleLen[i]];
    }
    for(i=(0);i<(n);i++){
      if(int2c[i] >= 0){
        cycle[int2c[i]][int2cInd[i]] = i;
      }
    }
    return numCycle;
  }
  void calcNext(int recalc = 1){
    int i, k;
    if(recalc || numCycle==0){
      calcCycle();
    }
    if(calc_nx == 0){
      int i;
      calc_nx = 1;
      nx = new int*[logn];
      for(i=(0);i<(logn);i++){
        nx[i] = new int[n];
      }
    }
    for(i=(0);i<(n);i++){
      nx[0][i] = dat[i];
    }
    for(k=(1);k<(logn);k++){
      for(i=(0);i<(n);i++){
        nx[k][i] = nx[k-1][nx[k-1][i]];
      }
    }
  }
  template<class T> int getNext(int x, T s){
    int i;
    if(calc_nx==0){
      calcNext();
    }
    if(s >= (1<<(logn-1))){
      x = nx[logn-1][x];
      s -= (1<<(logn-1));
      return cycle[int2c[x]][(int2cInd[x]+s)%cycleLen[int2c[x]]];
    }
    for(i=(0);i<(logn);i++){
      if(s&1<<i){
        x = nx[i][x];
      }
    }
    return x;
  }
  inline int& operator[](const int a){
    return dat[a];
  }
}
;
#include <cstring>
int n;
int q;
int a[100000+20];
int que[100000+10][2];
int fs[100000+20];
int fsz;
int closest[100000+20];
int main(){
  int i;
  rd(n);
  rd(q);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(a[PiIOrLma]);
    }
  }
  {
    int GIHf_YD2;
    int djQeACzd;
    for(GIHf_YD2=(0);GIHf_YD2<(q);GIHf_YD2++){
      for(djQeACzd=(0);djQeACzd<(2);djQeACzd++){
        rd(que[GIHf_YD2][djQeACzd]);
      }
    }
  }
  IntMap f(n+2);
  memset(closest, 0xff, sizeof(closest));
  for(i=(0);i<(n+2);i++){
    f[i] = n;
  }
  for(i=(n)-1;i>=(0);i--){
    int j;
    fsz =Factor_L( a[i], fs);
    for(j=(0);j<(fsz);j++){
      int x = fs[j];
      if(closest[x] != -1){
        chmin(f[i], closest[x]);
      }
      closest[x] = i;
    }
  }
  for(i=(n)-1;i>=(0);i--){
    chmin(f[i], f[i+1]);
  }
  for(i=(0);i<(q);i++){
    int l;
    int r;
    auto Y0H_suZr = ((que[i][0]-1));
    auto Q7E_c5bj = ((que[i][1]));
    l=Y0H_suZr;
    r=Q7E_c5bj;
    int oGwDY68s;
    int WpmOCj1U;
    int cDHiUAlz;
    oGwDY68s = 0;
    WpmOCj1U = 100000+1;
    while(oGwDY68s < WpmOCj1U){
      if((oGwDY68s + WpmOCj1U)%2==0){
        cDHiUAlz = (oGwDY68s + WpmOCj1U) / 2;
      }
      else{
        cDHiUAlz = (oGwDY68s + WpmOCj1U + 1) / 2;
      }
      if(f.getNext(l,cDHiUAlz) < r){
        oGwDY68s = cDHiUAlz;
      }
      else{
        WpmOCj1U = cDHiUAlz - 1;
      }
    }
    int cnt =WpmOCj1U;
    wt_L(cnt+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// #include <cstring>
// int n, q;
// int a[1d5+20];
// int que[1d5+10][2];
// int fs[1d5+20], fsz;
// int closest[1d5+20];
// {
//     
//     rd(n, q, a(n), que(q, 2));
//     IntMap f(n+2);
//     memset(closest, 0xff, sizeof(closest));
//     rep(i, n+2) f[i] = n;
//     rrep(i, n){
//         fsz = Factor( a[i], fs);
//         rep(j, fsz){
//             int x = fs[j];
//             if(closest[x] != -1) f[i] <?= closest[x];
//             closest[x] = i;
//         }
//     }
//     rrep(i,n) f[i] <?= f[i+1];
//     rep(i, q){
//         int l,r;
//         (l,r) = (que[i][0]-1,que[i][1]);
//         int cnt = bsearch_max[int, k, 0 ,1d5+1] (f.getNext(l,k) < r);
//         wt(cnt+1);
//     }
// }
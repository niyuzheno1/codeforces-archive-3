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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
const int MN = 100000+10;
int dll[MN];
int nxt[MN];
int pre[MN];
int n;
int a[MN];
int ap[MN];
int q[MN];
int rdx[MN];
int qtot;
int ans[MN];
int atot;
int dbg = 0;
void del(int x){
  a[x] = 0;
  int u = nxt[x];
  int v = pre[x];
  nxt[v] = u;
  pre[u] = v;
}
void push(int x, int y){
  arrInsert(qtot, qtot, q, x, rdx, y);
}
void pusha(int x){
  arrInsert(atot, atot, ans, x+1);
}
void init_t(){
  int i;
  qtot = atot = 0;
  for(i=(0);i<(n);i++){
    pre[i] = i-1;
    nxt[i] = i + 1;
  }
  nxt[n-1] = 0;
  pre[0] = n-1;
}
int main(){
  int T;
  int Tcases;
  rd(Tcases);
  int cntn = 0;
  int Q5VJL1cS = Tcases;
  for(T=(0);T<(Q5VJL1cS);T++){
    rd(n);
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(n);RZTsC2BF++){
        rd(a[RZTsC2BF]);
      }
    }
    if(dbg){
      int i;
      for(i=(0);i<(n);i++){
        ap[i] = a[i];
      }
    }
    init_t();
    int i = 0;
    while(i < n){
      int ci = i;
      if(GCD_L(a[i], a[nxt[i]])== 1){
        push(nxt[i], 0);
        i = nxt[nxt[i]];
        if(i <= ci){
          rdx[qtot-1] = 1;
          break;
        }
      }
      else{
        i = nxt[i];
        if(i <= ci){
          break;
        }
      }
    }
    int np = -10;
    int nrd = 0;
    int lowl = 0;
    for(i=(0);i<(qtot);i++){
      int x = q[i];
      int crd = rdx[i];
      if(GCD_L(a[pre[x]], a[x])!= 1){
        continue;
      }
      if( (x == np && crd <= nrd) ){
        continue;
      }
      pusha(x);
      del(x);
      np = nxt[x];
      chmax(nrd, crd);
      if(GCD_L(a[pre[x]], a[nxt[x]])== 1){
        if(nxt[x] < x){
          push(nxt[x], nrd+2);
          ++ nrd;
        }
        else{
          push(nxt[x], nrd+1);
        }
      }
    }
    if(dbg == 0){
      wt_L(atot);
      wt_L(' ');
      {
        int YREPHmFM;
        if(atot==0){
          wt_L('\n');
        }
        else{
          for(YREPHmFM=(0);YREPHmFM<(atot-1);YREPHmFM++){
            wt_L(ans[YREPHmFM]);
            wt_L(' ');
          }
          wt_L(ans[YREPHmFM]);
          wt_L('\n');
        }
      }
    }
    else{
      cntn += atot + 1;
      if(cntn >=  214){
        wt_L(n);
        wt_L(' ');
        {
          int ZIeRIny5;
          if(n==0){
            wt_L('\n');
          }
          else{
            for(ZIeRIny5=(0);ZIeRIny5<(n-1);ZIeRIny5++){
              wt_L(ap[ZIeRIny5]);
              wt_L(' ');
            }
            wt_L(ap[ZIeRIny5]);
            wt_L('\n');
          }
        }
        return 0;
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5+10;
// int dll[MN];
// int nxt[MN],pre[MN], n, a[MN], ap[MN];
// int q[MN], rdx[MN], qtot, ans[MN], atot;
// int dbg = 0;
// void del(int x){
//     a[x] = 0;
//     int u = nxt[x], v = pre[x];
//     nxt[v] = u;
//     pre[u] = v;
// }
// void push(int x, int y){
//     arrInsert(qtot, qtot, q, x, rdx, y);
// }
// 
// void pusha(int x){
//     arrInsert(atot, atot, ans, x+1);
// }
// void init_t(){
//     qtot = atot = 0;
//     rep(i, n) pre[i] = i-1, nxt[i] = i + 1;
//     nxt[n-1] = 0;
//     pre[0] = n-1;
// }
// {
//     int @Tcases;
//     //if(Tcases > 50) dbg = 1;
//     int cntn = 0;
//     REP(T,Tcases){
//         rd(n, a(n));
//         if(dbg){
//             rep(i,n){
//                 ap[i] = a[i];
//             }
//         }
//         init_t();
//         
//         int i = 0;
//         while(i < n){
//             int ci = i;
//             if(gcd(a[i], a[nxt[i]]) == 1) {
//                 push(nxt[i], 0);
//                 i = nxt[nxt[i]];
//                 if(i <= ci) rdx[qtot-1] = 1, break;
//             }else{
//                 i = nxt[i];
//                 if(i <= ci) break;
//             }
//         }
//         int np = -10, nrd = 0, lowl = 0;
//         rep(i, qtot){
//             int x = q[i], crd = rdx[i];
//             //if(x == 7) __asm int 3;
//             if( gcd(a[pre[x]], a[x]) != 1)  continue;
//             if( (x == np && crd <= nrd) ){
//                 //np = -10;
//                 //push(x, crd+1);
//                 continue;
//             }
//             pusha(x);
//             del(x);
//             np = nxt[x];
//             nrd >?= crd;
//             if(gcd(a[pre[x]],a[nxt[x]]) == 1){
//                 if(nxt[x] < x) {
//                     
//                     push(nxt[x], nrd+2);
//                     ++ nrd;
//                 }
//                 else
//                     push(nxt[x], nrd+1);
//             }
//         }
//         if(dbg == 0){
//             wt(atot, ans(atot));
//         }else{
//             cntn += atot + 1;
//             if(cntn >=  214){
//                 wt(n, ap(n));
//                 return 0;
//             }
//         }
//     }
// }
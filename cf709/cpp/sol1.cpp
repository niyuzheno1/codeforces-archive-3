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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
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
const int MN = 100000+10;
const int MM = 200000+10;
int f[MN];
int a[MM];
int ans[MN];
int l[MN];
int r[MN];
int c[MN];
int tot;
int tota;
int n ;
int m;
void push(int x){
  arrInsert(tot,tot, a, x);
}
void pusha(int x){
  arrInsert(tota,tota, ans,x);
}
void clr(){
  int i;
  for(i=(0);i<(tot);i++){
    f[a[i]] = 0;
  }
}
int main(){
  int T;
  int Q5VJL1cS = rd_int();
  for(T=(0);T<(Q5VJL1cS);T++){
    int i;
    tot = 0;
    tota = 0;
    rd(n);
    rd(m);
    for(i=(0);i<(m);i++){
      int j;
      int k;
      rd(k);
      l[i] = 1e9;
      r[i] = 0;
      for(j=(0);j<(k);j++){
        int x;
        rd(x);
        chmin(l[i], tot);
        chmax(r[i], tot);
        push(x);
      }
      ++r[i];
    }
    for(i=(0);i<(m);i++){
      ++f[a[l[i]]];
      c[i] = l[i];
    }
    for(i=(0);i<(m);i++){
      int j = l[i]+1;
      while(f[a[c[i]]]  > ((divup_L(m,2))) && j < r[i] ){
        --f[a[c[i]]];
        ++f[a[j]];
        c[i] = j;
        ++j;
      }
    }
    bool flag = true;
    for(i=(0);i<(m);i++){
      int j;
      for(j=(l[i]);j<(r[i]);j++){
        if(f[a[j]] > ((divup_L(m,2)))){
          flag = false;
        }
      }
    }
    if(!flag){
      wt_L("NO");
      wt_L('\n');
      clr();
      continue;
    }
    for(i=(0);i<(m);i++){
      pusha(a[c[i]]);
    }
    wt_L("YES");
    wt_L('\n');
    {
      int iMWUTgY_;
      if(m==0){
        wt_L('\n');
      }
      else{
        for(iMWUTgY_=(0);iMWUTgY_<(m-1);iMWUTgY_++){
          wt_L(ans[iMWUTgY_]);
          wt_L(' ');
        }
        wt_L(ans[iMWUTgY_]);
        wt_L('\n');
      }
    }
    clr();
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5+10;
// const int MM = 2d5+10;
// int f[MN];
// int a[MM], ans[MN];
// int l[MN], r[MN], c[MN];
// int tot,tota, n , m;
// void push(int x){
//     arrInsert(tot,tot, a, x);
// }
// void pusha(int x){
//     arrInsert(tota,tota, ans,x);
// }
// 
// void clr(){
//     rep(i,tot)  f[a[i]] = 0;
// }
// 
// {
//     REP(T,rd_int()){
//         //if(T == 5){ __asm int 3;}
//         tot = 0;
//         tota = 0;
//         rd(n,m);
//         rep(i,m){
//             int @k;
//             l[i] = 1e9, r[i] = 0;
//             rep(j,k){
//                 int @x;
//                 l[i] <?= tot;
//                 r[i] >?= tot;
//                 push(x);
//             }
//             ++r[i];
//         }
//         rep(i,m) ++f[a[l[i]]], c[i] = l[i];
//         rep(i,m){
//             int j = l[i]+1;
//             while(f[a[c[i]]]  > (m /+ 2) && j < r[i] ){
//                 --f[a[c[i]]];
//                 ++f[a[j]];
//                 c[i] = j;
//                 ++j;
//             }
//         }
//         bool flag = true;
//         rep(i,m) rep(j, l[i],r[i]) if(f[a[j]] > (m/+2)) flag = false;
//         if(!flag) wt("NO"),clr(), continue;
//         rep(i,m) pusha(a[c[i]]);
//         wt("YES");
//         wt(ans(m));
//         clr();       
//         
//     }
// }
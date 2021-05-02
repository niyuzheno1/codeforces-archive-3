#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
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
int n;
int a[110];
int idx[110];
const int MS = 110*2100;
bitset<MS> t;
void process(bitset<MS> & x ){
  int i;
  x.reset();
  x[0] = 1;
  for(i=(0);i<(n);i++){
    x |= (x << a[i]);
  }
}
void process(bitset<MS> & x,int skip){
  int i;
  x.reset();
  x[0] = 1;
  for(i=(0);i<(n);i++){
    if(i != skip){
      x |= (x << a[i]);
    }
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int djQeACzd;
    for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
      rd(a[djQeACzd]);
    }
  }
  for(i=(0);i<(n);i++){
    idx[i] = i+1;
  }
  sortA_L(n,a, idx);
  process(t);
  int EZ0PmQmu;
  int zxsUT70f;
  if(n==0){
    zxsUT70f = 0;
  }
  else{
    zxsUT70f = a[0];
    for(EZ0PmQmu=(1);EZ0PmQmu<(n);EZ0PmQmu++){
      zxsUT70f += a[EZ0PmQmu];
    }
  }
  int u = zxsUT70f;
  if(u % 2 == 1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  if(t[u>>1]){
    int ret = 0;
    for(i=(0);i<(n);i++){
      int v = u - a[i];
      if( v % 2 == 1){
        ret = idx[i];
        break;
      }
      process(t, i);
      if(t[v >> 1] == 0){
        ret = idx[i];
        break;
      }
    }
    wt_L(1);
    wt_L('\n');
    wt_L(ret);
    wt_L('\n');
  }
  else{
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// int a[110], idx[110];
// const int MS = 110*2100;
// bitset<MS> t;
// void process(bitset<MS> & x ){
//     x.reset();
//     x[0] = 1;
//     rep(i, 0, n) x |= (x << a[i]);
// }
// void process(bitset<MS> & x,int skip){
//     x.reset();
//     x[0] = 1;
//     rep(i, 0, n) if(i != skip) x |= (x << a[i]);
// }
// 
// {
//     rd(n, a(n));
//     rep(i, n) idx[i] = i+1;
//     sortA(n,a, idx);
//     process(t);
//     int u = sum(a(n));
//     if(u % 2 == 1){
//         wt(0);
//         return 0;
//     }
//     if(t[u>>1]){
//         int ret = 0;
//         rep(i,n){
//             int v = u - a[i];
//             if( v % 2 == 1) {ret = idx[i]; break;}
//             process(t, i);
//             if(t[v >> 1] == 0){
//                 ret = idx[i];
//                 break;
//             }
//             
//         }
//         wt(1);
//         wt(ret);
//     }else{
//         wt(0);
//         return 0;
//     }
// }
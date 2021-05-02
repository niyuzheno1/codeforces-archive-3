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
int n;
long long u[400000];
long long s[400000];
long long pre[400000];
long long stp[400000];
long long ed[400000];
long long len[400000];
long long ans[400000];
vector<int> b;
long long rang(int x, int y){
  if( x > y){
    return 0;
  }
  if(x == 0){
    return pre[y];
  }
  return pre[y] - pre[x-1];
}
int main(){
  int PiIOrLma;
  wmem = memarr;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int asz, i;
    b.clear();
    rd(n);
    {
      int djQeACzd;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        rd(u[djQeACzd]);
      }
    }
    {
      int NN9wFlop;
      for(NN9wFlop=(0);NN9wFlop<(n);NN9wFlop++){
        rd(s[NN9wFlop]);
      }
    }
    for(i=(0);i<(n);i++){
      s[i] = -s[i];
    }
    sortA_L(n, u, s);
    for(i=(0);i<(n);i++){
      s[i] = -s[i];
    }
    for(i=(0);i<(n);i++){
      pre[i] = (i==0? 0 : pre[i-1]) + s[i];
    }
    for(i=(0);i<(n+1);i++){
      len[i] = 0;
      ed[i] = -1;
      stp[i] = 1073709056;
    }
    for(i=(0);i<(n);i++){
      chmin(stp[u[i]], i);
      chmax(ed[u[i]], i);
      ++len[u[i]];
    }
    for(i=(0);i<(n+1);i++){
      if(stp[i] != 1073709056){
        b.push_back(i);
      }
    }
    long long permsum = 0;
    for(asz=(0);asz<(n);asz++){
      int a3PBjchb;
      int k = asz+1;
      auto tmpans = pre[n-1];
      int bsz = b.size();
      tmpans -= permsum;
      for(a3PBjchb=(0);a3PBjchb<(bsz);a3PBjchb++){
        auto&i = b[a3PBjchb];
        int tmp = len[i] % k;
        tmpans -= rang(ed[i]-tmp+1, ed[i]);
      }
      for(i=(0);i<(b.size());i++){
        int x = b[i];
        if(k > len[x]){
          b.erase(b.begin() + i);
          permsum += rang(stp[x], ed[x]);
          --i;
        }
      }
      ans[asz] = tmpans;
    }
    {
      int LiLe88qh;
      if(n==0){
        wt_L('\n');
      }
      else{
        for(LiLe88qh=(0);LiLe88qh<(n-1);LiLe88qh++){
          wt_L(ans[LiLe88qh]);
          wt_L(' ');
        }
        wt_L(ans[LiLe88qh]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// ll u[4d5],s[];
// ll pre[], stp[], ed[], len[], ans[];
// 
// vector<int> b;
// ll rang(int x, int y){
//     if( x > y) return 0;
//     if(x == 0) return pre[y];
//     return pre[y] - pre[x-1];
// } 
// {
//     REP(rd_int()){
//         b.clear();
//         rd(n, u(n), s(n));
//         rep(i, n) s[i] = -s[i];
//         sortA(n, u, s);
//         rep(i, n) s[i] = -s[i];
//         rep(i, n) pre[i] = (i==0? 0 : pre[i-1]) + s[i];
//         rep(i, n+1) len[i] = 0, ed[i] = -1, stp[i] = int_inf;
//         rep(i, n) stp[u[i]] <?= i, ed[u[i]] >?= i, ++len[u[i]];
//         rep(i, n+1) if(stp[i] != int_inf) b.push_back(i);
//         ll permsum = 0;
//         rep(asz, n){
//             int k = asz+1;
//             auto tmpans = pre[n-1];
//             int bsz = b.size();
//             tmpans -= permsum;
//             rep[b](i,bsz){
//                 int tmp = len[i] % k;
//                 tmpans -= rang(ed[i]-tmp+1, ed[i]);
//             }
//             rep(i, b.size()){
//                 int x = b[i];
//                 if(k > len[x]){
//                     b.erase(b.begin() + i);
//                     
//                     permsum += rang(stp[x], ed[x]);
//                     --i;
//                 }
//             }
//             ans[asz] = tmpans;
//         }
//         wt(ans(n));
//     }
// }
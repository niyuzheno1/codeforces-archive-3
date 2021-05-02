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
int b[110][110];
int L[110];
int R[110];
int ans[110][110];
int cnt[110];
#define mp make_pair
#define pq_type priority_queue<pair<int,int> >
#define X first
#define Y second
int main(){
  int PiIOrLma;
  wmem = memarr;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    int n;
    rd(n);
    int m;
    rd(m);
    {
      int djQeACzd;
      int Z8lEHcvz;
      for(djQeACzd=(0);djQeACzd<(n);djQeACzd++){
        for(Z8lEHcvz=(0);Z8lEHcvz<(m);Z8lEHcvz++){
          rd(b[djQeACzd][Z8lEHcvz]);
        }
      }
    }
    for(i=(0);i<(n);i++){
      R[i] = m-1;
      L[i] = 0;
    }
    pq_type pq;
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(m);j++){
        pq.push(mp(-b[i][j],i));
      }
    }
    for(i=(0);i<(n);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(n);i++){
      sortA_L(m, b[i]);
    }
    while(!pq.empty()){
      int j;
      auto y = pq.top();
      pq.pop();
      auto x = mp(-y.X, y.Y);
      int i = x.Y;
      if(L[i] > R[i]){
        continue;
      }
      ans[i][cnt[i]] = x.X;
      ++ cnt[i];
      ++ L[i];
      for(j=(0);j<(n);j++){
        if(j != i){
          ans[j][cnt[j]]=b[j][R[j]];
          ++cnt[j];
          --R[j];
        }
      }
    }
    for(i=(0);i<(n);i++){
      {
        int waYUWM6f;
        if(m==0){
          wt_L('\n');
        }
        else{
          for(waYUWM6f=(0);waYUWM6f<(m-1);waYUWM6f++){
            wt_L(ans[i][waYUWM6f]);
            wt_L(' ');
          }
          wt_L(ans[i][waYUWM6f]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int b[110][110];
// int L[110], R[110];
// int ans[110][110];
// int cnt[110];
// #define mp make_pair
// #define pq_type priority_queue<pair<int,int> >
// #define X first
// #define Y second
// {
//     REP(rd_int()){
//         int @n, @m;
//         rd(b(n,m));
//         rep(i, n) R[i] = m-1, L[i] = 0;
//         pq_type pq;
//         rep(i, n) rep(j,m) pq.push(mp(-b[i][j],i));
//         rep(i, n) cnt[i] = 0;
//         rep(i, n) sortA(m, b[i]);
//         while(!pq.empty()){
//             auto y = pq.top(); pq.pop();
//             auto x = mp(-y.X, y.Y);
//             int i = x.Y;
//             if(L[i] > R[i]) continue;
//             ans[i][cnt[i]] = x.X; ++ cnt[i]; ++ L[i];
//             rep(j, n) if(j != i) ans[j][cnt[j]]=b[j][R[j]], ++cnt[j], --R[j];
//         }
//         rep(i,n) wt(ans[i](m));
//     }
// }
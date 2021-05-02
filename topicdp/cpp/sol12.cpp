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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
#define pii pair<int,int>
#define mp make_pair
int n;
int k;
int c[1000+10];
int p[1000+10];
int idxc[1000+10];
int idxt[1000+10];
int r[1000+10];
int dp[1000+10][1000+10];
pii dir[1000+10][1000+10];
int ans[1000+10][2];
int asz;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  {
    int PiIOrLma;
    for(PiIOrLma=(0);PiIOrLma<(n);PiIOrLma++){
      rd(c[PiIOrLma]);
      rd(p[PiIOrLma]);
    }
  }
  rd(k);
  {
    int GIHf_YD2;
    for(GIHf_YD2=(0);GIHf_YD2<(k);GIHf_YD2++){
      rd(r[GIHf_YD2]);
    }
  }
  iota(idxc, idxc+n, 1);
  iota(idxt, idxt+k, 1);
  sortA_L(n, c, p, idxc );
  sortA_L(k, r, idxt);
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(k);j++){
      dir[i][j] = mp(-1,-1);
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(k);j++){
      if(c[i] <= r[j]){
        chmax(dp[i+1][j+1], dp[i][j] + p[i]);
        if(dp[i+1][j+1] == dp[i][j] + p[i]){
          dir[i+1][j+1] = mp(i,j);
        }
      }
      chmax(dp[i+1][j], dp[i][j]);
      if(dp[i+1][j] == dp[i][j]){
        dir[i+1][j] = mp(i,j);
      }
      chmax(dp[i][j+1], dp[i][j]);
      if(dp[i][j+1] == dp[i][j]){
        dir[i][j+1] = mp(i,j);
      }
    }
  }
  int x = 0;
  int y = 0;
  for(i=(0);i<(n+1);i++){
    int j;
    for(j=(0);j<(k+1);j++){
      if(dp[x][y] < dp[i][j]){
        x = i;
        y = j;
      }
    }
  }
  int _x = x;
  int _y = y;
  while(x != -1 && y != -1){
    int nx;
    int ny;
    auto Q7E_c5bj = ((dir[x][y].first));
    auto oGwDY68s = (( dir[x][y].second ));
    nx=Q7E_c5bj;
    ny=oGwDY68s;
    if(x > nx && y > ny){
      if( (idxc[nx], idxt[ny]) == (0, 0)){
        break;
      }
      ans[asz][0] = idxc[nx];
      ans[asz][1] = idxt[ny];
      ++asz;
    }
    auto WpmOCj1U = ((nx));
    auto cDHiUAlz = (( ny));
    x=WpmOCj1U;
    y=cDHiUAlz;
  }
  x = _x;
  y = _y;
  wt_L(asz);
  wt_L(' ');
  wt_L(dp[x][y]);
  wt_L('\n');
  for(i=(0);i<(asz);i++){
    wt_L(ans[i][0]);
    wt_L(' ');
    wt_L(ans[i][1]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// #define pii pair<int,int>
// #define mp make_pair
// int n, k, c[1d3+10], p[], idxc[], idxt[], r[];
// int dp[1d3+10][1d3+10];
// pii dir[1d3+10][1d3+10];
// int ans[1d3+10][2], asz;
// 
// {
//     rd(n, (c,p)(n), k, r(k));
//     iota(idxc, idxc+n, 1);
//     iota(idxt, idxt+k, 1);
//     sortA(n, c, p, idxc ); sortA(k, r, idxt);
//     rep(i, 0, n) rep(j, 0, k) dir[i][j] = mp(-1,-1);
//     rep(i, 0, n){
//         rep(j, 0, k){
//             if(c[i] <= r[j]){
//                 dp[i+1][j+1] >?= dp[i][j] + p[i];
//                 if(dp[i+1][j+1] == dp[i][j] + p[i]){
//                     dir[i+1][j+1] = mp(i,j);
//                 }
//             }
//             dp[i+1][j] >?= dp[i][j];
//             if(dp[i+1][j] == dp[i][j]) dir[i+1][j] = mp(i,j);
//             dp[i][j+1] >?= dp[i][j];
//             if(dp[i][j+1] == dp[i][j]) dir[i][j+1] = mp(i,j);
//         }
//     }
//     int x = 0, y = 0;
//     rep(i, n+1) rep(j, k+1) if(dp[x][y] < dp[i][j]){
//         x = i;
//         y = j;
//     }
//     int _x = x, _y = y;
//     while(x != -1 && y != -1){
//         int nx, ny;
//         (nx, ny) = (dir[x][y].first, dir[x][y].second );
//         if(x > nx && y > ny){
//             if( (idxc[nx], idxt[ny]) == (0, 0)) break;
//             
//             ans[asz][0] = idxc[nx];
//             ans[asz][1] = idxt[ny];
//             ++asz;
//         }
//         (x,y) = (nx, ny);
//     }
//     x = _x; y = _y;
//     wt(asz, dp[x][y]);
//     rep(i, asz) wt(ans[i][0], ans[i][1]);
// }

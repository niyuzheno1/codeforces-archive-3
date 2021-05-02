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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
long long vis[100000+30];
long long a[100000+30];
long long b[100000+30];
long long c[100000+30];
long long d[100000+30];
long long dsz;
long long sz;
long long n;
long long cnt(){
  int i;
  long long scores = 0;
  for(i=(0);i<(dsz);i++){
    scores += a[d[i]-1];
  }
  for(i=(0);i<(dsz);i++){
    int j;
    for(j=(0);j<(dsz);j++){
      int k;
      if(i == j){
        continue;
      }
      bool sub = false;
      long long tmp = 1;
      for(k=(0);k<(35);k++){
        tmp *= d[i];
        if(tmp > n){
          break;
        }
        if(tmp == d[j]){
          sub = true;
        }
      }
      if(sub){
        scores -= b[d[j]-1];
      }
    }
  }
  return scores;
}
long long binenum(){
  int i;
  long long ans = 0;
  for(i=(0);i<(1<<sz);i++){
    int j;
    dsz = 0;
    for(j=(0);j<(sz);j++){
      if( (i>>j) & 1){
        d[dsz] = c[j];
        dsz++;
      }
    }
    long long r1 = cnt();
    chmax(ans, r1);
  }
  return ans;
}
int main(){
  int i;
  rd(n);
  {
    int Yd8JT4OW;
    for(Yd8JT4OW=(0);Yd8JT4OW<(n);Yd8JT4OW++){
      rd(a[Yd8JT4OW]);
    }
  }
  {
    int o8AZ1iEn;
    for(o8AZ1iEn=(0);o8AZ1iEn<(n);o8AZ1iEn++){
      rd(b[o8AZ1iEn]);
    }
  }
  for(i=(2);i<(n);i++){
    if(i * i > n){
      break;
    }
    long long j = i * i;
    while(j <= n){
      vis[j] = 1;
      j *= i;
    }
  }
  long long ans = a[0];
  for(i=(2);i<(n+1);i++){
    if(vis[i]){
      continue;
    }
    if(i * i <= n){
      sz = 0;
      long long j = i;
      while(j <= n){
        c[sz++] = j;
        j *= i;
      }
      ans += binenum();
    }
    else{
      ans += a[i-1];
    }
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll vis[1d5+30], a[], b[], c[], d[], dsz, sz, n;
// ll cnt(){
//     ll scores = 0;
//     rep(i, dsz) scores += a[d[i]-1];
//     rep(i, dsz){
//         rep(j, dsz){
//             if(i == j) continue;
//             bool sub = false;
//             ll tmp = 1;
//             rep(k, 0, 35){
//                 tmp *= d[i];
//                 if(tmp > n) break;
//                 if(tmp == d[j]) sub = true;
//             }
//             if(sub) scores -= b[d[j]-1];
//         }
//     }
//     return scores;
// }
// ll binenum(){
//     ll ans = 0;
//     rep(i, 1<<sz){
//         dsz = 0;
//         rep(j, sz) 
//         if( (i>>j) & 1){
//             d[dsz] = c[j];
//             dsz++;
//         }
//         ll r1 = cnt();
//         ans >?= r1;
//     }
//     return ans;
// }
// 
// {
//     rd(n, a(n), b(n));
//     rep(i,2, n){
//         if(i * i > n) break;
//         ll j = i * i;
//         while(j <= n){
//             vis[j] = 1;
//             j *= i;
//         }
//     }
//     ll ans = a[0];
//     rep(i, 2, n+1){
//         if(vis[i]) continue;
//         if(i * i <= n){
//             sz = 0;
//             ll j = i;
//             while(j <= n){
//                 c[sz++] = j;
//                 j *= i;
//             }
//             ans += binenum();
//         }else{
//             ans += a[i-1];
//         }
//     }
//     wt(ans);
// }
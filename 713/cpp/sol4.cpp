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
long long a[200000+10];
long long ans[200000+10];
long long sz;
long long pre[200000+10];
long long suf[200000+10];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    sz = 0;
    int n;
    rd(n);
    n = n+2;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        rd(a[cTE1_r3A]);
      }
    }
    sortA_L(n,a);
    for(i=(0);i<(n+3);i++){
      pre[i] = suf[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(i != 0){
        pre[i] = pre[i-1];
      }
      pre[i] += a[i];
    }
    for(i=(n)-1;i>=(0);i--){
      if(i != n-1){
        suf[i] = suf[i+1];
      }
      suf[i] += a[i];
    }
    if(pre[n-3] == a[n-2] || pre[n-3] == a[n-1]){
      {
        int a2conNHc;
        if(n-2==0){
          wt_L('\n');
        }
        else{
          for(a2conNHc=(0);a2conNHc<(n-2-1);a2conNHc++){
            wt_L(a[a2conNHc]);
            wt_L(' ');
          }
          wt_L(a[a2conNHc]);
          wt_L('\n');
        }
      }
      continue;
    }
    bool okay = false;
    for(i=(0);i<(n-2);i++){
      int snow = i > 0 ? pre[i-1]:0;
      snow += (i + 1) < n ? suf[i+1]: 0;
      snow -= a[n-1];
      if(snow == a[n-1]){
        int j;
        okay = true;
        for(j=(0);j<(n-1);j++){
          if(j == i){
            continue;
          }
          ans[sz] = a[j];
          ++sz;
        }
        {
          int ZIeRIny5;
          if(sz==0){
            wt_L('\n');
          }
          else{
            for(ZIeRIny5=(0);ZIeRIny5<(sz-1);ZIeRIny5++){
              wt_L(ans[ZIeRIny5]);
              wt_L(' ');
            }
            wt_L(ans[ZIeRIny5]);
            wt_L('\n');
          }
        }
        break;
      }
    }
    if(!okay){
      wt_L(-1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// ll a[2d5+10];
// ll ans[2d5+10], sz;
// ll pre[2d5+10];
// ll suf[2d5+10];
// {
//     REP(rd_int()){
//         sz = 0;
//         int @n;
//         n = n+2;
//         rd(a(n));
//         sortA(n,a);
//         rep(i,n+3) pre[i] = suf[i] = 0;
//         rep(i,n){
//             if(i != 0)  pre[i] = pre[i-1];
//             pre[i] += a[i];
//         }
//         rrep(i,n){
//             if(i != n-1) suf[i] = suf[i+1];
//             suf[i] += a[i];
//         }
//         if(pre[n-3] == a[n-2] || pre[n-3] == a[n-1]){
//            wt(a(n-2));
//            continue; 
//         }
//         bool okay = false;
//         rep(i,n-2){
//             int snow = i > 0 ? pre[i-1]:0;
//             snow += (i + 1) < n ? suf[i+1]: 0;
//             snow -= a[n-1];
//             if(snow == a[n-1]){
//                 okay = true;
//                 rep(j,n-1){
//                     if(j == i) continue;
//                     ans[sz] = a[j]; ++sz;
//                 }
//                 wt(ans(sz));
//                 break;
//             }
//         }
//         if(!okay){
//             wt(-1);
//         }
//     }
// }
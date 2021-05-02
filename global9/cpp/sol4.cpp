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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int n;
int a[1000+50];
int cnt[1000+50];
int ans[5000+20];
int asz;
void push(int x){
  ans[asz] = x;
  ++asz;
}
set<int> cnt2[1000+50];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    asz = 0;
    rd(n);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(n);cTE1_r3A++){
        rd(a[cTE1_r3A]);
      }
    }
    for(i=(0);i<(n);i++){
      ++cnt[a[i]];
    }
    int l = 0;
    while(true){
      while(cnt[l]){
        ++l;
      }
      if(l >= n){
        break;
      }
      int tmp = a[l];
      --cnt[tmp];
      ++cnt[l];
      a[l] = l;
      push(l);
      if(cnt[tmp] == 0){
        chmin(l, tmp);
      }
    }
    for(i=(0);i<(n);i++){
      cnt2[a[i]].insert(i);
    }
    l = 0;
    int r = n;
    while(true){
      while(cnt2[r].size() > 0){
        ++r;
      }
      while(cnt2[l].find(l) != cnt2[l].end()){
        ++l;
      }
      if(l >= n){
        break;
      }
      int t1;
      int t2;
      if(cnt2[l].size() > 0){
        t1 = *cnt2[l].begin();
        t2 = a[t1];
        if(t1 != -1){
          push(t1);
          a[t1] = r;
          cnt2[r].insert(t1);
          cnt2[t2].erase(t1);
          chmin(r, t2);
        }
      }
      push(l);
      t2 = a[l];
      cnt2[t2].erase(l);
      a[l] = l;
      cnt2[l].insert(l);
      chmin(l, t2);
    }
    wt_L(asz);
    wt_L('\n');
    for(i=(0);i<(asz);i++){
      ++ans[i];
    }
    {
      int XJIcIBrW;
      if(asz==0){
        wt_L('\n');
      }
      else{
        for(XJIcIBrW=(0);XJIcIBrW<(asz-1);XJIcIBrW++){
          wt_L(ans[XJIcIBrW]);
          wt_L(' ');
        }
        wt_L(ans[XJIcIBrW]);
        wt_L('\n');
      }
    }
    for(i=(0);i<(n+30);i++){
      cnt[i] = 0;
      cnt2[i].clear();
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int n;
// int a[1d3+50];
// int cnt[1d3+50];
// int ans[5d3+20], asz;
// void push(int x){
//     ans[asz] = x;
//     ++asz;
// }
// set<int> cnt2[1d3+50];
// {
//     REP(rd_int()){
//         asz = 0;
//         rd(n,a(n));
//         // TODO : [part one] make sure that the mex of the array with duplicates sorted
//         rep(i,n) ++cnt[a[i]];
//         int l = 0;
//         while(true){
//             while(cnt[l]) ++l;
//             if(l >= n) break;
//             int tmp = a[l];
//             --cnt[tmp];
//             ++cnt[l];
//             a[l] = l;
//             push(l);
//             if(cnt[tmp] == 0) l <?= tmp;
//         }
//         // TODO : [part two] make sure that the array with unsorted entries being sorted
//         rep(i,n) cnt2[a[i]].insert(i);
//         l = 0;
//         int r = n;
//         while(true){
//             while(cnt2[r].size() > 0) ++r;
//             while(cnt2[l].find(l) != cnt2[l].end()) ++l;
//             if(l >= n) break;
//             int t1, t2;
//             if(cnt2[l].size() > 0){
//                 t1 = *cnt2[l].begin(); t2 = a[t1];
//                 if(t1 != -1){
//                     push(t1);
//                     a[t1] = r;
//                     cnt2[r].insert(t1);
//                     cnt2[t2].erase(t1);
//                     r <?= t2;
//                 }
//             }
//             push(l);
//             t2 = a[l];
//             cnt2[t2].erase(l);
//             a[l] = l;
//             cnt2[l].insert(l);
//             l <?= t2;
//         }
//         wt(asz);
//         rep(i,asz) ++ans[i];
//         wt(ans(asz));
//         rep(i,n+30) cnt[i] = 0, cnt2[i].clear();
//     }
// }
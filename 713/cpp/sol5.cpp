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
long long n;
long long l;
long long r;
long long s;
const int MAXN = 510;
long long ans[MAXN];
long long con[MAXN];
bool out(){
  int i;
  for(i=(0);i<(n+2);i++){
    con[i] = 0;
  }
  for(i=(1);i<(n+1);i++){
    if(ans[i] != 0){
      ++con[ans[i]];
      if(con[ans[i]] > 1){
        return false;
      }
    }
  }
  int l = 1;
  for(i=(1);i<(n+1);i++){
    while(con[l]){
      ++l;
    }
    if(ans[i] != 0){
      continue;
    }
    ++con[l];
    ans[i] = l;
  }
  long long* aans = &ans[1];
  {
    int WYIGIcGE;
    if(n==0){
      wt_L('\n');
    }
    else{
      for(WYIGIcGE=(0);WYIGIcGE<(n-1);WYIGIcGE++){
        wt_L(aans[WYIGIcGE]);
        wt_L(' ');
      }
      wt_L(aans[WYIGIcGE]);
      wt_L('\n');
    }
  }
  return true;
}
bool dfs(long long cpos, long long s, long long maxm){
  int i;
  if(cpos > r){
    if(s > 0){
      return false;
    }
    return out();
  }
  if(s <= 0 || maxm <= 0){
    return false;
  }
  long long sx = 0;
  long long cmax = maxm;
  for(i=(cpos);i<(r+1);i++){
    sx += cmax;
    --cmax;
  }
  if(s - sx > 0){
    return false;
  }
  bool ret = false;
  for(i=(maxm+1)-1;i>=(1);i--){
    if(s - i < 0){
      continue;
    }
    ans[cpos] = i;
    ret = dfs(cpos+1, s-i, i-1);
    if(ret){
      break;
    }
  }
  return ret;
}
int main(){
  int V9aVTaxx;
  int APIVbQlN = rd_int();
  for(V9aVTaxx=(0);V9aVTaxx<(APIVbQlN);V9aVTaxx++){
    int i;
    rd(n);
    rd(l);
    rd(r);
    rd(s);
    bool ret = dfs(l, s, n);
    if(ret == false){
      wt_L(-1);
      wt_L('\n');
    }
    for(i=(0);i<(n+3);i++){
      ans[i] = 0;
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// ll n, l, r, s;
// const int MAXN = 510;
// ll ans[MAXN];
// ll con[MAXN];
// 
// bool out(){
//     rep(i, 0, n+2) con[i] = 0;
//     rep(i, 1, n+1){
//         if(ans[i] != 0){
//              ++con[ans[i]];
//              if(con[ans[i]] > 1) return false;
//         }
//     }
//     int l = 1;
//     rep(i,1,n+1){
//         
//         while(con[l]) ++l;
//         if(ans[i] != 0) continue;
//         ++con[l];
//         ans[i] = l;
//     }
//     ll * aans = &ans[1];
//     wt(aans(n));
//     return true;
// }
// 
// bool dfs(ll cpos, ll s, ll maxm){
//     if(cpos > r){
//         if(s > 0) return false;
//         return out();
//     }
//     if(s <= 0 || maxm <= 0){
//         return false;
//     }
//     ll sx = 0,  cmax = maxm;
//     rep(i,cpos, r+1){
//         sx += cmax;
//         --cmax;
//     }
//     if(s - sx > 0) return false; 
//     bool ret = false;
//     rrep(i,1, maxm+1){
//         if(s - i < 0) continue;
//         ans[cpos] = i;
//         ret = dfs(cpos+1, s-i, i-1);
//         if(ret) break;
//     }
//     return ret;
// }
// 
// {
//     REP(rd_int()){
//         rd(n,l,r,s);
//         bool ret = dfs(l, s, n);
//         if(ret == false){
//             wt(-1);
//         }
//         rep(i,0, n+3) ans[i] = 0;
//     }
// }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
long long r;
long long b;
long long d;
bool dfs(long long  x, long long y, long long d){
  if(x > y){
    swap(x,y);
  }
  if(x == 0){
    return y == 0;
  }
  if( abs(x-y) <= d){
    return true;
  }
  long long PiIOrLma;
  long long AuJVIghY;
  long long FJNsjZ7B;
  PiIOrLma = 0;
  AuJVIghY = x;
  while(PiIOrLma < AuJVIghY){
    if((PiIOrLma + AuJVIghY)%2==0){
      FJNsjZ7B = (PiIOrLma + AuJVIghY) / 2;
    }
    else{
      FJNsjZ7B = (PiIOrLma + AuJVIghY + 1) / 2;
    }
    if( FJNsjZ7B + FJNsjZ7B * d <= y){
      PiIOrLma = FJNsjZ7B;
    }
    else{
      AuJVIghY = FJNsjZ7B - 1;
    }
  }
  long long a =AuJVIghY;
  if(a == 0){
    return false;
  }
  return dfs(x - a, y - (a + a * d), d );
}
int main(){
  int Z8lEHcvz;
  int rbGYC8dh = rd_int();
  for(Z8lEHcvz=(0);Z8lEHcvz<(rbGYC8dh);Z8lEHcvz++){
    rd(r);
    rd(b);
    rd(d);
    if(r > b){
      swap(r,b);
    }
    if(r + r * d < b){
      wt_L("NO");
      wt_L('\n');
    }
    else{
      wt_L("YES");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll r, b, d;
// bool dfs(ll  x, ll y, ll d){
//     if(x > y) swap(x,y);
//    
//     if(x == 0) return y == 0;
//      if( abs(x-y) <= d) return true;
//     ll a = bsearch_max[ll, k, 0, x] ( k + k * d <= y);
//     if(a == 0) return false;
//     return dfs(x - a, y - (a + a * d), d );
// }
// {
//     REP(rd_int()){
//         rd(r,b,d);
//         if(r > b) swap(r,b);
//         if(r + r * d < b) wt("NO");
//         else wt("YES");
//         //wt(dfs(r,b,d) ? "YES ": "NO"); 
//     }
// }
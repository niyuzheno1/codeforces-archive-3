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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int n;
char s[100000+10];
int main(){
  int PiIOrLma;
  int AuJVIghY = rd_int();
  for(PiIOrLma=(0);PiIOrLma<(AuJVIghY);PiIOrLma++){
    int i;
    rd(n);
    rd(s);
    bool ok = true;
    int cnt = n/3;
    int cntm = 0;
    int cntt = 0;
    for(i=(0);i<(n);i++){
      if(s[i] == 'M'){
        ++ cntm;
      }
    }
    if(cntm != cnt){
      ok = false;
    }
    cntt = 0;
    if(s[0] != 'T' || s[n-1] != 'T'){
      ok = false;
    }
    cntm = 0;
    cntt = 0;
    for(i=(0);i<(n);i++){
      if(s[i] == 'M'){
        ++ cntm;
      }
      if(s[i] == 'T'){
        ++ cntt;
      }
      if(cntm > cntt){
        ok = false;
      }
    }
    cntm = 0;
    cntt = 0;
    for(i=(n)-1;i>=(0);i--){
      if(s[i] == 'M'){
        ++ cntm;
      }
      if(s[i] == 'T'){
        ++ cntt;
      }
      if(cntm > cntt){
        ok = false;
      }
    }
    if(ok){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n;
// char s[1d5+10];
// {
//     REP(rd_int()){
//         rd(n, s);
//         bool ok = true;
//         int cnt = n/3, cntm = 0, cntt = 0;
//         rep(i,n) if(s[i] == 'M') {++ cntm;}
//         if(cntm != cnt) ok = false;
//         cntt = 0;
//         if(s[0] != 'T' || s[n-1] != 'T') ok = false; 
//         cntm = 0, cntt = 0;
//         rep(i,n){
//             if(s[i] == 'M') ++ cntm;
//             if(s[i] == 'T') ++ cntt;
//             if(cntm > cntt) ok = false;
//         }
//         cntm = 0, cntt = 0;
//         rrep(i,n){
//             if(s[i] == 'M') ++ cntm;
//             if(s[i] == 'T') ++ cntt;
//             if(cntm > cntt) ok = false;
//         }
//         if(ok) wt("YES");
//         else wt("NO");
//     }
// }
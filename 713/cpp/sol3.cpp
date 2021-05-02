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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
char s[200000+10];
int minx;
int miny;
int maxx;
int maxy;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int a;
    int b;
    int n;
    rd(a);
    rd(b);
    n = rd(s);
    int m[] = {a,b};
    for(i=(0);i<(n);i++){
      if(s[i] == '?' && s[n-i-1] != '?'){
        s[i] = s[n-i-1];
      }
    }
    for(i=(0);i<(n);i++){
      if('0' <= s[i]  &&  s[i] <= '9'){
        --m[s[i]-'0'];
      }
    }
    bool okay = true;
    if(n % 2 == 0){
      for(i=(0);i<(n);i++){
        if(s[i] == '?' && s[n-i-1] == '?'){
          if(m[0] > 0){
            s[i] = s[n-i-1] = '0';
            m[0] -= 2;
          }
          else{
            s[i] = s[n-i-1] = '1';
            m[1] -= 2;
          }
        }
      }
      if(m[0] != 0 || m[1] != 0){
        okay = false;
      }
    }
    else{
      okay = false;
      int md = 0;
      for(i=(0);i<(n);i++){
        if(i == n-i-1){
          md = i;
        }
      }
      for(i=(0);i<(n);i++){
        if(i != n-i-1 && s[i] == '?' && s[n-i-1] == '?'){
          if(m[0] > 1){
            s[i] = s[n-i-1] = '0';
            m[0] -= 2;
          }
          else if(m[1] > 1){
            s[i] = s[n-i-1] = '1';
            m[1] -= 2;
          }
        }
      }
      if(m[0] == 0 && m[1] == 0){
        okay = true;
      }
      if(m[0] == 0 && m[1] == 1){
        okay = true;
        s[md] = '1';
      }
      else if(m[0] == 1 && m[1] == 0){
        okay = true;
        s[md] = '0';
      }
    }
    for(i=(0);i<(n);i++){
      if(s[i] != s[n-i-1]){
        okay = false;
      }
    }
    if(!okay){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L(s);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char s[2d5+10];
// int minx, miny, maxx, maxy;
// {
//     REP(rd_int()){
//         int a,b,n;
//         rd(a,b,s@n);
//         int m[] = {a,b};
//         rep(i,n) if(s[i] == '?' && s[n-i-1] != '?') s[i] = s[n-i-1];
//         rep(i,n) if('0' <= s[i] <= '9')--m[s[i]-'0'];
//         bool okay = true;
//         if(n % 2 == 0){
//             rep(i,n) if(s[i] == '?' && s[n-i-1] == '?'){
//                 if(m[0] > 0){
//                     s[i] = s[n-i-1] = '0';
//                     m[0] -= 2;
//                 }else{
//                     s[i] = s[n-i-1] = '1';
//                     m[1] -= 2;
//                 }
//             }
//             if(m[0] != 0 || m[1] != 0){
//                 okay = false;
//             }
//         }else{
//             okay = false;
//             int md = 0;
//             rep(i,n) if(i == n-i-1) md = i;
//             rep(i,n) if(i != n-i-1 && s[i] == '?' && s[n-i-1] == '?'){
//                 if(m[0] > 1){
//                     s[i] = s[n-i-1] = '0';
//                     m[0] -= 2;
//                 }else if(m[1] > 1){
//                     s[i] = s[n-i-1] = '1';
//                     m[1] -= 2;
//                 }
//             }
//             if(m[0] == 0 && m[1] == 0){
//                 okay = true;
//             }
//             if(m[0] == 0 && m[1] == 1){
//                 okay = true;
//                 s[md] = '1';
//             }else if(m[0] == 1 && m[1] == 0){
//                 okay = true;
//                 s[md] = '0';
//             }
//         }
//         rep(i,n) if(s[i] != s[n-i-1]) okay = false;
//         if(!okay) wt(-1); else wt(s);
//     }
// }
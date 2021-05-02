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
inline void rd(double &x){
  int k;
  int m=0;
  int p=0;
  double r = 1;
  x = 0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m = 1;
      break;
    }
    if(k=='.'){
      p = 1;
      break;
    }
    if('0'<=k&&k<='9'){
      x = k - '0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k=='.'){
      p = 1;
      continue;
    }
    if(k<'0'||k>'9'){
      break;
    }
    if(p){
      r *= 0.1;
      x += r * (k - '0');
    }
    else{
      x = x * 10 + k - '0';
    }
  }
  if(m){
    x = -x;
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
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
double a;
double b;
double c;
double d;
int main(){
  rd(a);
  rd(b);
  rd(c);
  rd(d);
  double l = a/b;
  double e = c/d;
  wt_L(l * (1.0/(1.0-(1.0-l)*(1.0-e))));
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// double a, b, c, d;
// {
//     rd(a,b,c,d);
//     double l = a/b;
//     double e = c/d;
//     wt(l * (1.0/(1.0-(1.0-l)*(1.0-e))));
// 
// }

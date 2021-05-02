#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (1000000007U)
void*wmem;
char memarr[209715200];
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
struct mint{
  static unsigned md;
  static unsigned W;
  static unsigned R;
  static unsigned Rinv;
  static unsigned mdninv;
  static unsigned RR;
  unsigned val;
  mint(){
    val=0;
  }
  mint(int a){
    val = mulR(a);
  }
  mint(unsigned a){
    val = mulR(a);
  }
  mint(long long a){
    val = mulR(a);
  }
  mint(unsigned long long a){
    val = mulR(a);
  }
  int get_inv(long long a, int md){
    long long t=a;
    long long s=md;
    long long u=1;
    long long v=0;
    long long e;
    while(s){
      e=t/s;
      t-=e*s;
      u-=e*v;
      swap(t,s);
      swap(u,v);
    }
    if(u<0){
      u+=md;
    }
    return u;
  }
  void setmod(unsigned m){
    int i;
    unsigned t;
    W = 32;
    md = m;
    R = (1ULL << W) % md;
    RR = (unsigned long long)R*R % md;
    switch(m){
      case 104857601:
      Rinv = 2560000;
      mdninv = 104857599;
      break;
      case 998244353:
      Rinv = 232013824;
      mdninv = 998244351;
      break;
      case 1000000007:
      Rinv = 518424770;
      mdninv = 2226617417U;
      break;
      case 1000000009:
      Rinv = 171601999;
      mdninv = 737024967;
      break;
      case 1004535809:
      Rinv = 234947584;
      mdninv = 1004535807;
      break;
      case 1007681537:
      Rinv = 236421376;
      mdninv = 1007681535;
      break;
      case 1012924417:
      Rinv = 238887936;
      mdninv = 1012924415;
      break;
      case 1045430273:
      Rinv = 254466304;
      mdninv = 1045430271;
      break;
      case 1051721729:
      Rinv = 257538304;
      mdninv = 1051721727;
      break;
      default:
      Rinv = get_inv(R, md);
      mdninv = 0;
      t = 0;
      for(i=(0);i<((int)W);i++){
        if(t%2==0){
          t+=md;
          mdninv |= (1U<<i);
        }
        t /= 2;
      }
    }
  }
  unsigned mulR(unsigned a){
    return (unsigned long long)a*R%md;
  }
  unsigned mulR(int a){
    if(a < 0){
      a = a%((int)md)+(int)md;
    }
    return mulR((unsigned)a);
  }
  unsigned mulR(unsigned long long a){
    return mulR((unsigned)(a%md));
  }
  unsigned mulR(long long a){
    a %= (int)md;
    if(a < 0){
      a += md;
    }
    return mulR((unsigned)a);
  }
  unsigned reduce(unsigned T){
    unsigned m = T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned reduce(unsigned long long T){
    unsigned m = (unsigned)T * mdninv;
    unsigned t = (unsigned)((T + (unsigned long long)m*md) >> W);
    if(t >= md){
      t -= md;
    }
    return t;
  }
  unsigned get(){
    return reduce(val);
  }
  inline mint &operator++(){
    (*this) += 1;
    return *this;
  }
  inline mint &operator--(){
    (*this) -= 1;
    return *this;
  }
  inline mint operator++(int a){
    mint res(*this);
    (*this) += 1;
    return res;
  }
  inline mint operator--(int a){
    mint res(*this);
    (*this) -= 1;
    return res;
  }
  mint &operator+=(mint a){
    val += a.val;
    if(val >= md){
      val -= md;
    }
    return *this;
  }
  mint &operator-=(mint a){
    if(val < a.val){
      val = val + md - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  mint &operator*=(mint a){
    val = reduce((unsigned long long)val*a.val);
    return *this;
  }
  mint &operator/=(mint a){
    return *this *= a.inverse();
  }
  mint operator+(mint a){
    return mint(*this)+=a;
  }
  mint operator-(mint a){
    return mint(*this)-=a;
  }
  mint operator*(mint a){
    return mint(*this)*=a;
  }
  mint operator/(mint a){
    return mint(*this)/=a;
  }
  mint operator+(int a){
    return mint(*this)+=mint(a);
  }
  mint operator-(int a){
    return mint(*this)-=mint(a);
  }
  mint operator*(int a){
    return mint(*this)*=mint(a);
  }
  mint operator/(int a){
    return mint(*this)/=mint(a);
  }
  mint operator+(long long a){
    return mint(*this)+=mint(a);
  }
  mint operator-(long long a){
    return mint(*this)-=mint(a);
  }
  mint operator*(long long a){
    return mint(*this)*=mint(a);
  }
  mint operator/(long long a){
    return mint(*this)/=mint(a);
  }
  mint operator-(void){
    mint res;
    if(val){
      res.val=md-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  operator bool(void){
    return val!=0;
  }
  operator int(void){
    return get();
  }
  operator long long(void){
    return get();
  }
  mint inverse(){
    int a = val;
    int b = md;
    int u = 1;
    int v = 0;
    int t;
    mint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += md;
    }
    res.val = (unsigned long long)u*RR % md;
    return res;
  }
  mint pw(unsigned long long b){
    mint a(*this);
    mint res;
    res.val = R;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  bool operator==(int a){
    return mulR(a)==val;
  }
  bool operator!=(int a){
    return mulR(a)!=val;
  }
}
;
unsigned mint::md;
unsigned mint::W;
unsigned mint::R;
unsigned mint::Rinv;
unsigned mint::mdninv;
unsigned mint::RR;
mint operator+(int a, mint b){
  return mint(a)+=b;
}
mint operator-(int a, mint b){
  return mint(a)-=b;
}
mint operator*(int a, mint b){
  return mint(a)*=b;
}
mint operator/(int a, mint b){
  return mint(a)/=b;
}
mint operator+(long long a, mint b){
  return mint(a)+=b;
}
mint operator-(long long a, mint b){
  return mint(a)-=b;
}
mint operator*(long long a, mint b){
  return mint(a)*=b;
}
mint operator/(long long a, mint b){
  return mint(a)/=b;
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
inline void my_putchar(const int k){
  putchar(k);
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
#include <random>
#define Treap TreapDa<Data>
template<class Data> class TreapDa{
  public:
  int priority;
  int id;
  int subtreeSize;
  Data data;
  Data subtreeData;
  void** kids;
  TreapDa(){
    priority = 0;
    id = 0;
    subtreeSize = 0;
    data = subtreeData = NULL;
    kids = NULL;
  }
}
;
template<class RandomDevice, class Data, class UpdateData> class TreapOp{
  RandomDevice* rande;
  UpdateData* upda;
  void* node_pool;
  int cur;
  int lmt;
  public:
  void reset(int nsz){
    Treap * tmp_node_pool = NULL;
    walloc1d(&tmp_node_pool, nsz);
    node_pool = (void*)tmp_node_pool;
    cur = 0;
    lmt = nsz;
  }
  void * allocate_new_node(){
    if(cur >= lmt){
      reset(lmt<<1);
    }
    Treap * tmp_node_pool = (Treap * )node_pool;
    return (void*)&tmp_node_pool[cur++];
  }
  TreapOp(){
    cur = 0;
    lmt = 0;
    upda = new UpdateData();
    rande = new RandomDevice();
  }
  ~TreapOp(){
    delete upda;
    delete rande;
  }
  void * get_new_node(Data & data, int id){
    Treap * root = (Treap *) allocate_new_node();
    root->data = data;
    root->id = id;
    root->priority = rande->next();
    root->subtreeData = Data();
    walloc1d(&root->kids, 2);
    root->kids[0] = root->kids[1] = 0;
    this->recalc(root);
    return (void*)root;
  }
  void split(void ** res, void * x, int nInLeft){
    auto me = (Treap*) x;
    res[0] = res[1] = NULL;
    if (me==NULL){
      return ;
    }
    this->prop(me);
    if (this->size(me->kids[0])>=nInLeft){
      void* leftRes[2];
      this->split(leftRes, me->kids[0], nInLeft);
      me->kids[0]=leftRes[1];
      this->recalc(me);
      res[0] = leftRes[0];
      res[1] = me;
      return;
    }
    else{
      nInLeft=nInLeft-(this->size(me->kids[0]))-1;
      void* rightRes[2];
      this->split(rightRes, me->kids[1], nInLeft);
      me->kids[1]=rightRes[0];
      this->recalc(me);
      res[0] = (void *)me;
      res[1] = (void *)rightRes[1];
      return;
    }
  }
  void * merge(void * lll, void * rrr){
    auto l = (Treap*) lll;
    auto r = (Treap*) rrr;
    if (l==NULL){
      return r;
    }
    if (r==NULL){
      return l;
    }
    this->prop(l);
    this->prop(r);
    if (l->priority<r->priority){
      l->kids[1]=this->merge(l->kids[1], r);
      this->recalc(l);
      return l;
    }
    else{
      r->kids[0]=this->merge(l, r->kids[0]);
      this->recalc(r);
      return r;
    }
  }
  void recalc(void * x){
    auto me = (Treap*) x;
    if (me==NULL){
      return;
    }
    assert(upda->check((void*)me));
    upda->recalibrate((void*)me);
  }
  void prop(void * x){
    auto me = (Treap*) x;
    if (me==NULL){
      return;
    }
    upda->propagate((void*)me);
    this->recalc(me);
  }
  int size(void * x){
    auto t = (Treap*) x;
    if(t == NULL){
      return 0;
    }
    return t->subtreeSize;
  }
}
;
class RDevice{
  public:
  random_device randomD;
  mt19937 rng;
  std::uniform_int_distribution<int> * uid;
  RDevice(){
    mt19937 rngx{randomD()};
    rng = rngx;
    uid = new std::uniform_int_distribution<int>(1,100000);
  }
  ~RDevice(){
    delete uid;
  }
  int next(){
    return (*uid)(rng);
  }
}
;
mint pw[800000+10];
class Gata{
  public:
  mint ls;
  mint rs;
  int width;
  Gata(){
    ls = rs = 0;
    width = 1;
  }
  Gata(char s){
    int u = s;
    ls = rs = u;
    width = 1;
  }
}
;
void merge1(Gata & lhs, Gata & x, Gata & y){
  lhs = x;
  lhs.width += y.width;
  lhs.ls *= pw[y.width];
  lhs.ls += y.ls;
}
void merge2(Gata & lhs, Gata & x, Gata & y){
  lhs = x;
  lhs.rs *= pw[y.width];
  lhs.rs += y.rs;
}
#define Trea TreapDa<Gata>
#define TMaster TreapOp<RDevice,Gata,UpdateD>
class UpdateD{
  public:
  UpdateD(){
  }
  bool check(void * x){
    return true;
  }
  void recalibrate(void * x){
    int i;
    Trea * me = (Trea *) x;
    me->subtreeSize = 1;
    Gata*subtreeData = &me->subtreeData;
    Gata*data = &me->data;
    data->width = 1;
    data->ls = data->rs;
    subtreeData->width = 0;
    subtreeData->ls = 0;
    subtreeData->rs = 0;
    Gata res[10];
    for(i=(0);i<(2);i++){
      auto t =  (Trea *) me->kids[i];
      if(t == NULL){
        if(i == 0){
          merge1(res[2], *subtreeData, *data);
          subtreeData = &res[2];
          continue;
        }
        continue;
      }
      merge1(res[i], *subtreeData, t->subtreeData);
      if(i == 0){
        merge1(res[2], res[i], *data);
        subtreeData = &res[2];
        continue;
      }
      subtreeData = &res[i];
    }
    for(i=(2)-1;i>=(0);i--){
      int j = i + 4;
      auto t =  (Trea *) me->kids[i];
      if(t == NULL){
        if(i == 1){
          merge2(res[3], *subtreeData, *data);
          subtreeData = &res[3];
          continue;
        }
        continue;
      }
      merge2(res[j], *subtreeData, t->subtreeData);
      if(i == 1){
        merge2(res[3], res[j], *data);
        subtreeData = &res[3];
        continue;
      }
      subtreeData = &res[j];
    }
    me->subtreeData = *subtreeData;
    for(int i = 0; i < 2; ++i){
      auto t = (Trea *) me->kids[i];
      if(t == NULL){
        continue;
      }
      me->subtreeSize += t->subtreeSize;
    }
  }
  void propagate(void * x){
  }
}
;
void showall(void * x){
  auto t =  (Trea *)x;
  if(t == NULL){
    return;
  }
  int u = t->data.ls;
  char v = (char)u;
  v+='a';
  showall(t->kids[0]);
  cout << v;
  showall(t->kids[1]);
}
int n;
int q;
char a[700000+10];
TMaster treap;
mint pp;
int idx;
int main(){
  int i;
  wmem = memarr;
  {
    mint x;
    x.setmod(MD);
  }
  pp = 31;
  pw[0] = 1;
  pw[1] = pp;
  treap.reset(800000);
  rd(n);
  rd(q);
  {
    int rbGYC8dh;
    for(rbGYC8dh=(0);rbGYC8dh<(n);rbGYC8dh++){
      rd(a[rbGYC8dh]);
    }
  }
  for(i=(2);i<(n+q+2);i++){
    pw[i] = pw[i-1]*pp;
  }
  for(i=(0);i<(300000+n);i++){
    a[i] = a[i]-'a';
  }
  Trea * root = NULL;
  for(int i = 0; i < n; ++i){
    Gata tmp(a[i]);
    root = (Trea *)treap.merge(root, treap.get_new_node(tmp, idx++));
  }
  for (int qq=0; qq<q; qq++){
    int type;
    rd(type);
    if (type==1){
      int l;
      rd(l);
      int r;
      rd(r);
      --l;
      --r;
      assert(l<=r);
      void* parts1[2];
      void* parts2[2];
      treap.split(parts1,root, l);
      treap.split(parts2,parts1[1], r-l+1);
      root=(Trea *)treap.merge(parts1[0], parts2[1]);
    }
    else if(type == 2){
      char c[4];
      int p;
      rd(c);
      rd(p);
      --p;
      void* parts1[2];
      treap.split(parts1,root, p);
      Gata tmp(c[0]-'a');
      auto node = treap.get_new_node(tmp, idx++);
      root = (Trea *)treap.merge(parts1[0], treap.merge( node, parts1[1]));
    }
    else{
      int l;
      rd(l);
      int r;
      rd(r);
      --l;
      --r;
      void* parts1[2];
      void* parts2[2];
      treap.split(parts1,root, l);
      treap.split(parts2,parts1[1], r-l+1);
      Trea * t1 = (Trea * )parts2[0];
      if(t1->subtreeData.ls == t1->subtreeData.rs){
        wt_L("yes");
        wt_L('\n');
      }
      else{
        wt_L("no");
        wt_L('\n');
      }
      root = (Trea *)treap.merge(parts1[0], treap.merge( parts2[0], parts2[1]));
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=200m
// #include <random>
// #define Treap TreapDa<Data>
// /*Treap Data*/
// template<class Data>
// class TreapDa {
// public: 
//   int priority, id, subtreeSize;
//   Data data, subtreeData;
//   void** kids;
//   TreapDa(){
//     priority = 0;
//     id = 0;
//     subtreeSize = 0;
//     data = subtreeData = NULL; 
//     kids = NULL;
//   }
// };
// 
// /*Treap Operations*/
// template<class RandomDevice, class Data, class UpdateData>
// class TreapOp {
//   RandomDevice * rande;
//   UpdateData * upda;
//   void * node_pool;
//   int cur, lmt;
// 
// public:
//   void reset(int nsz){
//       Treap * tmp_node_pool = NULL;
//       walloc1d(&tmp_node_pool, nsz);
//       node_pool = (void*)tmp_node_pool;
//       cur = 0;
//       lmt = nsz;
//   } 
//   void * allocate_new_node(){
//       if(cur >= lmt) reset(lmt<<1);
//       Treap * tmp_node_pool = (Treap * )node_pool;
//       return (void*)&tmp_node_pool[cur++];
//   }
//   
//   TreapOp(){
//     cur = 0; lmt = 0;
//     upda = new UpdateData(); 
//     rande = new RandomDevice();
// 
//   }
//   ~TreapOp(){
//       delete upda;
//       delete rande;
//   }
//   void * get_new_node(Data & data, int id){
//     Treap * root = (Treap *) allocate_new_node();
//     root->data = data;
//     root->id = id;
//     root->priority = rande->next();
//     root->subtreeData = Data();
//     
//     walloc1d(&root->kids, 2);
//     root->kids[0] = root->kids[1] = 0;
//     this->recalc(root);
//     return (void*)root;
//   }  
//   void split(void ** res, void * x, int nInLeft) {
//     auto me = (Treap*) x;
//     res[0] = res[1] = NULL;
//     if (me==NULL) return ;
//     this->prop(me);
//     if (this->size(me->kids[0])>=nInLeft) {
//       void * leftRes[2];
//       this->split(leftRes, me->kids[0], nInLeft);
//       me->kids[0]=leftRes[1];
//       this->recalc(me);
//       res[0] = leftRes[0]; res[1] = me;
//       return;
//     }
//     else {
//       nInLeft=nInLeft-(this->size(me->kids[0]))-1;
//       void * rightRes[2];
//       this->split(rightRes, me->kids[1], nInLeft);
//       me->kids[1]=rightRes[0];
//       this->recalc(me);
//       res[0] = (void *)me; res[1] = (void *)rightRes[1];
//       return;
//     }
//   }
//     
//   
//   void * merge(void * lll, void * rrr) {
//     auto l = (Treap*) lll;
//     auto r = (Treap*) rrr;
//     if (l==NULL) return r;
//     if (r==NULL) return l;
//     this->prop(l); this->prop(r);
//     if (l->priority<r->priority) {
//       l->kids[1]=this->merge(l->kids[1], r);
//       this->recalc(l);
//       return l;
//     }
//     else {
//       r->kids[0]=this->merge(l, r->kids[0]);
//       this->recalc(r);
//       return r;
//     }
//   }
//   
//   
//   //MUST CALL PROP BEFORE RECALCING!
//   void recalc(void * x) {
//     auto me = (Treap*) x;
//     if (me==NULL) return;
//     assert(upda->check((void*)me)); // sanitation check
//     upda->recalibrate((void*)me);
//   }
//   void prop(void * x) {
//     auto me = (Treap*) x;
//     if (me==NULL) return;
//     //reset subtreedata max in recalc
//     upda->propagate((void*)me);
//     this->recalc(me);
//   }
//   int size(void * x) {
//     auto t = (Treap*) x;
//     if(t == NULL) return 0;
//     return t->subtreeSize;
//   }  
// };
// 
// /*Random Device is here */
// 
// class RDevice{
// public:
//     random_device randomD;
//      mt19937 rng;
//    std::uniform_int_distribution<int> * uid;
//     RDevice(){
//       mt19937 rngx{randomD()};
//       rng = rngx;
//       uid = new std::uniform_int_distribution<int>(1,100000);
//     }
//     ~RDevice(){
//         delete uid;
//     }
//   int next(){
//     return (*uid)(rng);
//   }
// };
// 
// mint pw[8d5+10];
// /*Our Data stored in each node in the Treap*/
// 
// class Gata{
// public:
//   mint ls,rs;
//   int width;
//   Gata(){
//       ls = rs = 0;
//       width = 1;
//   }
//   Gata(char s){
//       int u = s;
//       ls = rs = u;
//       width = 1;
//   }
//   
// };
// 
// void merge1(Gata & lhs, Gata & x, Gata & y){
//     lhs = x;
//     lhs.width += y.width;
//     lhs.ls *= pw[y.width];
//     lhs.ls += y.ls;
// }
// void merge2(Gata & lhs, Gata & x, Gata & y){
//     lhs = x;
//     lhs.rs *= pw[y.width];
//     lhs.rs += y.rs;
// }
// 
// #define Trea TreapDa<Gata>
// #define TMaster TreapOp<RDevice,Gata,UpdateD>
// 
// 
// class UpdateD{
// public:
//   UpdateD(){
// 
//   }
//   bool check(void * x){
//     return true;
//   }
//   void recalibrate(void * x){
//     Trea * me = (Trea *) x;
//     me->subtreeSize = 1;
//     //intitialize our data
//     Gata *subtreeData = &me->subtreeData, *data = &me->data;
//     data->width = 1;
//     data->ls = data->rs;
//     subtreeData->width = 0;
//     subtreeData->ls = 0;
//     subtreeData->rs = 0;
//     Gata res[10];
//     //merge between subtrees
//     rep(i,0,2){
//       auto t =  (Trea *) me->kids[i];
//       if(t == NULL){ 
//         if(i == 0){
//           merge1(res[2], *subtreeData, *data);
//           subtreeData = &res[2];
//           continue;    
//         }
//         continue;
//       }
//       merge1(res[i], *subtreeData, t->subtreeData);
//       if(i == 0){
//         merge1(res[2], res[i], *data);
//         subtreeData = &res[2];
//         continue;    
//       }
//       subtreeData = &res[i];
//     } 
//     rrep(i,0,2){
//       int j = i + 4;
//       auto t =  (Trea *) me->kids[i];
//       if(t == NULL){ 
//         if(i == 1){
//           merge2(res[3], *subtreeData, *data);
//           subtreeData = &res[3];
//           continue;    
//         }
//         continue;
//       }
//       merge2(res[j], *subtreeData, t->subtreeData);
//       if(i == 1){
//         merge2(res[3], res[j], *data);
//         subtreeData = &res[3];
//         continue;    
//       }
//       subtreeData = &res[j];
//     } 
//     me->subtreeData = *subtreeData;
//     for(int i = 0; i < 2; ++i){
//       auto t = (Trea *) me->kids[i];
//       if(t == NULL) continue;
//       me->subtreeSize += t->subtreeSize;
//     }
//     //assert( !( (me->subtreeData.ls != 0 && me->subtreeData.rs == 0 ) || (me->subtreeData.ls == 0 && me->subtreeData.rs != 0 ) ));
//   }
//   void propagate(void * x){
//     
//   }
// };
// 
// 
// void showall(void * x){
//   auto t =  (Trea *)x;
//   if(t == NULL) return;
//   int u = t->data.ls;
//   char v = (char)u;
//   v+='a';
//   showall(t->kids[0]);
//   cout << v;
//   showall(t->kids[1]);
// }
// 
// int n,q;
// char a[7d5+10];
// TMaster treap;
// mint pp;
// int idx;
// 
// {
//     pp = 31;
//     pw[0] = 1;
//     pw[1] = pp;
//  
//     treap.reset(8d5);
//     rd(n, q, a(n));
//     rep(i, 2, n+q+2)  pw[i] = pw[i-1]*pp;
//     rep(i,3d5+n) a[i] = a[i]-'a';
//     Trea * root = NULL;
//     for(int i = 0; i < n; ++i){
//         Gata tmp(a[i]);
//         root = (Trea *)treap.merge(root, treap.get_new_node(tmp, idx++));
//     }
//     for (int qq=0; qq<q; qq++) {
//         int @type; 
//         if (type==1) {
//             int @l, @r;
//             --l; --r;
//             assert(l<=r);
//             void * parts1[2];
//             void * parts2[2];
//             treap.split(parts1,root, l);
//             treap.split(parts2,parts1[1], r-l+1); 
//             root=(Trea *)treap.merge(parts1[0], parts2[1]);
//         }
//         else if(type == 2){
//             char c[4];
//             int p;
//             rd(c,p);
//             --p;
//             void * parts1[2];
//             treap.split(parts1,root, p);
//             Gata tmp(c[0]-'a');
//             auto node = treap.get_new_node(tmp, idx++);
//             root = (Trea *)treap.merge(parts1[0], treap.merge( node, parts1[1]));
//         }else{
//             int @l, @r;
//             --l; --r;
//             void * parts1[2];
//             void * parts2[2];
//             treap.split(parts1,root, l);
//             treap.split(parts2,parts1[1], r-l+1); 
//             Trea * t1 = (Trea * )parts2[0];
//             if(t1->subtreeData.ls == t1->subtreeData.rs){
//                 wt("yes");
//             }else{
//                 wt("no");
//             }
//             root = (Trea *)treap.merge(parts1[0], treap.merge( parts2[0], parts2[1]));
//            
//         }
//         
//     }
// }
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[209715200];
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
#include <random>
#include <cstring>
#define Treap TreapDa<Data>
template<class Data> class TreapDa{
  public:
  int priority;
  int id;
  int subtreeSize;
  Data data;
  Data subtreeData;
  void** kids;
  void* par;
  TreapDa(){
    priority = 0;
    id = 0;
    subtreeSize = 0;
    data = subtreeData = NULL;
    kids = NULL;
    par = NULL;
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
  void setparent(void * a, void * b){
    if(b == NULL){
      return;
    }
    auto tb = (Treap*)b;
    tb->par = a;
  }
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
  void * getparent(void * x){
    auto me = (Treap*) x;
    while(me->par){
      me =  (Treap*)me->par;
    }
    return me;
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
      setparent(NULL, me->kids[0]);
      this->split(leftRes, me->kids[0], nInLeft);
      setparent(me , leftRes[1]);
      me->kids[0]=leftRes[1];
      this->recalc(me);
      res[0] = leftRes[0];
      res[1] = me;
      return;
    }
    else{
      nInLeft=nInLeft-(this->size(me->kids[0]))-1;
      void* rightRes[2];
      setparent(NULL, me->kids[1]);
      this->split(rightRes, me->kids[1], nInLeft);
      me->kids[1]=rightRes[0];
      setparent(me , rightRes[0]);
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
      setparent(NULL, l->kids[1]);
      l->kids[1]=this->merge(l->kids[1], r);
      setparent(l , l->kids[1]);
      this->recalc(l);
      return l;
    }
    else{
      setparent(NULL, r->kids[0]);
      r->kids[0]=this->merge(l, r->kids[0]);
      setparent(r , r->kids[0]);
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
class Gata{
  public:
  int val;
  int fliped;
  int esum[3][2];
  int cnt[2];
  int width;
  int inversed;
  int filled;
  Gata(){
    filled = -1;
    val = 0;
    inversed = 0;
    width = 0;
    fliped = 0;
    memset(esum, 0 ,sizeof(esum));
    memset(cnt, 0 ,sizeof(cnt));
  }
  Gata(char s){
    int i;
    val = s;
    filled = -1;
    inversed = 0;
    width = 1;
    fliped = 0;
    memset(esum, 0 ,sizeof(esum));
    memset(cnt, 0 ,sizeof(cnt));
    for(i=(0);i<(3);i++){
      esum[i][val] = 1;
    }
    cnt[val] = 1;
  }
}
;
#define Trea TreapDa<Gata>
#define TMaster TreapOp<RDevice,Gata,UpdateD>
bool merge(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
  lhs = l;
  auto u = r.esum[dir^r.inversed][bits^r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.fliped == bits) * r.width;
  lhs.esum[dir][bits] += u;
  chmax(lhs.esum[2][bits], lhs.esum[dir][bits]);
  if(u != r.width){
    return false;
  }
  return true;
}
void merge2(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
  lhs = l;
  auto u = r.esum[dir^r.inversed][bits ^ r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.fliped == bits) * r.width;
  lhs.esum[2][bits] += u;
}
void merge3(Gata & lhs, Gata & l, Gata & r, int bits){
  lhs = l;
  auto u = r.esum[2][bits] * (r.filled == -1) + (r.filled >= 0)* (r.filled ^ r.fliped == bits)  * r.width;
  chmax(lhs.esum[2][bits], u);
}
void merge4(Gata & lhs, Gata & l, Gata & r){
  lhs = l;
  lhs.width += r.width;
}
void merge5(Gata & lhs, Gata & l, Gata & r, int bits){
  lhs = l;
  auto u = r.cnt[bits^r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.filled == bits) * r.width;
  lhs.cnt[bits] += u;
}
void flipdata(Gata & x){
  int i;
  x.val ^= 1;
  for(i=(0);i<(3);i++){
    swap(x.esum[i][0], x.esum[i][1]);
  }
  swap(x.cnt[0], x.cnt[1]);
}
void inversedata(Gata & x){
  int i;
  for(i=(0);i<(2);i++){
    swap(x.esum[0][i], x.esum[1][i]);
  }
}
void filldata(Gata & x, int filled){
  int i;
  x.val = filled;
  memset(x.esum, 0, sizeof(x.esum));
  for(i=(0);i<(3);i++){
    x.esum[i][filled] = x.width;
  }
  x.cnt[filled] = x.width;
  x.cnt[filled^1] = 0;
}
class UpdateD{
  public:
  UpdateD(){
  }
  bool check(void * x){
    Trea * me = (Trea *) x;
    return (me->subtreeData.fliped == 0) && (me->subtreeData.inversed == 0) && (me->subtreeData.filled == -1);
  }
  void recalibrate(void * x){
    int bits, i;
    Trea * me = (Trea *) x;
    Gata*subtreeData = &me->subtreeData;
    Gata*data = &me->data;
    subtreeData->width = 0;
    subtreeData->val = 0;
    subtreeData->fliped = 0;
    memset(subtreeData->esum, 0 ,sizeof(subtreeData->esum));
    memset(subtreeData->cnt, 0 ,sizeof(subtreeData->cnt));
    Gata res[20];
    int idx = 0;
    int tidx = 0;
    Gata* trs[10];
    for(i=(0);i<(2);i++){
      auto t = (Trea *)me->kids[i];
      if(t == NULL){
        trs[tidx++] = NULL;
      }
      else{
        trs[tidx++] = &t->subtreeData;
      }
      if(i == 0){
        trs[tidx++] = data;
      }
    }
    for(bits=(0);bits<(2);bits++){
      for(i=(0);i<(3);i++){
        if(trs[i] == NULL){
          continue;
        }
        if(!merge(res[idx], *subtreeData, *trs[i], bits, 0)){
          subtreeData = &res[idx++];
          break;
        }
        subtreeData = &res[idx++];
      }
    }
    for(bits=(0);bits<(2);bits++){
      for(i=(3)-1;i>=(0);i--){
        if(trs[i] == NULL){
          continue;
        }
        if(!merge(res[idx], *subtreeData, *trs[i], bits, 1 )){
          subtreeData = &res[idx++];
          break;
        }
        subtreeData = &res[idx++];
      }
    }
    me->subtreeData = *subtreeData;
    memset(&res[0],0,sizeof(res[0]));
    subtreeData = &res[0];
    idx = 1;
    for(bits=(0);bits<(2);bits++){
      if(bits != data->val){
        continue;
      }
      for(i=(0);i<(3);i++){
        if(trs[i] == NULL){
          continue;
        }
        merge2(res[idx], *subtreeData, *trs[i], bits, i == 0 ? 1 : 0);
        subtreeData = &res[idx++];
      }
      chmax(me->subtreeData.esum[2][bits], subtreeData->esum[2][bits]);
    }
    subtreeData = &me->subtreeData;
    idx = 0;
    for(bits=(0);bits<(2);bits++){
      for(i=(0);i<(3);i++){
        if(trs[i] == NULL){
          continue;
        }
        merge3(res[idx], *subtreeData, *trs[i], bits);
        subtreeData = &res[idx++];
      }
    }
    for(i=(0);i<(3);i++){
      if(trs[i] == NULL){
        continue;
      }
      merge4(res[idx], *subtreeData, *trs[i]);
      subtreeData = &res[idx++];
    }
    me->subtreeData = *subtreeData;
    subtreeData = &me->subtreeData;
    idx = 0;
    for(bits=(0);bits<(2);bits++){
      for(i=(0);i<(3);i++){
        if(trs[i] == NULL){
          continue;
        }
        merge5(res[idx], *subtreeData, *trs[i], bits);
        subtreeData = &res[idx++];
      }
    }
    me->subtreeData = *subtreeData;
    me->subtreeSize = 1;
    for(i=(0);i<(2);i++){
      auto t = (Trea *) me->kids[i];
      if(t == NULL){
        continue;
      }
      me->subtreeSize += t->subtreeSize;
    }
  }
  void propagate(void * x){
    Trea * me = (Trea *) x;
    if(me->subtreeData.fliped){
      int i;
      flipdata(me->data);
      me->subtreeData.fliped = 0;
      for(i=(0);i<(2);i++){
        auto t = (Trea *) me->kids[i];
        if(t == NULL){
          continue;
        }
        t->subtreeData.fliped ^= 1;
      }
    }
    if(me->subtreeData.filled != -1){
      int i;
      filldata(me->data, me->subtreeData.filled);
      for(i=(0);i<(2);i++){
        auto t = (Trea *) me->kids[i];
        if(t == NULL){
          continue;
        }
        t->subtreeData.filled = me->subtreeData.filled;
      }
      me->subtreeData.filled = -1;
    }
    if(me->subtreeData.inversed == 1){
      int i;
      inversedata(me->data);
      swap(me->kids[0], me->kids[1]);
      for(i=(0);i<(2);i++){
        auto t = (Trea *) me->kids[i];
        if(t == NULL){
          continue;
        }
        t->subtreeData.inversed ^= 1;
      }
      me->subtreeData.inversed = 0;
    }
  }
}
;
TMaster treap;
Trea * root;
int n;
int q;
int queries[400000+10][3];
char s[400000+10];
int main(){
  int i;
  wmem = memarr;
  treap.reset(400000+10);
  root = NULL;
  rd(n);
  rd(q);
  {
    int mh1PDLat;
    for(mh1PDLat=(0);mh1PDLat<(n);mh1PDLat++){
      rd(s[mh1PDLat]);
    }
  }
  {
    int xMwilYvQ;
    int P1jAuWt8;
    for(xMwilYvQ=(0);xMwilYvQ<(q);xMwilYvQ++){
      for(P1jAuWt8=(0);P1jAuWt8<(3);P1jAuWt8++){
        rd(queries[xMwilYvQ][P1jAuWt8]);
      }
    }
  }
  for(i=(0);i<(n);i++){
    s[i] = s[i] - '0';
  }
  for(i=(0);i<(n);i++){
    Gata tmp(s[i]);
    root = (Trea *)treap.merge(root,treap.get_new_node(tmp, i+1));
  }
  for(i=(0);i<(q);i++){
    int type;
    int l;
    int r;
    auto dMqNLGkZ = ((queries[i][0]));
    auto hFCgbKbG = ((queries[i][1]));
    auto IDaYkpTg = ((queries[i][2]));
    type=dMqNLGkZ;
    l=hFCgbKbG;
    r=IDaYkpTg;
    --l;
    --r;
    void* parts1[3];
    void* parts2[3];
    treap.split(parts1,root, l);
    treap.split(parts2, parts1[1], r-l+1);
    auto t = (Trea *)parts2[0];
    treap.prop(t);
    if(type == 1){
      t->subtreeData.fliped ^= 1;
    }
    else if(type == 2){
      t->subtreeData.inversed ^= 1;
    }
    else{
      int u = t->subtreeData.cnt[0];
      if(u != 0 && u != t->subtreeData.width){
        void* parts3[3];
        treap.split(parts3, parts2[0], u);
        treap.prop(parts3[0]);
        treap.prop(parts3[1]);
        auto t1 = (Trea *)parts3[0];
        t1->subtreeData.filled = 0;
        auto t2 = (Trea *)parts3[1];
        t2->subtreeData.filled = 1;
        parts2[0] = treap.merge(parts3[0], parts3[1]);
      }
    }
    root=(Trea *)treap.merge(parts1[0], treap.merge(parts2[0], parts2[1]));
    int ans =max_L(root->subtreeData.esum[2][0], root->subtreeData.esum[2][1]);
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=200m
// #include <random>
// #include <cstring>
// #define Treap TreapDa<Data>
// /*Treap Data*/
// template<class Data>
// class TreapDa {
// public: 
//   int priority, id, subtreeSize;
//   Data data, subtreeData;
//   void** kids;
//   void* par;
//   TreapDa(){
//     priority = 0;
//     id = 0;
//     subtreeSize = 0;
//     data = subtreeData = NULL; 
//     kids = NULL;
//     par = NULL;
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
//   void setparent(void * a, void * b){
//       if(b == NULL) return;
//       auto tb = (Treap*)b;
//       tb->par = a;
//   }
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
//     walloc1d(&root->kids, 2);
//     root->kids[0] = root->kids[1] = 0;
//     this->recalc(root);
//     return (void*)root;
//   }  
//   void * getparent(void * x){
//     auto me = (Treap*) x;
//     while(me->par) me =  (Treap*)me->par;
//     return me; 
//   }
//   void split(void ** res, void * x, int nInLeft) {
//     auto me = (Treap*) x;
//     res[0] = res[1] = NULL;
//     if (me==NULL) return ;
//     this->prop(me);
//     if (this->size(me->kids[0])>=nInLeft) {
//       void * leftRes[2];
//       setparent(NULL, me->kids[0]);
//       this->split(leftRes, me->kids[0], nInLeft);
//       setparent(me , leftRes[1]);
//       me->kids[0]=leftRes[1];
//       this->recalc(me);
//       res[0] = leftRes[0]; res[1] = me;
//       return;
//     }
//     else {
//       nInLeft=nInLeft-(this->size(me->kids[0]))-1;
//       void * rightRes[2];
//       setparent(NULL, me->kids[1]);
//       this->split(rightRes, me->kids[1], nInLeft);
//       me->kids[1]=rightRes[0];
//       setparent(me , rightRes[0]);
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
//       setparent(NULL, l->kids[1]);
//       l->kids[1]=this->merge(l->kids[1], r);
//       setparent(l , l->kids[1]);
//       this->recalc(l);
//       return l;
//     }
//     else {
//       setparent(NULL, r->kids[0]);
//       r->kids[0]=this->merge(l, r->kids[0]);
//       setparent(r , r->kids[0]);
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
// /*Our Data stored in each node in the Treap*/
// 
// class Gata{
// public:
//   int val;
//   int fliped;
//   int esum[3][2];
//   int cnt[2];
//   int width;
//   int inversed;
//   int filled;
//   Gata(){
//     filled = -1;
//     val = 0;
//     inversed = 0;
//     width = 0;
//     fliped = 0;
//     memset(esum, 0 ,sizeof(esum));
//     memset(cnt, 0 ,sizeof(cnt));
//   }
//   Gata(char s){
//     val = s;
//     filled = -1;
//     inversed = 0;
//     width = 1;
//     fliped = 0;
//     memset(esum, 0 ,sizeof(esum));
//     memset(cnt, 0 ,sizeof(cnt));
//     rep(i, 3) esum[i][val] = 1;
//     cnt[val] = 1;
//   }
// };
// 
// 
// 
// #define Trea TreapDa<Gata>
// #define TMaster TreapOp<RDevice,Gata,UpdateD>
// 
// bool merge(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
//     lhs = l;
//     auto u = r.esum[dir^r.inversed][bits^r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.fliped == bits) * r.width;
//     lhs.esum[dir][bits] += u;
//     lhs.esum[2][bits] >?= lhs.esum[dir][bits]; 
//     if(u != r.width) return false;
//     return true;
// }
// 
// 
// void merge2(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
//     lhs = l;
//     auto u = r.esum[dir^r.inversed][bits ^ r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.fliped == bits) * r.width;
//     lhs.esum[2][bits] += u;
// }
// 
// void merge3(Gata & lhs, Gata & l, Gata & r, int bits){
//     lhs = l;
//     auto u = r.esum[2][bits] * (r.filled == -1) + (r.filled >= 0)* (r.filled ^ r.fliped == bits)  * r.width;
//     lhs.esum[2][bits] >?= u;
// }
// 
// void merge4(Gata & lhs, Gata & l, Gata & r){
//     lhs = l;
//     lhs.width += r.width;
// }
// 
// void merge5(Gata & lhs, Gata & l, Gata & r, int bits){
//     lhs = l;
//     auto u = r.cnt[bits^r.fliped] * (r.filled == -1) + (r.filled >= 0) * (r.filled ^ r.filled == bits) * r.width;
//     lhs.cnt[bits] += u;
// }
// 
// 
// void flipdata(Gata & x){
//     x.val ^= 1;
//     rep(i, 3) swap(x.esum[i][0], x.esum[i][1]);
//     swap(x.cnt[0], x.cnt[1]);
// }
// 
// void inversedata(Gata & x){
//     rep(i, 2) swap(x.esum[0][i], x.esum[1][i]);
// }
// 
// void filldata(Gata & x, int filled){
//     x.val = filled;
//     memset(x.esum, 0, sizeof(x.esum));
//     rep(i, 3) x.esum[i][filled] = x.width;
//     x.cnt[filled] = x.width;
//     x.cnt[filled^1] = 0;
// }
// 
// class UpdateD{
// public:
//   UpdateD(){
// 
//   }
//   bool check(void * x){
//     Trea * me = (Trea *) x;
//     return (me->subtreeData.fliped == 0) && (me->subtreeData.inversed == 0) && (me->subtreeData.filled == -1);
//   }
//   void recalibrate(void * x){
//     Trea * me = (Trea *) x;
//     Gata *subtreeData = &me->subtreeData, *data = &me->data;
//     subtreeData->width = 0;
//     subtreeData->val = 0;
//     subtreeData->fliped = 0;
//     memset(subtreeData->esum, 0 ,sizeof(subtreeData->esum));
//     memset(subtreeData->cnt, 0 ,sizeof(subtreeData->cnt));
//     Gata res[20];
//     int idx = 0, tidx = 0;
//     Gata * trs[10];
//     rep(i,2){
//         auto t = (Trea *)me->kids[i];
//         if(t == NULL)
//             trs[tidx++] = NULL;
//         else
//             trs[tidx++] = &t->subtreeData;
//         if(i == 0){
//             trs[tidx++] = data;
//         } 
//     }
//     rep(bits, 2){
//         rep(i,3){
//             if(trs[i] == NULL) continue;
//             if(!merge(res[idx], *subtreeData, *trs[i], bits, 0)){
//                 subtreeData = &res[idx++];
//                  break;
//             }
//             subtreeData = &res[idx++];
//         }
//     }
//     rep(bits, 2){
//         rrep(i,3){
//             if(trs[i] == NULL) continue;
//             if(!merge(res[idx], *subtreeData, *trs[i], bits, 1 )){
//                  subtreeData = &res[idx++];
//                  break;
//             }
//             subtreeData = &res[idx++];
//         }
//     }
//     me->subtreeData = *subtreeData; //cache in
//     memset(&res[0],0,sizeof(res[0]));
//     subtreeData = &res[0];
//     idx = 1;
//     rep(bits, 2){
//         if(bits != data->val) continue;
//         rep(i,3){
//             if(trs[i] == NULL) continue;
//             merge2(res[idx], *subtreeData, *trs[i], bits, i == 0 ? 1 : 0);
//             subtreeData = &res[idx++];
//         }
//         me->subtreeData.esum[2][bits] >?= subtreeData->esum[2][bits];
//         
//     }
//     subtreeData = &me->subtreeData; //cache out
//     idx = 0;
//     rep(bits, 2){
//         rep(i,3){
//             if(trs[i] == NULL) continue;
//             merge3(res[idx], *subtreeData, *trs[i], bits);
//             subtreeData = &res[idx++];
//         
//         }
//        
//     }
//     rep(i, 3){
//         if(trs[i] == NULL) continue;
//         merge4(res[idx], *subtreeData, *trs[i]);
//         subtreeData = &res[idx++];
//     }
//     me->subtreeData = *subtreeData; //cache in
//     subtreeData = &me->subtreeData; //cache out
//     idx = 0;
//     rep(bits, 2){
//         rep(i,3){
//             if(trs[i] == NULL) continue;
//             merge5(res[idx], *subtreeData, *trs[i], bits);
//             subtreeData = &res[idx++];
//         
//         }  
//     }
//     me->subtreeData = *subtreeData;
//     me->subtreeSize = 1;
//     rep(i,0,2){
//       auto t = (Trea *) me->kids[i];
//       if(t == NULL) continue;
//       me->subtreeSize += t->subtreeSize;
//     }
//   }
//   void propagate(void * x){
//     Trea * me = (Trea *) x;
//     if(me->subtreeData.fliped){
//         flipdata(me->data);
//         me->subtreeData.fliped = 0;
//         rep(i, 2){
//             auto t = (Trea *) me->kids[i];
//             if(t == NULL) continue;
//             t->subtreeData.fliped ^= 1;
//         }
//     }
//     if(me->subtreeData.filled != -1){
//         filldata(me->data, me->subtreeData.filled);
//     
//         rep(i, 2){
//             auto t = (Trea *) me->kids[i];
//             if(t == NULL) continue;
//             t->subtreeData.filled = me->subtreeData.filled;
//         }
//         me->subtreeData.filled = -1;
//     }
//     if(me->subtreeData.inversed == 1){
//         inversedata(me->data);
//         swap(me->kids[0], me->kids[1]);
//         rep(i,2){
//             auto t = (Trea *) me->kids[i];
//             if(t == NULL) continue;
//             t->subtreeData.inversed ^= 1;
//         }
//         me->subtreeData.inversed = 0;
//     }
//   }
// };
// 
// 
// 
// TMaster treap;
// Trea * root;
// int n,q, queries[4d5+10][3];
// char s[4d5+10];
// {
//     treap.reset(4d5+10);
//     root = NULL;
//     rd(n,q, s(n), queries(q,3));
//     rep(i, n) s[i] = s[i] - '0';
//     rep(i, n){
//         Gata tmp(s[i]);       
//         root = (Trea *)treap.merge(root,treap.get_new_node(tmp, i+1));
//     }
//     rep(i, q){
//         int type, l, r;
//         (type, l, r) = (queries[i][0],queries[i][1],queries[i][2]);
//         --l; --r;
//         void * parts1[3], * parts2[3];
//         treap.split(parts1,root, l);
//         treap.split(parts2, parts1[1], r-l+1);
//         auto t = (Trea *)parts2[0];
//         treap.prop(t);
//         if(type == 1){
//             t->subtreeData.fliped ^= 1;
//         }else if(type == 2){
//             t->subtreeData.inversed ^= 1;
//         }else{
//             int u = t->subtreeData.cnt[0];
//             if(u != 0 && u != t->subtreeData.width){
//                 void * parts3[3];
//                 treap.split(parts3, parts2[0], u);
//                 treap.prop(parts3[0]);
//                 treap.prop(parts3[1]);
//                 auto t1 = (Trea *)parts3[0];
//                 t1->subtreeData.filled = 0;
//                 auto t2 = (Trea *)parts3[1];
//                 t2->subtreeData.filled = 1;
//                 parts2[0] = treap.merge(parts3[0], parts3[1]);
//             }
//         }
//     
//         root=(Trea *)treap.merge(parts1[0], treap.merge(parts2[0], parts2[1]));
//         
// 
//         int ans = max(root->subtreeData.esum[2][0], root->subtreeData.esum[2][1]);
//         wt(ans);
//     }
// }
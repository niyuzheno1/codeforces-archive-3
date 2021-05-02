#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
class Gata{
  public:
  int val;
  Gata(){
    val = 0;
  }
  Gata(int s){
    val = s;
  }
}
;
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
    for(i=(0);i<(2);i++){
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
int ans[500000+10];
int asz;
void showall(void * x){
  auto t =  (Trea *)x;
  if(t == NULL){
    return;
  }
  int u = t->data.val;
  showall(t->kids[0]);
  ans[asz] = u;
  ++asz;
  showall(t->kids[1]);
}
void show(void * x){
  asz = 0;
  showall(x);
  {
    int FJNsjZ7B;
    if(asz==0){
      wt_L('\n');
    }
    else{
      for(FJNsjZ7B=(0);FJNsjZ7B<(asz-1);FJNsjZ7B++){
        wt_L(ans[FJNsjZ7B]);
        wt_L(' ');
      }
      wt_L(ans[FJNsjZ7B]);
      wt_L('\n');
    }
  }
}
int n;
int q;
TMaster treap;
int idx;
int Q[500000+20][2];
int main(){
  wmem = memarr;
  treap.reset(500000+10);
  rd(n);
  {
    int Z8lEHcvz;
    int rbGYC8dh;
    for(Z8lEHcvz=(0);Z8lEHcvz<(n);Z8lEHcvz++){
      for(rbGYC8dh=(0);rbGYC8dh<(2);rbGYC8dh++){
        rd(Q[Z8lEHcvz][rbGYC8dh]);
      }
    }
  }
  Trea * root = NULL;
  for(int i = 0; i < n; ++i){
    Gata tmp(i+1);
    root = (Trea *)treap.merge(root, treap.get_new_node(tmp, idx++));
  }
  for (int i=0; i<n; i++){
    int a = Q[i][0];
    int b = Q[i][1];
    --a;
    --b;
    if(b-a <= 0){
      continue;
    }
    if(b-a <= n-b){
      int x = b-a;
      void* parts1[2];
      void* parts2[2];
      void* parts3[2];
      treap.split(parts1, root, a);
      treap.split(parts2, parts1[1], x);
      treap.split(parts3, parts2[1], x);
      root = (Trea *) treap.merge( treap.merge( parts1[0], parts3[0]), treap.merge( parts2[0] , parts3[1] ) );
    }
    else{
      int le = (n-a) - 2*(n-b);
      int x = n-b;
      void* parts1[2];
      void* parts2[2];
      void* parts3[2];
      treap.split(parts1, root, a);
      treap.split(parts2, parts1[1], x);
      treap.split(parts3, parts2[1], le);
      root = (Trea *) treap.merge( treap.merge( parts1[0], parts3[1]), treap.merge( parts3[0] , parts2[0] ) );
    }
  }
  show(root);
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
// /*Our Data stored in each node in the Treap*/
// 
// class Gata{
// public:
//   int val;
//   Gata(){
//       val = 0;
//   }
//   Gata(int s){
//       val = s;
//   }
//   
// };
// 
// 
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
//     rep(i,0,2){
//       auto t = (Trea *) me->kids[i];
//       if(t == NULL) continue;
//       me->subtreeSize += t->subtreeSize;
//     }
// 
//   }
//   void propagate(void * x){
//     
//   }
// };
// 
// int ans[5d5+10], asz;
// void showall(void * x){
//   auto t =  (Trea *)x;
//   if(t == NULL) return;
//   int u = t->data.val;
//   showall(t->kids[0]);
//   ans[asz] = u; 
//   ++asz;
//   showall(t->kids[1]);
// }
// 
// void show(void * x){
//     asz = 0;
//     showall(x);
//     wt(ans(asz));
// }
// 
// int n,q;
// TMaster treap;
// int idx;
// int Q[5d5+20][2];
// {
//  
//     treap.reset(5d5+10);
//     rd(n, Q(n,2));
//     Trea * root = NULL;
//     for(int i = 0; i < n; ++i){
//         Gata tmp(i+1);
//         root = (Trea *)treap.merge(root, treap.get_new_node(tmp, idx++));
//     }
//     for (int i=0; i<n; i++) {
//         int a = Q[i][0], b = Q[i][1];
//         --a; --b;
//         if(b-a <= 0) continue;
//         if(b-a <= n-b){
//             int x = b-a;
//             void * parts1[2],* parts2[2], * parts3[2];
//             treap.split(parts1, root, a);
//             treap.split(parts2, parts1[1], x);
//             treap.split(parts3, parts2[1], x);
//             
//             root = (Trea *) treap.merge( treap.merge( parts1[0], parts3[0]), treap.merge( parts2[0] , parts3[1] ) );
//             
//         }else{
//             int le = (n-a) - 2*(n-b);
//             int x = n-b;
//             void * parts1[2],* parts2[2], * parts3[2];
//             treap.split(parts1, root, a);
//             treap.split(parts2, parts1[1], x);
//             
//             treap.split(parts3, parts2[1], le);
//             root = (Trea *) treap.merge( treap.merge( parts1[0], parts3[1]), treap.merge( parts3[0] , parts2[0] ) );
//         }
//     }
//     
//         show(root);
// }
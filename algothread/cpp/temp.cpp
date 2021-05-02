//no-unlocked
//working_memory=200m
#include <random>
#define Treap TreapDa<Data>
/*Treap Data*/
template<class Data>
class TreapDa {
public: 
  int priority, id, subtreeSize;
  Data data, subtreeData;
  void** kids;
  TreapDa(){
    priority = 0;
    id = 0;
    subtreeSize = 0;
    data = subtreeData = NULL; 
    kids = NULL;
  }
};

/*Treap Operations*/
template<class RandomDevice, class Data, class UpdateData>
class TreapOp {
  RandomDevice * rande;
  UpdateData * upda;
  void * node_pool;
  int cur, lmt;

public:
  void reset(int nsz){
      Treap * tmp_node_pool = NULL;
      walloc1d(&tmp_node_pool, nsz);
      node_pool = (void*)tmp_node_pool;
      cur = 0;
      lmt = nsz;
  } 
  void * allocate_new_node(){
      if(cur >= lmt) reset(lmt<<1);
      Treap * tmp_node_pool = (Treap * )node_pool;
      return (void*)&tmp_node_pool[cur++];
  }
  
  TreapOp(){
    cur = 0; lmt = 0;
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
  void split(void ** res, void * x, int nInLeft) {
    auto me = (Treap*) x;
    res[0] = res[1] = NULL;
    if (me==NULL) return ;
    this->prop(me);
    if (this->size(me->kids[0])>=nInLeft) {
      void * leftRes[2];
      this->split(leftRes, me->kids[0], nInLeft);
      me->kids[0]=leftRes[1];
      this->recalc(me);
      res[0] = leftRes[0]; res[1] = me;
      return;
    }
    else {
      nInLeft=nInLeft-(this->size(me->kids[0]))-1;
      void * rightRes[2];
      this->split(rightRes, me->kids[1], nInLeft);
      me->kids[1]=rightRes[0];
      this->recalc(me);
      res[0] = (void *)me; res[1] = (void *)rightRes[1];
      return;
    }
  }
    
  
  void * merge(void * lll, void * rrr) {
    auto l = (Treap*) lll;
    auto r = (Treap*) rrr;
    if (l==NULL) return r;
    if (r==NULL) return l;
    this->prop(l); this->prop(r);
    if (l->priority<r->priority) {
      l->kids[1]=this->merge(l->kids[1], r);
      this->recalc(l);
      return l;
    }
    else {
      r->kids[0]=this->merge(l, r->kids[0]);
      this->recalc(r);
      return r;
    }
  }
  
  
  //MUST CALL PROP BEFORE RECALCING!
  void recalc(void * x) {
    auto me = (Treap*) x;
    if (me==NULL) return;
    assert(upda->check((void*)me)); // sanitation check
    upda->recalibrate((void*)me);
  }
  void prop(void * x) {
    auto me = (Treap*) x;
    if (me==NULL) return;
    //reset subtreedata max in recalc
    upda->propagate((void*)me);
    this->recalc(me);
  }
  int size(void * x) {
    auto t = (Treap*) x;
    if(t == NULL) return 0;
    return t->subtreeSize;
  }  
};

/*Random Device is here */

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
};

mint pw[8d5+10];
/*Our Data stored in each node in the Treap*/

class Gata{
public:
  mint ls,rs;
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
  
};

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
    Trea * me = (Trea *) x;
    me->subtreeSize = 1;
    //intitialize our data
    Gata *subtreeData = &me->subtreeData, *data = &me->data;
    data->width = 1;
    data->ls = data->rs;
    subtreeData->width = 0;
    subtreeData->ls = 0;
    subtreeData->rs = 0;
    Gata res[10];
    //merge between subtrees
    rep(i,0,2){
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
    rrep(i,0,2){
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
      if(t == NULL) continue;
      me->subtreeSize += t->subtreeSize;
    }
    //assert( !( (me->subtreeData.ls != 0 && me->subtreeData.rs == 0 ) || (me->subtreeData.ls == 0 && me->subtreeData.rs != 0 ) ));
  }
  void propagate(void * x){
    
  }
};


void showall(void * x){
  auto t =  (Trea *)x;
  if(t == NULL) return;
  int u = t->data.ls;
  char v = (char)u;
  v+='a';
  showall(t->kids[0]);
  cout << v;
  showall(t->kids[1]);
}

int n,q;
char a[7d5+10];
TMaster treap;
mint pp;
int idx;

{
    pp = 31;
    pw[0] = 1;
    pw[1] = pp;
 
    treap.reset(8d5);
    rd(n, q, a(n));
    rep(i, 2, n+q+2)  pw[i] = pw[i-1]*pp;
    rep(i,3d5+n) a[i] = a[i]-'a';
    Trea * root = NULL;
    for(int i = 0; i < n; ++i){
        Gata tmp(a[i]);
        root = (Trea *)treap.merge(root, treap.get_new_node(tmp, idx++));
    }
    for (int qq=0; qq<q; qq++) {
        int @type; 
        if (type==1) {
            int @l, @r;
            --l; --r;
            assert(l<=r);
            void * parts1[2];
            void * parts2[2];
            treap.split(parts1,root, l);
            treap.split(parts2,parts1[1], r-l+1); 
            root=(Trea *)treap.merge(parts1[0], parts2[1]);
        }
        else if(type == 2){
            char c[4];
            int p;
            rd(c,p);
            --p;
            void * parts1[2];
            treap.split(parts1,root, p);
            Gata tmp(c[0]-'a');
            auto node = treap.get_new_node(tmp, idx++);
            root = (Trea *)treap.merge(parts1[0], treap.merge( node, parts1[1]));
        }else{
            int @l, @r;
            --l; --r;
            void * parts1[2];
            void * parts2[2];
            treap.split(parts1,root, l);
            treap.split(parts2,parts1[1], r-l+1); 
            Trea * t1 = (Trea * )parts2[0];
            if(t1->subtreeData.ls == t1->subtreeData.rs){
                wt("yes");
            }else{
                wt("no");
            }
            root = (Trea *)treap.merge(parts1[0], treap.merge( parts2[0], parts2[1]));
           
        }
        
    }
}
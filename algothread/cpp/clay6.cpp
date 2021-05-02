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
  void* par;
  TreapDa(){
    priority = 0;
    id = 0;
    subtreeSize = 0;
    data = subtreeData = NULL; 
    kids = NULL;
    par = NULL;
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
  void setparent(void * a, void * b){
      if(b == NULL) return;
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
  void * getparent(void * x){
    auto me = (Treap*) x;
    while(me->par) me =  (Treap*)me->par;
    return me; 
  }
  void split(void ** res, void * x, int nInLeft) {
    auto me = (Treap*) x;
    res[0] = res[1] = NULL;
    if (me==NULL) return ;
    this->prop(me);
    if (this->size(me->kids[0])>=nInLeft) {
      void * leftRes[2];
      setparent(NULL, me->kids[0]);
      this->split(leftRes, me->kids[0], nInLeft);
      setparent(me , leftRes[1]);
      me->kids[0]=leftRes[1];
      this->recalc(me);
      res[0] = leftRes[0]; res[1] = me;
      return;
    }
    else {
      nInLeft=nInLeft-(this->size(me->kids[0]))-1;
      void * rightRes[2];
      setparent(NULL, me->kids[1]);
      this->split(rightRes, me->kids[1], nInLeft);
      me->kids[1]=rightRes[0];
      setparent(me , rightRes[0]);
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
      setparent(NULL, l->kids[1]);
      l->kids[1]=this->merge(l->kids[1], r);
      setparent(l , l->kids[1]);
      this->recalc(l);
      return l;
    }
    else {
      setparent(NULL, r->kids[0]);
      r->kids[0]=this->merge(l, r->kids[0]);
      setparent(r , r->kids[0]);
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
/*Our Data stored in each node in the Treap*/

class Gata{
public:
  ll val;
  ll sumval;
  Gata(){
      val = 0;
  }
  Gata(ll s){
      val = s;
      sumval = s;
  }
};



#define Trea TreapDa<Gata>
#define TMaster TreapOp<RDevice,Gata,UpdateD>

void merge1(Gata & lhs, Gata & l, Gata & r){
    lhs = l;
    lhs.sumval += r.sumval;
}

class UpdateD{
public:
  UpdateD(){

  }
  bool check(void * x){
    return true;
  }
  void recalibrate(void * x){
    Trea * me = (Trea *) x;
    Gata *subtreeData = &me->subtreeData, *data = &me->data;
    data->sumval = data->val;
    subtreeData->sumval = 0;
    Gata res[10];
    int idx = 0, tidx = 0;
    Gata * trs[10];
    rep(i,2){
        auto t = (Trea *)me->kids[i];
        if(t == NULL)
            trs[tidx++] = NULL;
        else
            trs[tidx++] = &t->subtreeData;
        if(i == 0){
            trs[tidx++] = data;
        } 
    }
    rrep(i,2){
        auto t = (Trea *)me->kids[i];
        if(t == NULL)
            trs[tidx++] = NULL;
        else
            trs[tidx++] = &t->subtreeData;
        if(i == 1){
            trs[tidx++] = data;
        } 
    }
    rep(i,3){
        if(trs[i] == NULL) continue;
        merge1(res[idx], *subtreeData, *trs[i] );
        subtreeData = &res[idx++];
    }

    me->subtreeData = *subtreeData;
    me->subtreeSize = 1;
    rep(i,0,2){
      auto t = (Trea *) me->kids[i];
      if(t == NULL) continue;
      me->subtreeSize += t->subtreeSize;
    }
  }
  void propagate(void * x){
    
  }
};

int ans[5d5+10], asz;
void showall(void * x){
  auto t =  (Trea *)x;
  if(t == NULL) return;
  int u = t->data.val;
  showall(t->kids[0]);
  ans[asz] = u; 
  ++asz;
  showall(t->kids[1]);
}

void show(void * x){
    asz = 0;
    showall(x);
    wt(ans(asz));
}

int n,q;
TMaster treap;
void * nodes[5d5+10];
{
 
    treap.reset(5d5+10);
    rd(n);
    rep(i,1, n+1){
        int @type;
        if(type == 1){
            int @y;
            Gata tmp(y);
            nodes[i] = treap.get_new_node(tmp,y);
        }else if(type == 2){
            int @y, @z;
            auto u = treap.getparent(nodes[y]);
            auto v = treap.getparent(nodes[z]);
            if(u == v) continue;
            u = treap.merge((void*)u,(void*)v);
        }else if(type == 3){
            int @y, @z;
            auto u = (Trea*)treap.getparent(nodes[y]);
            if(u->subtreeSize <= z) continue;
            void * res[2];
            treap.split(res, u, z);
        }else{
            int @y;
            auto u = (Trea*)treap.getparent(nodes[y]);
            wt(u->subtreeData.sumval);
        }
    }
}
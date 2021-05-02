//no-unlocked
//working_memory=200m
#include <random>
#include <cstring>
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
#define Treap TreapDa<Data>
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
  int val;
  int fliped;
  int esum[3][2];
  int width;
  Gata(){
    val = 0;
    width = 0;
    fliped = 0;
    memset(esum, 0 ,sizeof(esum));
  }
  Gata(char s){
    val = s;
    width = 1;
    fliped = 0;
    memset(esum, 0 ,sizeof(esum));
    rep(i, 3) esum[i][val] = 1;
  }
};



#define Trea TreapDa<Gata>
#define TMaster TreapOp<RDevice,Gata,UpdateD>

bool merge(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
    lhs = l;
    auto u = r.esum[dir][bits^r.fliped];
    lhs.esum[dir][bits] += u;
    lhs.esum[2][bits] >?= lhs.esum[dir][bits]; 
    if(u != r.width) return false;
    return true;
}


void merge2(Gata & lhs, Gata & l, Gata & r, int bits, int dir){
    lhs = l;
    auto u = r.esum[dir][bits ^ r.fliped];
    lhs.esum[2][bits] += u;
}

void merge3(Gata & lhs, Gata & l, Gata & r, int bits){
    lhs = l;
    auto u = r.esum[2][bits];
    lhs.esum[2][bits] >?= r.esum[2][bits];
}

void merge4(Gata & lhs, Gata & l, Gata & r){
    lhs = l;
    lhs.width += r.width;
}


void flipdata(Gata & x){
    x.val ^= 1;
    rep(i, 3) swap(x.esum[i][0], x.esum[i][1]);
}

class UpdateD{
public:
  UpdateD(){

  }
  bool check(void * x){
    Trea * me = (Trea *) x;
    return (me->subtreeData.fliped == 0);
  }
  void recalibrate(void * x){
    Trea * me = (Trea *) x;
    Gata *subtreeData = &me->subtreeData, *data = &me->data;
    subtreeData->width = 0;
    subtreeData->val = 0;
    subtreeData->fliped = 0;
    memset(subtreeData->esum, 0 ,sizeof(subtreeData->esum));
    Gata res[20];
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
    rep(bits, 2){
        rep(i,3){
            if(trs[i] == NULL) continue;
            if(!merge(res[idx], *subtreeData, *trs[i], bits, 0)){
                subtreeData = &res[idx++];
                 break;
            }
            subtreeData = &res[idx++];
        }
    }
    rep(bits, 2){
        rrep(i,3){
            if(trs[i] == NULL) continue;
            if(!merge(res[idx], *subtreeData, *trs[i], bits, 1 )){
                 subtreeData = &res[idx++];
                 break;
            }
            subtreeData = &res[idx++];
        }
    }
    me->subtreeData = *subtreeData; //cache in
    memset(&res[0],0,sizeof(res[0]));
    subtreeData = &res[0];
    idx = 1;
    rep(bits, 2){
        if(bits != data->val) continue;
        rep(i,3){
            if(trs[i] == NULL) continue;
            merge2(res[idx], *subtreeData, *trs[i], bits, i == 0 ? 1 : 0);
            subtreeData = &res[idx++];
        }
        me->subtreeData.esum[2][bits] >?= subtreeData->esum[2][bits];
        
    }
    subtreeData = &me->subtreeData; //cache out
    idx = 0;
    rep(bits, 2){
        rep(i,3){
            if(trs[i] == NULL) continue;
            merge3(res[idx], *subtreeData, *trs[i], bits);
            subtreeData = &res[idx++];
        
        }
       
    }
    rep(i, 3){
        if(trs[i] == NULL) continue;
        merge4(res[idx], *subtreeData, *trs[i]);
        subtreeData = &res[idx++];
    }
    me->subtreeData = *subtreeData; //cache in
    me->subtreeSize = 1;
    rep(i,0,2){
      auto t = (Trea *) me->kids[i];
      if(t == NULL) continue;
      me->subtreeSize += t->subtreeSize;
    }
  }
  void propagate(void * x){
    Trea * me = (Trea *) x;
    if(me->subtreeData.fliped){
        flipdata(me->data);
        me->subtreeData.fliped = 0;
        rep(i, 2){
            auto t = (Trea *) me->kids[i];
            if(t == NULL) continue;
            t->subtreeData.fliped ^= 1;
        }

    }
  }
};



TMaster treap;
Trea * root;
int n,q, queries[4d5+10][3];
char s[4d5+10];
{
    treap.reset(4d5+10);
    root = NULL;
    rd(n,q, s(n), queries(q,3));
    rep(i, n) s[i] = s[i] - '0';
    rep(i, n){
        Gata tmp(s[i]);       
        root = (Trea *)treap.merge(root,treap.get_new_node(tmp, i+1));
    }
    rep(i, q){
        int type, l, r;
        (type, l, r) = (queries[i][0],queries[i][1],queries[i][2]);
        --l; --r;
        if(type == 1){
            void * parts1[3], * parts2[3];
            treap.split(parts1,root, l);
            treap.split(parts2, parts1[1], r-l+1);
            auto t = (Trea *)parts2[0];
            t->subtreeData.fliped ^= 1;
            root=(Trea *)treap.merge(parts1[0], treap.merge(parts2[0], parts2[1]));
        }
        int ans = max(root->subtreeData.esum[2][0], root->subtreeData.esum[2][1]);
        wt(ans);
    }
}
//no-unlocked
//working_memory=100m
template<class EnterExit> 
class sqrt_decomp{    
public:
    EnterExit * a;
    int * L, * R, * E,  * IDX;
    int qsz, lmt, blocksz, _init, cur, solid_state, _update; 
    void init(bool enable_wmem, int isupdated){
        _update = 0;
        _init = 1;
        if(isupdated) {
            _update = 1;
        }
        if(enable_wmem){
            walloc1d(&L, qsz, &wmem);
            walloc1d(&R, qsz, &wmem);
            if(isupdated) walloc1d(&E, qsz, &wmem);
            walloc1d(&IDX, qsz, &wmem);
            this->solid_state = 1;
        }else{
            L = new int[qsz];
            R = new int[qsz];
            if(isupdated) E = new int[qsz];
            IDX = new int[qsz];
            this->solid_state = 0;
        }
        rep(i, 0, qsz) L[i] = R[i]   = 0;
        if(isupdated) E[i] = 0;
    }
    sqrt_decomp(){
        a = new EnterExit();
        this-> _init = 0;
    }
    void sinit(int qsz, int blocksz, int allow_update){
        if(this->_init) return;
        this->cur = 0;
        this->qsz = qsz;
        this->blocksz = blocksz;
        this->lmt = 0;
        this->solid_state = 0;
        init(true, allow_update);
    }
    void hinit(int qsz, int blocksz, int allow_update){
        if(this->_init) return;
        this-> _init = 0;
        this->cur = 0;
        this->qsz = qsz;
        this->blocksz = blocksz;
        this->lmt = 0;
        this->solid_state = 0;
        init(false, allow_update);
    }
    void clear(){
        if(!this->solid_state && this->_init){
            this->_init = 0;
            delete [] L;
            delete [] R;
            if(_update) delete [] E;
            delete [] IDX;
            L = R = E = IDX = NULL;
        }
    }
    
    ~sqrt_decomp(){
        delete a;  
        clear();
    }
    void transfer(int sz, int * L, int * R, int * E){
        rep(i, 0, sz)  this->IDX[i] = i;
        if(E != NULL){
            _update = 1;
        }
        if(!_update){
            sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                return R[lhs] < R[rhs];
            });
        }
        else{
            sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                if(R[lhs]/blocksz != R[rhs]/blocksz) return R[lhs] < R[rhs];
                return E[lhs] < E[rhs];
            });
        }
        rep(i, 0, sz){
            this->L[i] = L[this->IDX[i]];
            this->R[i] = R[this->IDX[i]];
        }
        if(_update) rep(i, 0, sz) this->E[i] = E[this->IDX[i]];
        this->cur = 0;
        this->lmt = sz;
    }
    int next(int & l, int & r, int & cl, int & cr){
        if(this->cur >= this->lmt) return -1;
        int i = this->cur;
        while(l < L[i]) a->change(l, -1), ++l;
        while(l > L[i]) a->change(l-1, 1), --l;
        while(r < R[i]) a->change(r+1,1), ++r;
        while(r > R[i]) a->change(r,-1), --r;
        (cl, cr)= (L[i],R[i]);
        ++this->cur;
        return IDX[i];
    }
    int next(int & l, int & r, int cl, int & cr, int & t){
        if(this->cur >= this->lmt) return -1;
        int i = this->cur;
        while(t < E[i]) a->modify(t+1,1, l, r), ++t;
        while(t > E[i]) a->modify(t,-1, l, r), --t;
        return next(l,r,cl,cr);
    }
};

{
    
}
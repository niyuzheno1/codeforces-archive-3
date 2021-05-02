//no-unlocked



#define pq_type priority_queue<int>
int n, a[2d5+10], L[], R[];

{
    rd(n, a(n));
    int dis = coordcomp(n, a);
    rep(i, dis) R[i] = -1, L[i] = int_inf;
    rep(i, n){
        L[a[i]] <?= i;
        R[a[i]] >?= i;
    }
    sortA(dis, L, R);
    int inv = 0;
    pq_type  pq;
    rep(i, dis){
        if(pq.empty()){
            ++inv;
            pq.push(R[i]);
            continue;
        }
        auto x = pq.top(); pq.pop();
        if(x < L[i]){
            ++inv;
            while(!pq.empty()) pq.pop();
            pq.push(R[i]);
            continue;
        }
        else{
            pq.push(x);
            pq.push(R[i]);
        }
    }
    mint x; 
    x.setmod(998244353);
    x = 2;
    wt(x.pw(inv-1));
}
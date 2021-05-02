//no-unlocked
int n;
int a[1d3+50];
int cnt[1d3+50];
int ans[5d3+20], asz;
void push(int x){
    ans[asz] = x;
    ++asz;
}
set<int> cnt2[1d3+50];
{
    REP(rd_int()){
        asz = 0;
        rd(n,a(n));
        // TODO : [part one] make sure that the mex of the array with duplicates sorted
        rep(i,n) ++cnt[a[i]];
        int l = 0;
        while(true){
            while(cnt[l]) ++l;
            if(l >= n) break;
            int tmp = a[l];
            --cnt[tmp];
            ++cnt[l];
            a[l] = l;
            push(l);
            if(cnt[tmp] == 0) l <?= tmp;
        }
        // TODO : [part two] make sure that the array with unsorted entries being sorted
        rep(i,n) cnt2[a[i]].insert(i);
        l = 0;
        int r = n;
        while(true){
            while(cnt2[r].size() > 0) ++r;
            while(cnt2[l].find(l) != cnt2[l].end()) ++l;
            if(l >= n) break;
            int t1, t2;
            if(cnt2[l].size() > 0){
                t1 = *cnt2[l].begin(); t2 = a[t1];
                if(t1 != -1){
                    push(t1);
                    a[t1] = r;
                    cnt2[r].insert(t1);
                    cnt2[t2].erase(t1);
                    r <?= t2;
                }
            }
            push(l);
            t2 = a[l];
            cnt2[t2].erase(l);
            a[l] = l;
            cnt2[l].insert(l);
            l <?= t2;
        }
        wt(asz);
        rep(i,asz) ++ans[i];
        wt(ans(asz));
        rep(i,n+30) cnt[i] = 0, cnt2[i].clear();
    }
}
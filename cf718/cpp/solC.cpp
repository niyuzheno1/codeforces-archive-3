#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll & x : a) cin >> x;

    auto slow = [&] (){
        mn ans = 0;
        for(int mask = 0; mask < 1 << n; ++ mask){
            vi  c,p;
            for(int i = 0; i < n; ++i){
                if( (mask >> i) & 1) c.push_back(i);
                else p.push_back(i);
            }
            ll diff = 0;
            for(int i : c) diff -= a[i];
            for(int i : p) diff += a[i];
            bool good = true;
            for(int i = 1; i + 1 < sz(c); ++ i){
                good &= c[i] - c[i-1] <= c[i+1] -c[i];
            }
            for(int i = 1; i + 1 < sz(p); ++i) 
                good &= p[i] - p[i-1] >= p[i+1] - p[i];
            if(diff <= 0) continue;
            if(good) ans += 1;
        }
        return ans;
    };
    
    if(n <= 6){
        ps(slow()); return;
    }

    vll prefix{0};
    partial_sum(all(a), back_in)
    
    mn ans = 0;
    // P ? C * P* C?
    for(int initial_p = 0; initial_p <= 1; initial_p ++){
        for(int ending_c = 0; ending_c <= 1; ++ ending_c){
            int l = initial_p;
            int r = n-ending_c;
            for(count_c = 0; count_c <= r-l; count_c ++){
                int count_p = r-l-count_c;
                if(count_p == 0 && ending_c) continue;
                if(count_c == 0 && initial_p) continue;
                ll diff = initial_p * a.front() - ending_c * a.back();
                diff -= getrange(l +1, l + count_c);
                diff += getrange(l+count_c + 1, r);
                if(diff > 0) ++ans;
            }
        }
    }
    // P{2+} C{2+}
    for(int count_p = 2; count_p <= n; ++count_p){
        int count_c = n - count_p;
        if(count_c < 2) continue;
        ll diff = prefix[count_p];
        diff -= getrange(count_p+1, n);
    }

    vll prefix_pc{0};
    for(int i = 0; i < n; ++i){
        int val = i % 2 == 0 ? a[i] : - a[i];
        prefix_pc.push_back(prefix_pc.back() + val);
    }

    auto sum_pc = [&] (int l, int r) -> ll {
        assert((r-l) % 2 == 0);
        ll sum = getrangepc(l+1,r);
        if(l % 2 != 0) return -sum;
        return sum;
    };

    for(int initial_p = 0; initial_p <= 1; ++ initial_p){
        for(int ending_c = 0; ending_c <= 1; ++ ending_c){
            int l = initial_p;
            int r = n - ending_c;
            
            for(int count_c = 1; count_c <= r-l; ++count_c){
                auto too_big = [&] (int pc){
                    int count_p = r- l - count_c - 2 * pc;
                    if(count_p <= 0) return true;
                    ll diff = initial_p * a.front() - ending_c * a.back();
                    diff -= getrange(l+1, l + count_c);
                    diff += getrange(r-count_p+1, r);
                    diff += sum_pc(1+count_c, r-count_p);
                    return diff <= 0;
                };
                int ways = 0;
                ans += ways;       
            }
        }
    }

    return 0;
}
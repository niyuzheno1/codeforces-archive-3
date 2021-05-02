//no-unlocked
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html

#define Arguments ...Args
#define all_defined_y_combo     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
#define arguments_y_combo     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
#define template_for_y_comb template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    all_defined_y_combo ;
    arguments_y_combo;
};

template_for_y_comb;
// The following template is accredited to Neal Wu.
// I have rewritten it so it fits more for cLay
#define default_empty ={}
#define default_zero =0
#define get_query_value  T query_value(int a, int b){  return values[query_index(a, b)];}
template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
    RMQ(const vector<T> &_values default_empty) {
        if (!_values.empty())
            build(_values);
    }
    RMQ(T * _values default_zero, int sz default_zero){
        vector<T> _v;
        rep(i,sz){
            _v.push_back(_values[i]);
        }
        if(sz > 0)
        {
            build(_v);
        }
    }
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int better_index(int a, int b)  {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
        // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
    get_query_value;

};
const int MN = 3d5+10;
ll n, h[MN], b[MN];

{
    rd(n,h(n),b(n));
    RMQ<ll> rmq(h,n);
    auto tmp = y_combinator(
        [&](auto solve, int l, int r) -> ll {
            
            if(l > r) return 0;
            auto x = rmq.query_index(l,r+1);
            
            auto lx = x-1;
            auto rx = x+1;
            auto leftx = solve(l, lx);
            auto rightx = solve(rx, r);
            auto ans = b[x] + leftx + rightx;
            if(l != 0) ans = max(ans,rightx);
            if(r != n-1) ans = max(ans, leftx);
            return ans;
        }
    );
    wt(tmp(0,n-1));
}
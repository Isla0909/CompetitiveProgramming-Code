#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#include <ctime>
#include <random>
#include <chrono>
#include <functional>
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct PresidentTree
{
    int idx = 0;
    int root[N];

    struct node
    {
        int l, r;
        int cnt;
        i64 sum;
    }tr[4 * N + 17 * N * 2];

    void modify(int &u, int v, int l, int r, int x, int delta, int s)
    {
        u = ++idx;
        tr[u] = tr[v];
        tr[u].cnt += delta;
        tr[u].sum += delta * s;

        if(l == r) return ;

        int mid = l + r >> 1;
        if(x <= mid) modify(tr[u].l, tr[v].l, l, mid, x, delta, s);
        else modify(tr[u].r, tr[v].r, mid + 1, r, x, delta, s);
    }

    i64 query(int u, int l, int r, int k, const vector<int> &w)
    {
        if(k == 0 || tr[u].cnt == 0) return 0;
        if(l == r) return 1LL * k * w[l];

        int mid = l + r >> 1;
        int c = tr[tr[u].l].cnt;
        if(k <= c) return query(tr[u].l, l, mid, k, w);
        return tr[tr[u].l].sum + query(tr[u].r, mid + 1, r, k - c, w); 
    }
};

struct Task
{
    int s, e;
    int p;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin >>m >>n;
    vector<Task> a(m + 1);
    vector<int> b;
    for(int i = 1; i <= m; i ++)
    {
        cin >>a[i].s >>a[i].e >>a[i].p;
        b.push_back(a[i].p);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    auto find = [&](int x) -> int
    {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;  
    };
    int len = b.size();
    vector<int> w(len + 1);
    for(int i = 1; i <= len; i ++)
        w[i] = b[i - 1];
    
    vector<vector<pii>> add(n + 1), del(n + 1);
    for(int i = 1; i <= m; i ++)
    {
        auto [s, e, p] = a[i];
        add[s].emplace_back(p, 1);
        if(e + 1 <= n) del[e + 1].emplace_back(p, -1);
    }

    PresidentTree tree;
    for(int t = 1; t <= n; t ++)
    {
        tree.root[t] = tree.root[t - 1];
        for(auto [p, delta] : add[t])
            tree.modify(tree.root[t], tree.root[t], 1, len, find(p), delta, p);
        for(auto [p, delta] : del[t])
            tree.modify(tree.root[t], tree.root[t], 1, len, find(p), delta, p);
    }

    i64 pre = 1;
    for(int i = 1; i <= n; i ++)
    {
        int x, a, b, c; cin >>x >>a >>b >>c;
        i64 k = 1 + (1LL * a * pre + b) % c;

        int tot = tree.tr[tree.root[x]].cnt;
        if(k > tot) k = tot;
        i64 ans = tree.query(tree.root[x], 1, len, k, w);
        cout <<ans <<endl;
        pre = ans;
    }
    return 0;
}
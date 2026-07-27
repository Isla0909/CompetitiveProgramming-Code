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
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e6 + 1, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct SegmentTree
{
    struct node
    {
        int l, r;
        int val1, val2;//val1, val2分别是区间的最大最小值
    };
    vector<int> w;
    vector<node> tree;

    void pushup(int u)
    {
        auto pushup = [&](node &p, node &l, node &r) -> void
        {
            p.val1 = max(l.val1, r.val1);
            p.val2 = min(l.val2, r.val2);
        };
        pushup(tree[u], tree[u << 1], tree[u << 1 | 1]);
    }

    void initial(int n)
    {
        w.resize(n + 1);
        tree.resize(4 * n + 1);

        auto build = [this](auto &&self, int u, int l, int r) -> void
        {
            if(l == r)
            {
                tree[u] = {l, r, w[l], w[l]};
                return ;
            }
            tree[u] = {l, r, 0, 0};
            int mid = l + r >> 1;
            self(self, u << 1, l, mid), self(self, u << 1 | 1, mid + 1, r);
            pushup(u);
        };
        build(build, 1, 1, n);
    }

    SegmentTree() {}
    SegmentTree(int n)
    {
        initial(n);
    }
    SegmentTree(vector<int> a)
    {
        int n = a.size() - 1;
        w.resize(n + 1);
        for(int i = 1; i <= n; i ++)
            w[i] = a[i];
        initial(n);
    }

    int max_query(int u, int l, int r)
    {
        if(tree[u].l >= l && tree[u].r <= r) return tree[u].val1;

        int mid = tree[u].l + tree[u].r >> 1;

        int res = -INF;
        if(l <= mid) res = max(res, max_query(u << 1, l, r));
        if(r >= mid + 1) res = max(res, max_query(u << 1 | 1, l, r));
        return res;
    }

    int min_query(int u, int l, int r)
    {
        if(tree[u].l >= l && tree[u].r <= r) return tree[u].val2;

        int mid = tree[u].l + tree[u].r >> 1;

        int res = INF;
        if(l <= mid) res = min(res, min_query(u << 1, l, r));
        if(r >= mid + 1) res = min(res, min_query(u << 1 | 1, l, r));
        return res;
    }

    int find_first(int u, int ql, int qr, int x)//查询区间第一个大于x的数的下标
    {
        //无交集返回-1
        if(tree[u].l > qr || tree[u].r < ql) return -1;

        //完美包含但不满足返回-1
        if(tree[u].l >= ql && tree[u].r <= qr && tree[u].val1 <= x) return -1;

        if(tree[u].l == tree[u].r) return tree[u].l;

        int c = find_first(u << 1, ql, qr, x);
        if(c != -1) return c;
        return find_first(u << 1 | 1, ql, qr, x);
    }

};

int maxx[N][21];
int minn[N][21];

inline int read() 
{
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
void wr(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)wr(x/10);
    putchar('0'+x%10);
}

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
    if(a.ff != b.ff) return a.ff < b.ff;
    return a.se < b.se;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = read();
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        a[i] = read();
        maxx[i][0] = a[i];
        minn[i][0] = a[i];
    }

    for(int i = 1 ; i <= 20 ; i ++ ){
        for(int j = 1 ; j + (1 << i) - 1 <= n ; j ++){
            maxx[j][i] = max(maxx[j][i - 1], maxx[j + (1 << i - 1)][i - 1]);
            minn[j][i] = min(minn[j][i - 1], minn[j + (1 << i - 1)][i - 1]);
        }
    }

    auto min_query = [&](int l, int r) -> int
    {
        int k = __lg(r - l + 1);
        return min(minn[l][k], minn[r - (1 << k) + 1][k]);
    };

    auto max_query = [&](int l, int r) -> int
    {
        int k = __lg(r - l + 1);
        return max(maxx[l][k], maxx[r - (1 << k) + 1][k]);
    };

    //SegmentTree seg(a);

    // vector<int> l(n + 1);
    // for(int i = 1; i <= n; i ++)
    // {
    //     int c = seg.find_first(1, 1, i, a[i]);
    //     if(c == -1) l[i] = i;
    //     else l[i] = c;
    // }

    bool f = 1;
    for(int i = 2; i <= n; i ++)
        if(a[i] < a[i - 1])
        {
            f = 0;
            break;
        }
    if(f)
    {
        cout <<n <<endl;
        return 0;
    }


    vector<int> st(n + 1, 0);
    int ans = 0;
    for(int len = 2; len <= n; len ++)
    {
        if(st[len] == 1)
        {
            ans ++;
            continue;
        }

        int pre = -1; bool f = 1;
        for(int i = 1; i <= n; i += len)
        {
            int l = i, r = min(i + len - 1, n);
            int M = max_query(l, r), m = min_query(l, r);

            if(pre == -1) pre = M;
            else if(m < pre)
            {
                f = 0;
                break;
            }
            else pre = M;
        }

        ans += f;
        if(f)
        {
            for(int k = 1; k * len <= n; k ++)
                if(st[k * len] == -1) st[k * len] = 1;
        }
    }    
    wr(ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define int long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct SegmentTree
{
    struct tree
    {
        int l, r, mi, val;
        vector<pair<int, int>> tag;
        bool rst;
    } tr[4 * maxn];
    int a[maxn];
    int n;

#define lc (p << 1)
#define rc (p << 1 | 1)

    void apply1(int p)
    {
        tr[p].tag.clear();
        tr[p].mi = tr[p].val;
        tr[p].rst = 1;
    }
    void apply2(int p, int op, int v)
    {
        if (op == 1) tr[p].mi -= v;
        else tr[p].mi >>= v;

        if (!tr[p].tag.empty() && tr[p].tag.back().first == op)
            tr[p].tag.back().second += v;
        else
            tr[p].tag.push_back({op, v});
    }

    void pushup(int p)
    {
        tr[p].val = min(tr[lc].val, tr[rc].val);
        tr[p].mi = min(tr[lc].mi, tr[rc].mi);
    }

    void pushdown(int p)
    {
        if (tr[p].rst)
        {
            apply1(lc), apply1(rc);
            tr[p].rst = false;
        }
        for (auto [op, v] : tr[p].tag)
            apply2(lc, op, v), apply2(rc, op, v);
        tr[p].tag.clear();
    }

    void build(int p, int l, int r)
    {
        tr[p].l = l, tr[p].r = r;
        tr[p].tag.clear(), tr[p].rst = 0;
        if (l == r)
        {
            tr[p].mi = tr[p].val = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }

    void change1(int p, int x, int y, int k) // del
    {
        if (x <= tr[p].l && y >= tr[p].r)
        {
            apply2(p, 1, k);
            return;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        pushdown(p);
        if (x <= mid)
            change1(lc, x, y, k);
        if (y > mid)
            change1(rc, x, y, k);
        pushup(p);
    }

    void change2(int p, int x, int y)
    {
        if (x <= tr[p].l && y >= tr[p].r)
        {
            apply2(p, 2, 1);
            return;
        }
        int mid = tr[p].l + tr[p].r >> 1;
        pushdown(p);
        if (x <= mid)
            change2(lc, x, y);
        if (y > mid)
            change2(rc, x, y);
        pushup(p);
    }
#undef lc
#undef rc
} t;

void sol()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> t.a[i];
    t.build(1, 1, n);
    while (Q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int x;
            cin >> x;
            t.change1(1, l, r, x);
        }
        else
            t.change2(1, l, r);

        if (t.tr[1].mi <= m)
        {
            cnt++;
            t.apply1(1);
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        sol();
}


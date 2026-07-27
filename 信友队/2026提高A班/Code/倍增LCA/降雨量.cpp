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
#include <array>
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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout << v[i] << " \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}

struct SparseTable
{
    int n, k;
    vector<int> a;
    vector<vector<int>> st;

    SparseTable() {}
    SparseTable(vector<int> &v)
    {
        initial(v);
    }

    void initial(vector<int> &v)
    {
        n = v.size() - 1;
        k = __lg(2 * n - 1) + 1;

        a.resize(n + 1);

        for(int i = 1; i <= n; i ++)
            a[i] = v[i];

        st.assign(n + 1, vector<int>(k));
    }

    void max_work()
    {
        for(int j = 0; j < k; j ++)
        {
            for(int i = 1; i + (1 << j) - 1 <= n; i ++)
            {
                if(j == 0) st[i][j] = a[i];
                else
                    st[i][j] = max(
                        st[i][j - 1],
                        st[i + (1 << (j - 1))][j - 1]
                    );
            }
        }
    }

    int max_query(int l, int r)
    {
        if(l > r) return -INF;
        int k = __lg(r - l + 1);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >>n;

    vector<int> year(n + 1), rain(n + 1);

    for(int i = 1; i <= n; i ++)
        cin >>year[i] >>rain[i];

    SparseTable st(rain);
    st.max_work();

    int q; cin >>q;

    while(q --)
    {
        int y, x; cin >> y >> x;

        int py = lower_bound(year.begin() + 1, year.end(), y) - year.begin();
        int px = lower_bound(year.begin() + 1, year.end(), x) - year.begin();

        bool ey = py <= n && year[py] == y;
        bool ex = px <= n && year[px] == x;

        int l = upper_bound(year.begin() + 1, year.end(), y) - year.begin();
        int r = lower_bound(year.begin() + 1, year.end(), x) - year.begin() - 1;

        int mx = st.max_query(l, r);

        if(ey && ex)
        {
            if(rain[px] > rain[py] || mx >= rain[px])
                cout << "false" << endl;
            else if(px - py == x - y)
                cout << "true" << endl;
            else
                cout << "maybe" << endl;
        }
        else if(ey)
        {
            if(mx >= rain[py])
                cout << "false" << endl;
            else
                cout << "maybe" << endl;
        }
        else if(ex)
        {
            if(mx >= rain[px])
                cout << "false" << endl;
            else
                cout << "maybe" << endl;
        }
        else cout << "maybe" << endl;
    }
    return 0;
}
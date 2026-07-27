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
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; i64 s; cin >>n >>m >>s;
    vector<int> w(n + 1), v(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >>w[i] >>v[i];
    vector<int> l(m + 1), r(m + 1);
    for(int i = 1; i <= m; i ++)
        cin >>l[i] >>r[i];

    auto calc = [&](int x) -> i64
    {
        vector<i64> pre1(n + 1), pre2(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            pre1[i] = pre1[i - 1] + (w[i] >= x);
            pre2[i] = pre2[i - 1] + (w[i] >= x) * v[i];
        }
        i64 y = 0;
        for(int i = 1; i <= m; i ++)
            y += (pre1[r[i]] - pre1[l[i] - 1]) * (pre2[r[i]] - pre2[l[i] - 1]);
        return y;
    };

    auto check = [&](int x) -> bool
    {
        return calc(x) >= s;
    };

    int L = 0, R = 1e6 + 1;
    while(L + 1 != R)
    {
        int mid = L + R >> 1;
        if(check(mid)) L = mid;
        else R = mid;
    }
    cout <<min(abs(calc(L) - s), abs(calc(R) - s)) <<endl;
    return 0;
}

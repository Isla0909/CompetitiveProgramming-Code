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
#define int long long
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

    int n, m; cin >>n >>m;
    vector<int> a(m + 1), pre(n + 1);
    vector<i64> s(m + 1);
    for(int i = 1; i <= m; i ++)
    {
        cin >>a[i];
        s[i] = s[i - 1] + a[i];
        pre[a[i]] = 1;
    }
    for(int i = 1; i <= n; i ++)
        pre[i] += pre[i - 1];

    auto calc = [&](int l, int r) -> __int128
    {
        __int128 c = r - l + 1;
        return c * c * c * c;
    };

    vector<i64> f(m + 1, inf); f[0] = 0;
    auto fun = [&](int l, int r) -> __int128
    {
        return (__int128)f[l] + (__int128)a[r] + calc(l + 1, r);
    };
    for(int i = 1; i <= m; i ++)
    {
        int l = 0, r = i - 1;
        while(r - l > 2)
        {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            if(fun(mid1, i) > fun(mid2, i)) l = mid1;
            else r = mid2;
        }
        
        for(int j = l; j <= r; j ++)
            f[i] = min((__int128)f[i], fun(j, i));
       // cout <<i <<" " <<l <<" " <<r <<" " <<f[i] <<endl;
    }
    cout <<(i64)min((__int128)f[m], fun(0, m)) <<endl;
    return 0;
}
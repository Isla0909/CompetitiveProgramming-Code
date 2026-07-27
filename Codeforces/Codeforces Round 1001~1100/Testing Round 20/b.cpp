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

    int n; cin >>n;
    vector<int> v1, v2;
    for(int i = 0; i < n; i ++)
    {
        int x, y; cin >>x >>y;
        if(y == 1) v1.push_back(x);
        else v2.push_back(x);
    }
    sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());

    int m1 = v1.size(), m2 = v2.size();
    auto calc = [&](pii t) -> i64
    {
        auto [a, b] = t;
        i64 res = 0;
        for(int i = 0; i < a; i ++) res += abs(v1[i] - v1[m1 - 1 - i]);
        for(int i = 0; i < b; i ++) res += abs(v2[i] - v2[m2 - 1 - i]);
        return res;
    };
    int ans = 0;
    for(int i = 0; 2 * i <= m1; i ++)
    {
        int x = m1 - 2 * i, y = (m2 - i) / 2;
        if(m2 - i < 0) continue;
        ans = max(ans, i + min(x, y));
    }
    vector<pii> v;
    for(int i = 0; 2 * i <= m1; i ++)
    {
        int x = m1 - 2 * i, y = (m2 - i) / 2;
        if(m2 - i < 0) continue;
        if(i + min(x, y) == ans) v.emplace_back(i, ans - i);
    }
    int l = 0, r = v.size() - 1;
    while(r - l > 2)
    {
        int midl = l + (r - l) / 3;
        int midr = r - (r - l) / 3;
        if(calc(v[midl]) >= calc(v[midr])) r = midr;
        else l = midl;
    }
    i64 s = 0;
    for(int i = l; i <= r; i ++)
        s = max(s, calc(v[i]));
    cout <<ans <<" " <<s <<endl;    
    return 0;
}

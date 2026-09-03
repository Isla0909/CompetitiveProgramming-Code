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
    vector<int> deg(2 * n + 1), to(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int u = i, v; cin >>v;
        to[u] = v;
        deg[v] ++;
    }

    vector<int> f(2 * n + 1);
    for(int i = 1; i <= n; i ++)
        f[i] = 1;

    queue<int> q;
    for(int i = 1; i <= n; i ++)
        if(!deg[i]) q.emplace(i);

    while(q.size())
    {
        auto u = q.front(); q.pop();

        int v = to[u];
        if(v <= n)
        {
            f[v] = max(f[v], f[u] + 1);
            if(-- deg[v] == 0) q.emplace(v);
        }
        else f[v] = max(f[v], f[u]);
    }

    int ans1 = accumulate(f.begin() + n + 1, f.end(), 0);

    vector<int> st(n + 1); int ans2 = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(!deg[i] || st[i]) continue;

        int len = 0, u = i;
        while(!st[u])
        {
            st[u] = 1;
            len ++;
            u = to[u];
        }
        ans2 += len;
    }
    cout <<ans1 + ans2 <<endl;
    return 0;
}

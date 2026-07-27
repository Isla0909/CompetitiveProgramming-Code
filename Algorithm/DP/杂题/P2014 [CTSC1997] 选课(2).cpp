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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int n, m; cin >>n >>m;
    vector<int> adj[n + 1], w(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int a, b; cin >>a >>b;
        w[i] = b;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    vector f(n + 1, vector<int>(m + 1));
    function <void(int, int, int)> dfs;
    dfs = [&](int u, int fa, int tot) -> void
    {
        if(tot <= 0) return ;
        for(auto v : adj[u])
        {
            if(v == fa) continue;

            for(int k = 0; k < tot; k ++)
                f[v][k] = f[u][k] + w[v];
            dfs(v, u, tot - 1);
            for(int k = 1; k <= tot; k ++)
                f[u][k] = max(f[u][k], f[v][k - 1]);
        }
    };
    dfs(0, -1, m);
    cout <<f[6][0] <<endl;
    return 0;
}
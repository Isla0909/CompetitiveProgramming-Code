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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, int b, int c) 
{
    int res = 1;
    while(b) 
    {
        if(b & 1) res = res * a % c;

        a = a * a % c;
        b >>= 1;
    }
    return res;
}

signed main() 
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >> T;
    while(T --) 
    {
        int n; cin >> n;
        vector<int> adj[n + 1];
        for(int i = 1; i < n; i ++) 
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> d(n + 1, n);
        
        function<void(int, int)> calc;
        calc = [&](int u, int fa) 
        {
            if(adj[u].size() == 1 && u != 1) 
            {
                d[u] = 0;
                return;
            }
            for(auto v : adj[u]) 
            {
                if(v == fa) continue;
                calc(v, u);
                d[u] = min(d[u], d[v] + 1);
            }
        };
        calc(1, -1);

        vector<int> ans(n + 1);
        function<void(int, int)> dfs;
        dfs = [&](int u, int fa) 
        {
            for(auto v : adj[u]) 
            {
                if(v == fa) continue;
                ans[v] = ans[u] * d[v] % mod * quick_pow(d[v] + 1, mod - 2, mod) % mod;
                dfs(v, u);
            }
        };
        ans[1] = 1;
        dfs(1, -1);

        for(int i = 1; i <= n; i ++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
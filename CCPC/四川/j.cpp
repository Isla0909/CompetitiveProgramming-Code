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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n; string s; cin >>n >>s;
        s = ' ' + s;

        vector<int> adj[n + 1];
        for(int i = 1; i < n; i ++)
        {
            int a, b; cin >>a >>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll ans = 0;
        vector f1(6, vector<int>(n + 1)), f2(6, vector<int>(n + 1));
        function <void(int, int)> dfs;
        dfs = [&](int u, int fa) -> void
        {
            //12345
            //SCCPC
            if(s[u] == 'S') f1[1][u] = 1;
            if(s[u] == 'C') f2[1][u] = 1;

            for(auto v : adj[u])
            {
                if(v == fa) continue;

                dfs(v, u);

                for(int i = 1; i <= 4; i ++)
                    ans += 1LL * f1[i][u] * f2[5 - i][v] + 1LL * f2[i][u] * f1[5 - i][v];
                
                if(s[u] == 'S') f2[5][u] += f2[4][v];
                else if(s[u] == 'C')
                {
                    f2[4][u] += f2[3][v];
                    f2[3][u] += f2[2][v];

                    f1[2][u] += f1[1][v];
                    f1[3][u] += f1[2][v];
                    f1[5][u] += f1[4][v];
                }
                else if(s[u] == 'P')
                {
                    f2[2][u] += f2[1][v];
                    f1[4][u] += f1[3][v];
                }
            }
        };
        dfs(1, -1);
        cout <<ans <<endl;
    }
    return 0;
}
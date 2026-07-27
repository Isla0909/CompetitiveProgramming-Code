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
    cin.tie(0) -> sync_with_stdio(false);

    int n, m; cin >>n >>m;
    vector g(n + 1, vector<int>(n + 1, inf));
    vector f(n + 1, vector<vector<int>>(n + 1, vector<int>(2 * n + 1, inf)));
    vector ff(n + 1, vector<vector<int>>(n + 1, vector<int>(2 * n + 1, inf)));
    for(int i = 1; i <= n; i ++) g[i][i] = 0, f[i][i][0] = 0, ff[i][i][0] = 0;

    vector<pii> adj[n + 1];
    vector<int> din(n + 1);
    while(m --)
    {
        int a, b, w; cin >>a >>b >>w;
        adj[a].emplace_back(b, w);
        g[a][b] = min(g[a][b], w);
        f[a][b][1] = min(f[a][b][1], w);
        ff[a][b][1] = min(ff[a][b][1], w * w);
        din[b] ++;
    }

    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    if(g[1][n] == inf)
    {
        cout <<-1 <<endl;
        return 0;
    }

    if(n == 1)
    {
        cout <<0 <<endl;
        return 0;
    }

    queue<int> q; vector<bool> st(n + 1);
    for(int i = 1; i <= n; i ++)
        if(!din[i])
        {
            st[i] = 1;
            q.push(i);
        }
    while(q.size())
    {
        auto t = q.front(); q.pop();
        for(auto [v, w] : adj[t])
        {
            din[v] --;
            if(!din[v])
            {
                st[v] = 1;
                q.push(v);
            }
        }
    }

    bool flag = 0; vector<int> cycle;
    for(int i = 1; i <= n; i ++)
        if(!st[i] && g[1][i] != inf && g[i][n] != inf)
        {
            flag = 1;
            cycle.push_back(i);
        }

    double ans = 1e18;
    if(flag)
    {
        for (int len = 1; len <= 2 * n; ++len) 
            for (int k = 1; k <= n; ++k) 
                for (int i = 1; i <= n; ++i) 
                    for (int j = 1; j <= n; ++j)
                        for (int c1 = 0; c1 <= len; ++c1) 
                        { 
                            int c2 = len - c1; 
                            if (c2 < 0 || c1 > n || c2 > n) continue;
                            if (f[i][k][c1] == inf || f[k][j][c2] == inf) continue;
                            if (f[i][j][len] > f[i][k][c1] + f[k][j][c2]) f[i][j][len] = f[i][k][c1] + f[k][j][c2];
                            if (ff[i][j][len] > ff[i][k][c1] + ff[k][j][c2]) ff[i][j][len] = ff[i][k][c1] + ff[k][j][c2];
                        }
        for(int i = 0; i < cycle.size(); i ++)
        {
            for(int j = 0; j < cycle.size(); j ++)
            {
                //if(i == j) continue;
                int a = cycle[i], b = cycle[j];
                for(int c1 = 0; c1 <= n; c1 ++)
                    for(int c2 = 0; c2 <= n; c2 ++)
                    {
                        // if(f[a][b][c1] != inf && f[b][a][c2] != inf)
                        // {
                        //  cout <<a <<" " <<b <<" " <<f[a][b][c1] <<" " <<f[b][a][c2] <<endl;
                        //  cout <<c1 <<" " <<c2 <<endl;
                        // }
                        if(c1 + c2 < 2) continue;
                        double ss = ff[a][b][c1] + ff[b][a][c2];
                        double s = f[a][b][c1] + f[b][a][c2];
                        if(ss >= inf || s >= inf) continue;
                        ss /= (c1 + c2), s /= (c1 + c2);
                        ans = min(ans, ss - s * s);
                    }
            }
        }
    }
    //cout <<"before " <<ans <<endl;

    struct State 
    {
        int s = inf;
        int ss = inf;
    };
    vector dp(n + 1, vector<State>(n + 1));  // dp[u][len]
    dp[1][0].s = dp[1][0].ss = 0;

    for(int len = 0; len < n; len ++) 
    {
        for(int u = 1; u <= n; u ++) 
        {
            if(dp[u][len].s == inf) continue;
            for(auto [v, w] : adj[u]) 
            {
                int new_len = len + 1;
                if (new_len > n) continue;
                int s = dp[u][len].s + w;
                int ss = dp[u][len].ss +  w * w;
                if(s < dp[v][new_len].s || (s == dp[v][new_len].s && ss < dp[v][new_len].ss))
                {
                    dp[v][new_len].s = s;
                    dp[v][new_len].ss = ss;
                }
            }
        }
    }


    for(int len = 1; len <= n; len ++) 
    {
        if (dp[n][len].s == inf) continue;
        double mean = 1.0 * dp[n][len].s / len;
        double var = 1.0 * dp[n][len].ss / len - mean * mean;
        ans = min(ans, var);
    }

    cout <<fixed <<setprecision(10) <<ans <<endl;
    return 0;
}
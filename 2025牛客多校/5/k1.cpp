#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<cstdlib>
#include<iomanip>
#include<climits>
#include<bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)

constexpr int maxn = 5e6 + 10;
constexpr int N = 21;
constexpr int mod = 998244353;
constexpr ll inf = 1e18;
constexpr ld eps = 1e-8;
constexpr int intinf = 1e9;
constexpr int dx[] = { 1,-1,0,0 };
constexpr int dy[] = { 0,0,1,-1 };

int n, m, k, key[maxn], f[maxn][25], state[maxn][25], dep[maxn];
ll dp[maxn], sum[maxn];
vector<pair<int, int>> edge[maxn];
bool flag[maxn];

void add(int u, int v, int w) {
    edge[u].push_back({ v,w });
}

void dfs(int u, int fa, int num) 
{
    dep[u] = dep[fa] + 1;
    if(num != 0) 
    {
        if (key[num] != 0) 
        {
            state[u][0] = 1 << (key[num] - 1);
        }
    }
    f[u][0] = fa;
    for (auto [v, w] : edge[u]) 
    {
        if (v == fa) continue;
        dfs(v, u, w);
    }
}

void up() 
{
    for (int i = 1; i < N; i++)
        for (int u = 1; u <= n; u++) 
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
            state[u][i] = state[u][i - 1] | state[f[u][i - 1]][i - 1];
        }
}

pair<int, int> get_lca(int u, int v) 
{
    int cur_state = 0;
    if (dep[u] < dep[v]) swap(u, v);

    int k = dep[u] - dep[v];
    for (int i = N - 1; i >= 0; i--)
        if ((k >> i) & 1) 
        {
            cur_state |= state[u][i];
            u = f[u][i];
        }

    if (u == v) return { u, cur_state };

    for (int i = N - 1; i >= 0; i--)
        if (f[u][i] != f[v][i]) 
        {
            cur_state |= state[u][i];
            cur_state |= state[v][i];
            u = f[u][i];
            v = f[v][i];
        }
    return { f[u][0], cur_state | state[u][0] | state[v][0] };
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i < n; i ++) 
    {
        int u, v;
        cin >> u >> v;
        add(u, v, i); add(v, u, i);
    }
    for (int i = 1; i <= m; i++) 
    {
        int x;
        cin >> x;
        key[x] = i;
    }
    dfs(1, 0, 0);
    up();

    for (int i = 0; i < (1 << m); i++) dp[i] = maxn;
    dp[0] = 0; sum[0] = 1;
    unordered_map<int, ll> states;
    int all_state = 0;
    for (int i = 1; i <= k; i++) 
    {
        int u, v;
        cin >> u >> v;
        auto cur = get_lca(u, v);
        states[cur.second]++;
        all_state |= cur.second;
    }

    for (auto [cur_state, num] : states) 
    {
        if (!cur_state) continue;
        for (int j = (1 << m) - 1; j >= 0; j--) 
        {
            if (sum[j] == 0) continue;
            if(dp[j] == maxn) continue;

            if (dp[j | cur_state] > dp[j] + 1) {
                sum[j | cur_state] = 1ll * sum[j] * num % mod;
                dp[j | cur_state] = dp[j] + 1;
            }
            else if (dp[j | cur_state] == dp[j] + 1) {
                sum[j | cur_state] = (sum[j | cur_state] + 1ll * sum[j] * num % mod) % mod;
            }
        }
    }
    if(dp[(1 << m) -1] == maxn) cout <<-1 <<endl;
    else cout << dp[(1 << m) - 1] << " " << sum[(1 << m) - 1] << "\n";
    return 0;
}
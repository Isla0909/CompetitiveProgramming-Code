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
//以1 ~ n每个点作为根, 选k个点, 求k个点的LCA
//一个点怎么样就能变成LCA?
//子树(包含自己)有k个节点?  -> Yes
//问题转化为以一个点为根时其余节点的子树大小  则考虑换根dp
//换根dp, 换根过程中改变了siz大小的其实也就两个点 -> u, v
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<vector<int>> adj(n + 1);
		for(int i = 1; i < n; i ++)
		{
			int u, v;  cin >>u >>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		i64 ans = 0;
		vector<int> siz(n + 1); 
		auto dfs1 = [&](this auto &&self, int u, int fa) -> void
		{
			siz[u] = 1;
			for(auto v : adj[u])
			{
				if(v == fa) continue;

				self(v, u);
				siz[u] += siz[v];
			}
			if(siz[u] >= k) ans += n - siz[u];
			if(n - siz[u] >= k) ans += siz[u];
		};
		ans += n;
		dfs1(1, -1);
		
		cout <<ans <<endl;
	}
	return 0;
}
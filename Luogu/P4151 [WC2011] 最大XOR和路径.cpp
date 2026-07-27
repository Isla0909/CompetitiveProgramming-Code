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

struct LinearBasis
{
	static constexpr int BASE = 63;
	vector<i64> d, p;
	int cnt, flag;
	bool rebuilt;

	LinearBasis()
	{
		d.assign(BASE, 0);   // d[i]:最高位为 i 的基向量
        p.assign(BASE, 0);   // p[i]:rebuild 后的“有序基向量”
		cnt = flag = 0;
		rebuilt = false;
	}

	bool insert(i64 x)
	{
		rebuilt = false;
		for(int i = BASE - 1; i >= 0; i --)
		{
			if(x >> i & 1LL)
			{
				if(!d[i]) 
				{
					d[i] = x;
					return true;
				}
				x ^= d[i];
			}
		}
		flag = 1;//线性相关
		return false;
	}

	bool check(i64 x)
	{
		for(int i = BASE - 1; i >= 0; i --)
		{
			if(x >> i & 1LL)
			{
				if(!d[i]) return false;
				x ^= d[i];
			}
		}
		return true;
	}

	i64 getmax()
	{
		i64 res = 0;
		for(int i = BASE - 1; i >= 0; i --)
			if((res ^ d[i]) > res) res ^= d[i];
		return res;
	}

	i64 query_max(i64 x)
	{
		i64 res = x;
		for(int i = BASE - 1; i >= 0; i --)
			if((res ^ d[i]) > res) res ^= d[i];
		return res;
	}

	i64 getmin()
	{
		if(!rebuilt) rebuild();
        if(flag) return 0;      
        if(cnt == 0) return 0;//不存在,看情况是否需要返回-1
        return p[0];            
	}

	void rebuild()
	{
		for(int i = BASE - 1; i >= 0; i --)
			for(int j = i - 1; j >= 0; j --)
				if(d[i] >> j & 1LL) d[i] ^= d[j];
		cnt = 0;
		for(int i = 0; i < BASE; i ++)
			if(d[i]) p[cnt ++] = d[i];
		rebuilt = true;
	}

	i64 kth_query(i64 k)//查询能被异或得到的第 k 小值, 如不存在则返回 -1
	{
		if(!rebuilt) rebuild();

		if(flag) k --;//!!!!!!!!!注意空集是否属于可达值!
		if(!k) return 0;
		if(k >= (1LL << cnt)) return -1;

		i64 res = 0;
		for(int i = 0; i < cnt; i ++)
			if(k >> i & 1LL) res ^= p[i];
		return res;
	}

	void merge(const LinearBasis &b)
	{
		rebuilt = false;
		for(int i = BASE - 1; i >= 0; i --)
			if(b.d[i]) insert(b.d[i]);
	}
};

LinearBasis merge(const LinearBasis &a, const LinearBasis &b)
{
	LinearBasis c = a;
	for(int i = a.BASE - 1; i >= 0; i --)
		if(b.d[i]) c.insert(b.d[i]);
	return c;
}

//注意:本模板默认“非空子集”可达集合 (空集不算)
//因此0只有在flag==1(存在线性相关,可由非空子集异或出0)时才可达

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<vector<pair<int, i64>>> adj(n + 1);
	for(int i = 0; i < m; i ++)
	{
		int u, v; i64 w; cin >>u >>v >>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	LinearBasis base;
	vector<i64> dis(n + 1);
	vector<int> vis(n + 1);
	auto dfs = [&](this auto &&self, int u, int fa) -> void
	{
		vis[u] = 1;
		for(auto [v, w] : adj[u])
		{
			if(v == fa) continue;

			if(!vis[v])
			{
				dis[v] = dis[u] ^ w;
				self(v, u);
			}
			else base.insert(dis[u] ^ dis[v] ^ w);
		}
	};
	dfs(1, -1);
	cout <<base.query_max(dis[n]) <<endl;
	return 0;
}

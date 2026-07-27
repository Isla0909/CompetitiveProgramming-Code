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

bool cmp(const pair<i64, i64> &a, const pair<i64, i64> &b)
{
	if(a.ff != b.ff) return a.ff < b.ff;
	return a.se > b.se;
}

vector<int> minp, primes;

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
		}
	}
}

vector<pair<i64, i64>> v;

void dfs(int u, int pre, i64 cur, i64 cnt)
{
	if(u == primes.size()) return ;

	v.emplace_back(cur, cnt);

	for(int i = 1; i <= pre; i ++)
	{
		if((i128)cur * primes[u] > inf) break;
		cur *= primes[u];
		dfs(u + 1, i, cur, cnt * (i + 1));
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(70);
	//cout <<primes.size() <<endl;

	dfs(0, 60, 1, 1);

	sort(v.begin(), v.end(), cmp);

	vector<i64> a, c;
	for(int i = 0; i < v.size(); i ++)
	{
		auto [val, cnt] = v[i];
		if(a.size() && val == a.back()) continue;

		a.emplace_back(val);
		if(c.size())
		{
			i64 x = c.back();
			c.emplace_back(max(cnt, x));
		}
		else c.emplace_back(cnt);
	}


	int T; cin >>T;
	while(T --)
	{
		i64 n; cin >>n;

		int idx = upper_bound(a.begin(), a.end(), n) - a.begin();
		if(idx) idx --;
		cout <<c[idx] <<endl;
	}
	return 0;
}


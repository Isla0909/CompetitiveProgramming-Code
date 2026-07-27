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

	int n, m; cin >>n >>m;
	int S = 1 << m, full = S - 1;

	vector<int> state(n + 1), cnt(n + 1);
	vector<int> f(S + 1, -1), g(S + 1, -1);

	auto better = [&](int x, int y) -> bool
	{
		if(x == -1) return false;
		if(y == -1) return true;

		if(cnt[x] != cnt[y]) return cnt[x] > cnt[y];

		return x < y;
	};

	auto add = [&](int x, int id) -> void
	{
		if(id == -1) return ;
		if(f[x] == id || g[x] == id) return ;

		if(better(id, f[x]))
		{
			g[x] = f[x];
			f[x] = id;
		}
		else if(better(id, g[x])) g[x] = id; 
	};

	for(int i = 1; i <= n; i ++)
	{
		string s; cin >>s;
		for(int j = 0; j < m; j ++)
			if(s[j] == 'T') state[i] |= 1 << j;
		cnt[i] = __builtin_popcount(state[i]);
		add(state[i], i);
	}	

	for(int j = 0; j < m; j ++)
	{
		for(int s = 0; s < (1 << m); s ++)
		{
			if(s >> j & 1) continue;

			int ns = s | (1 << j);
			add(s, f[ns]), add(s, g[ns]);
		}
	}
	int ans = -1, l = INF, r = INF;
	for(int i = 1; i <= n; i ++)
	{
		int s = full ^ state[i];
		int pos = f[s];

		if(pos == -1) continue;

		if(pos == i) pos = g[s];
		
		int res = cnt[i] + cnt[pos];
		if(res > ans)
		{
			ans = res;
			l = i, r = pos;
		}
	}
	if(ans == -1) cout <<"No" <<endl;
	else cout <<l <<" " <<r <<endl;
	return 0;
}

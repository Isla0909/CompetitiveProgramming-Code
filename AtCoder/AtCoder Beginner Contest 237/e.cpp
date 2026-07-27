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

constexpr int N = 2e5 + 10, M = 4e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int h[N], val[M], nex[M], w[M]; int idx;

void add(int a, int b, int c)
{
	nex[idx] = h[a], val[idx] = b, w[idx] = c, h[a] = idx ++;
} 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(h, -1, sizeof h);

	int n, m; cin >>n >>m;
	vector<int> H(n + 1);
	for(int i = 1; i <= n; i ++) cin >>H[i];

	auto calc = [&](int a, int b) -> int
	{
		if(H[a] >= H[b]) return H[a] - H[b];
		return 2 * (H[a] - H[b]);
	};

	for(int i = 0; i < m; i ++)
	{
		int a, b; cin >>a >>b;
		add(a, b, calc(a, b));
		add(b, a, calc(b, a));
	}

	vector<i64> dist(n + 1, -inf);
	vector<int> st(n + 1);
	queue<int> q; q.emplace(1);
	dist[1] = 0; st[1] = 1;
	while(q.size())
	{
		auto t = q.front(); q.pop(); st[t] = 0;
		for(int i = h[t]; ~ i; i = nex[i])
		{
			int j = val[i];
			if(dist[j] < dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					q.emplace(j);
					st[j] = 1;
				}
			}
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, dist[i]);
	cout <<ans <<endl;
	return 0;
}

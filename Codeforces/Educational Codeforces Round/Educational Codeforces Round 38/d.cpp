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

constexpr int N = 2e5 + 10, M = 6e5 + 10;

int h[N], val[M], nex[M]; i64 w[M]; int idx;

void add(int a, int b, i64 c)
{
	nex[idx] = h[a], val[idx] = b, w[idx] = c, h[a] = idx ++;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(h, -1, sizeof h);

	int n, m; cin >>n >>m;
	for(int i = 0; i < m; i ++)
	{
		int a, b; i64 c; cin >>a >>b >>c;
		add(a, b, c << 1LL);
		add(b, a, c << 1LL);
	}

	for(int i = 1; i <= n; i ++)
	{
		i64 w; cin >>w;
		add(0, i, w);
	}

	vector<bool> st(n + 1);
	vector<i64> dist(n + 1, inf);
	dist[0] = 0;
	priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
	q.emplace(0, 0);
	while(q.size())
	{
		auto [d, t] = q.top(); q.pop();
		if(st[t]) continue;
		st[t] = 1;

		for(int i = h[t]; ~ i; i = nex[i])
		{
			int j = val[i];
			if(dist[j] > d + w[i])
			{
				dist[j] = d + w[i];
				q.emplace(d + w[i], j);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		cout <<dist[i] <<" \n"[i == n];
	return 0;
}

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

constexpr int N = 2e5 + 10, INF = 1e9, mod = 1e9 + 7;

int query(char c, int k)
{
	cout <<"? " <<c <<" " <<k <<endl;
	int x; cin >>x;
	return x;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> x(n), y(n);
		for(int i = 0; i < n; i ++)
			cin >>x[i] >>y[i];
		vector<int> p(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&](int i, int j)
		{
			int dis1 = 2e9 + x[i] + y[i];
			int dis2 = 2e9 + x[j] + y[j];
			return dis1 < dis2;
		});

		query('L', INF), query('L', INF), query('D', INF);
		int d1 = query('D', INF);

		int id1 = p[0];
		query('R', INF), query('R', INF), query('R', INF);
		int d2 = query('R', INF);

		sort(p.begin(), p.end(), [&](int i, int j)
		{
			int dis1 = 2e9 - x[i] + y[i];
			int dis2 = 2e9 - x[j] + y[j];
			return dis1 < dis2;
		});
		int id2 = p[0];
		int ansx = (x[id1] + y[id1] - d1 + d2 - y[id2] + x[id2]) / 2;
		int ansy = x[id1] + y[id1] - d1 + 4LL * INF - ansx;
		cout <<"! " <<ansx <<" " <<ansy <<endl;
	}
	return 0;
}
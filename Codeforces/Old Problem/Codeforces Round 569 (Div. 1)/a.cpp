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
	vector<array<int, 2>> ans(2 * n + 1);
	deque<int> q;
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		q.emplace_back(x);
	}

	for(int i = 1; i <= n << 1; i ++)
	{
		int a = q.front(); q.pop_front();
		int b = q.front(); q.pop_front();
		ans[i] = {a, b};
		if(a < b) swap(a, b);
		q.emplace_front(a), q.emplace_back(b);
	}

	while(m --)
	{
		i64 x; cin >>x;
		if(x <= n) cout <<ans[x][0] <<" " <<ans[x][1] <<endl;
		else
		{
			x -= n;
			x %= (n - 1);
			if(!x) x = n - 1;
			cout <<ans[n + x][0] <<" " <<ans[n + x][1] <<endl;
		}
	}
	return 0;
}

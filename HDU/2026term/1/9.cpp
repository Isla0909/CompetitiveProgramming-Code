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
constexpr f64 pi = 3.1415926535, eps = 1e-8;

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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<array<int, 2>> a(n);
		for(int i = 0; i < n; i ++) cin >>a[i][0] >>a[i][1];

		vector<f64> v; bool f = 0;
		for(int i = 0; i < n; i ++)
		{
			auto [x, y] = a[i];
			if(!x && !y)
			{
				f = 1;
				break;
			}
			f64 c = atan2l(y, x);
			v.push_back(c);
		}

		sort(v.begin(), v.end());

		if(f)
		{
			cout <<1 <<endl;
			continue;
		}
		if(n == 2)
		{	
			if(fabsl(v[0] + pi - v[1]) < eps)
			{
				int x1 = a[0][0], x2 = a[1][0];
				if(x1 < 0) x1 = -x1;
				if(x2 < 0) x2 = -x2;
				if(x1 < x2) swap(x1, x2);
				cout <<x1 / x2 + 1 <<endl;
			}
			else cout <<-1 <<endl;
			continue;
		}

		if(v.back() < v[0] + pi)
		{
			cout <<-1 <<endl;
			continue;
		}

		unordered_map<i64, int> mp;
		map<pii, bool> st;
		queue<array<int, 3>> q;
		int cnt = 0; int ans = -1;
		q.push({0, 0, 0});
		while(q.size())
		{
			cnt ++;
			auto [d, x, y] = q.front(); q.pop();
			//ans = max(ans, d);
			if(x == 0 && y == 0 && d) 
			{
				ans = d;
				break;
			}
			for(int i = 0; i < n; i ++)
			{
				auto [dx, dy] = a[i];
				int nx = x + dx, ny = y + dy;
				if(abs(nx) > 200 || abs(ny) > 200 || st[{nx, ny}]) continue;

				st[{nx, ny}] = 1;
				q.push({d + 1, nx, ny});
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}

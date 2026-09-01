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

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<pii> pos(n * m);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
			{
				int x; cin >>x;
				pos[x] = {i, j};
			}

		vector<pii> v;
		auto check = [&](int x) -> bool
		{
			v.clear();
			for(int i = 0; i < x; i ++)
				v.emplace_back(pos[i]);
			sort(v.begin(), v.end(), [&](auto &a, auto &b)
			{
				if(a.ff != b.ff) return a.ff < b.ff;
				return a.se < b.se;
			});
			int a = 0, b = 0;
			for(auto [x, y] : v)
			{
				if(x >= a && y >= b) a = x, b = y;
				else return false;
			}
			return true;
		};

		int l = 0, r = n * m + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		cout <<l <<endl;
	}
	return 0;
}

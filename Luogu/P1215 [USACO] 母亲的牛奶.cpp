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

array<int, 3> split(int x)
{
	int a = x / (21 * 21) % 21, b = x / 21 % 21, c = x % 21;
	return {a, b, c};
}

int merge(int a, int b, int c)
{
	return 21 * 21 * a + 21 * b + c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c; cin >>a >>b >>c;
	vector<int> st(10000), ans;
	queue<int> q;
	q.emplace(merge(0, 0, c));

	auto change = [&](int &x, int &y, int lim) -> void
	{
		if(!x || y == lim) return ;

		if(y + x <= lim)
		{
			y += x;
			x = 0;
		}
		else
		{
			int c = lim - y;
			x -= c, y = lim;
		}
 	};

 	vector<int> lim{a, b, c};
	while(q.size())
	{
		auto t = q.front(); q.pop();
		if(st[t]) continue;

		st[t] = 1;

		auto v = split(t);
		auto [x, y, z] = v;
		if(!x) ans.push_back(z);

		// cout <<x <<" " <<y <<" " <<z <<endl;

		for(int i = 0; i < 3; i ++)
			for(int j = 0; j < 3; j ++)
			{
				if(i == j) continue;
				change(v[i], v[j], lim[j]);
				q.emplace(merge(v[0], v[1], v[2]));
				v[0] = x, v[1] = y, v[2] = z;
			}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	tell(0, ans);
	return 0;
}

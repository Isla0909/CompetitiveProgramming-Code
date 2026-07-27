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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7, P = 13331;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<u64> p(1e5 + 1); p[0] = 1;
	for(int i = 1; i <= 100000; i ++)
		p[i] = p[i - 1] * P;

	auto hash = [&](string s)
	{
		int len = s.size();
		s = ' ' + s;

		vector<u64> h(len + 1);
		for(int i = 1; i <= len; i ++)
		{
			int c = s[i] - 'a' + 1;
			h[i] = h[i - 1] * P + c;
		}
		return h;
	};

	int n; cin >>n;
	unordered_map<u64, bool> mp;

	vector<vector<string>> v(100001);
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		int len = s.size();
		v[len].push_back(s);
		mp[hash(s).back()] = 1;
		//cout <<hash(s).back() <<endl;
	}

	auto query = [&](vector<u64> h, int l, int r) -> u64
	{
		return h[r] - h[l - 1] * p[r - l + 1];
	};

	vector<int> pre(100001);
	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + v[i].size();

	int l = 0, r = 401;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		// if(pre[mid] < (1 + mid) * mid / 2)
		// {
		// 	r = mid;
		// 	continue;
		// }

		bool ok = 0;
		for(auto s : v[mid])
		{
			auto h = hash(s);
			int len = s.size(); bool f = 1;
			for(int i = len - 1; i >= 1; i --)
			{
				for(int ql = 0; ql + i - 1 < len; ql ++)
					if(!mp.count(query(h, ql + 1, ql + i - 1 + 1)))
					{
						f = 0;
						// if(mid == 2)
						// {
						// 	cout <<ql <<" " <<i <<endl;
						// 	cout <<query(h, ql + 1, ql + i - 1 + 1) <<endl;
						// }
						break;
					}
				if(!f) break;
 			}
			if(f)
			{
				ok = 1;
				break;
			}
		}

		if(ok) l = mid;
		else r = mid;
	}
	cout <<l <<endl;
	return 0;
}
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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	vector<pii> p(n);
	for(int i = 0; i < n; i ++)
		cin >>p[i].ff >>p[i].se;

	for(int i = 1; i < n; i ++)
	{
		map<int, vector<int>> mp;

		int dx = p[i].ff - p[0].ff;
		int dy = p[i].se - p[0].se;

		for(int j = 0; j < n; j ++)
		{
			int x = p[j].ff, y = p[j].se;

			int b = y * dx - dy * x;
			mp[b].push_back(j);

			if(mp.size() > k) break;
		}

		if(mp.size() == k)
		{
			bool f = 1;
			for(auto value : mp)
			{
				if(value.se.size() < 2)
				{
					f = 0;
					break;
				}
			}
			if(f)
			{
				for(auto value : mp)
				{
					cout <<value.se.size() <<" ";
					for(auto points : value.se)
						cout <<points + 1 <<" ";
					cout <<endl;
				}
				break;
			}
		}
	}
	return 0;
}
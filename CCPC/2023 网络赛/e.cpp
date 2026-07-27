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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	if(a.ff != b.ff) return a.ff < b.ff;
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	string s; cin >>s;


	auto get = [](int x, int y) -> i32
	{
		return x * 100 + y;
	};

	vector<pii> ans;
	for(int i = 0; i < (1 << n); i ++)
	{
		int x = 20, y = 20; bool f = 1;
		unordered_map<int, bool> mp;
		mp[get(x, y)] = 1;
		for(int j = 0; j < n; j ++)
		{
			auto c = s[j];
			if(c == 'L') x --;
			else if(c == 'R') x ++;
			else if(c == 'D') y --;
			else y ++;

			int s = get(x, y);
			if(mp.count(s))
			{
				if(mp[s] && (i >> j & 1)) continue;
				else if(!mp[s] && !(i >> j & 1))
				{
					if(c == 'L') x ++;
					else if(c == 'R') x --;
					else if(c == 'D') y ++;
					else y --;
				}
				else
				{
					f = 0;
					break;
				}
			}
			else
			{
				if(i >> j & 1) mp[s] = 1;
				else
				{
					mp[s] = 0;
					if(c == 'L') x ++;
					else if(c == 'R') x --;
					else if(c == 'D') y ++;
					else y --;
				}
			}
		}
		if(!f) continue;
		ans.emplace_back(x - 20, y - 20);
	}
	sort(ans.begin(), ans.end(), cmp);
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout <<ans.size() <<endl;
	for(auto [x, y] : ans)
		cout <<x <<" " <<y <<endl;
	return 0;
}
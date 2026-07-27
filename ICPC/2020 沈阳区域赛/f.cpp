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

	int n; cin >>n;
	vector<int> a(n);
	for(auto &x : a) cin >>x;

	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	auto find = [&](int x) -> i32
	{
		return lower_bound(b.begin(), b.end(), x) - b.begin();
	};

	vector<vector<int>> pos(n);
	for(int i = 0; i < n; i ++)
	{
		int x = find(a[i]);
		pos[x].push_back(i);
	}
	int ans = 0;
	int i = 0, j = -1, s = -1;
	while(i < b.size())
	{
		reverse(pos[i].begin(), pos[i].end());
		while(pos[i].size())
		{
			auto c = pos[i].back(); pos[i].pop_back();
			if(c > j)
			{
				if(a[c] >= s) ans ++;
				while(j < c)
				{
					j ++;
					s = max(s, a[j]);
				}
			}
		}
		i ++;
	}
	cout <<ans <<endl;
	return 0;
}

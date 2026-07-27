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
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k, w; cin >>n >>m >>k >>w;
		vector<pii> a(n + m + 2);
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			a[i] = {x, 1};
		}
		for(int i = 0; i < m; i ++)
		{
			int x; cin >>x;
			a[i + n] = {x, 0};
		}
		a[n + m] = {w + 1, 0};
		sort(a.begin(), a.end());

		vector<int> ans; bool f = 1;
		int l = 0, r = 0;
		for(int i = 0; i < a.size(); i ++)
		{
			if(a[i].se) continue;
			l = r, r = i;//黑点的两端
			vector<int> v;
			for(int j = l + 1; j < r; j ++)//遍历中间的红点
			{
				int pos = a[j].ff;
				v.push_back(pos);
				while(j + 1 < r && a[j + 1].ff < pos + k) j ++;
			}
			if(v.empty()) continue;
			v.push_back(a[r].ff);;
			for(int j = v.size() - 1; j >= 1; j --)
			{
				if(v[j - 1] + k - 1 >= v[j])
				{
					v[j - 1] = v[j] - k;
				}
			}
			if(v[0] <= a[l].ff)
			{
				f = 0;
				break;
			}
			v.pop_back();
			for(auto x : v)
				ans.push_back(x);
		}

		if(!f) cout <<-1 <<endl;
		else
		{
			cout <<ans.size() <<endl;
			tell(0, ans);
		}
	}
	return 0;
}
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
		int n; cin >>n;
		vector<i64> a(n + 1), pre(n + 1), abspre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
			abspre[i] = abspre[i - 1] + abs(a[i]);
		}
		vector<i64> suf(n + 2);
		for(int i = n; i >= 1; i --)
			suf[i] = suf[i + 1] + a[i];

		i64 s = pre[n];
		int pos = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] > 0)
			{
				i64 c = abspre[i - 1] - a[i] + suf[i + 1];
				if(c > s)
				{
					s = c;
					pos = i;
				}
			}
		}

		vector<int> ans;
		if(pos)
		{
			int p = 0;
			for(int i = pos - 1; i >= 1; i --)
			{
				i64 c = p ? -a[i] : a[i];

				if(c > 0)
				{
					ans.push_back(i);
					p ^= 1;
				}
			}
			ans.push_back(pos);
		}

		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
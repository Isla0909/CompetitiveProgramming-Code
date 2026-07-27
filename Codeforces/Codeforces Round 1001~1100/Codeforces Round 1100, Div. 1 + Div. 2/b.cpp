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
	if(a.ff != b.ff) return a.ff < b.ff;
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
		vector<int> a(n + 1), b(n + 1);
		vector<pii> v;
		i64 s1 = 0, s2 = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			s1 += a[i];
			v.emplace_back(a[i], 1 * (n + 1) + i);
		}
		for(int i = 1; i <= n; i ++)
		{
			cin >>b[i];
			s2 += b[i];
			v.emplace_back(b[i], 2 * (n + 1) + i);
		}
		sort(v.begin(), v.end(), cmp);

		vector<int> st(n + 1);
		i64 ans = s1 + s2;
		// cout <<ans <<endl;
		int cnt = 0;
		for(int i = 0; i < 2 * n && cnt != n - 1; i ++)
		{
			auto [x, k] = v[i];
			int id = k / (n + 1), pos = k % (n + 1);
			if(!st[pos])
			{
				st[pos] = 1;
				ans -= x;
				cnt ++;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}

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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, x; cin >>n >>x;

		vector<int> d;
		for(int i = 1; i * i <= x; i ++)
			if(x % i == 0)
			{
				d.push_back(i);
				if(i * i != x) d.push_back(x / i);
			}
		sort(d.begin(), d.end()); int m = d.size();

		vector<int> a(n);
		for(auto &c : a) cin >>c;

		vector<bool> f(m); f[0] = 1;//d[0] = 1;
		int ans = 1;
		for(int i = 0; i < n; i ++)
		{
			bool ok = 1;
			for(int j = 0; j < m; j ++)
			{
				if(f[j] && 1LL * a[i] * d[j] == x)
				{
					ok = 0;
					break;
				}
			}
			if(!ok)
			{
				ans ++;
				fill(f.begin(), f.end(), 0);
				f[0] = 1;
			}
			int idx = m - 1;
			for(int j = m - 1; j >= 0; j --)
			{
				while(idx >= 0 && d[idx] > 1LL * d[j] * a[i]) idx --;

				if(f[j] && d[idx] == 1LL * d[j] * a[i]) f[idx] = 1;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
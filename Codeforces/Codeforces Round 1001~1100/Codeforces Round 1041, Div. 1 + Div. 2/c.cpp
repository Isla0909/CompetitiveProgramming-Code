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
#define int long long
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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n), b(n);
		for(auto &x : a) cin >>x;
		for(auto &x : b) cin >>x;

		bool f = 0;
		vector<pii> v;
		for(int i = 0; i < n; i ++)
		{
			if(a[i] > b[i]) swap(a[i], b[i]);
			v.emplace_back(a[i], b[i]);
		}
		sort(v.begin(), v.end());
		int l = v[0].ff, r = v[0].se;
		for(int i = 1; i < n; i ++)
		{
			if(v[i].ff <= r)
			{
				f = 1;
				break;
			}
			else l = v[i].ff, r = v[i].se;
		}
		if(f)
		{
			i64 sum = 0;
			for(int i = 0; i < n; i ++)
				sum += abs(a[i] - b[i]);
			cout <<sum <<endl;
			continue;
		}
		else
		{
			int delta = inf;
			for(int i = 1; i < n; i ++)
			{
				delta = min(delta, 2 * (v[i].ff - v[i - 1].se));
			}
			i64 sum = 0;
			for(int i = 0; i < n; i ++)
				sum += abs(a[i] - b[i]);
			cout <<sum + delta <<endl;
		} 	
	}
	return 0;
}
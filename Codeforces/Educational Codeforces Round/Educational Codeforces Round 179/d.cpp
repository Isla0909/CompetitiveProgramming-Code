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
	return a.ff < b.ff;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<pii> v;
		for(int i = 0; i < m; i ++)
		{
			int x; cin >>x;
			int c = x / 100;
			v.emplace_back(c, x);
		}
		// for(auto x : v)
		// 	cout <<x.se <<" ";
		// cout <<endl;
		sort(v.begin(), v.end(), cmp);
		int l = 0, r = m - 1;
		for(int i = 1; i <= n / 2; i ++)
		{
			for(int j = 0; j < 3; j ++)
				cout <<v[l].se <<" " <<v[r].se <<" ";
			cout <<endl;
			for(int j = 0; j < 3; j ++)
				cout <<v[r].se <<" " <<v[l].se <<" ";
			cout <<endl;
			l ++, r --;
		}
		if(n & 1)
		{
			for(int j = 0; j < 3; j ++)
				cout <<v[l].se <<" " <<v[r].se <<" ";
			cout <<endl;
		}
	}
	return 0;
}
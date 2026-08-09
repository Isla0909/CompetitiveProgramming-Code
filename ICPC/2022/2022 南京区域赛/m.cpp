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

pii operator-(pii a, pii b)
{
	return {b.ff - a.ff, b.se - a.se};
}

int corss(pii a, pii b)
{
	return a.ff * b.se - a.se * b.ff;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<pii> v(n);
	for(int i = 0; i < n; i ++)
		cin >>v[i].ff >>v[i].se;

	auto nex = [&](int x) -> i32
	{
		return (x + 1) % n;
	};

	auto pre = [&](int x) -> i32
	{
		return (x - 1 + n) % n;
	};

	int ans = 0;
	for(int i = 0; i < n; i ++)
	{
		pii a = v[pre(i)] - v[i];
		//cout <<"a " <<a.ff <<" " <<a.se <<endl;
		int j = nex(i);
		if(v[i].se != v[j].se)
		{
			pii b = v[i] - v[j];
			//cout <<"b " <<b.ff <<" " <<b.se <<endl;
			if(a.se < 0 && b.se > 0 && corss(a, b) > 0) ans ++;

			//cout <<i <<" " <<j <<" " <<ans <<endl;
		}
		else
		{
			while(v[j].se == v[i].se) j = nex(j);

			pii b = v[pre(j)] - v[j];
			//cout <<"b " <<b.ff <<" " <<b.se <<endl;
			if(a.se < 0 && b.se > 0 && v[i].ff < v[nex(i)].ff) ans ++;
			//cout <<i <<" " <<j <<" " <<ans <<endl;
			if(pre(pre(j)) > i) 
			i = pre(pre(j));
		}

	}
	cout <<ans <<endl;
	return 0;
}
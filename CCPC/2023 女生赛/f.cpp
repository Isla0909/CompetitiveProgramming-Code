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

	int n; cin >>n; int s = 1; bool f = 1;
	vector<vector<int>> v(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		v[x].push_back(i);
		if(x > s)
		{
			if(x != s + 1) f = 0;
			else s = x;
		}
	}

	if(!f)
	{
		cout <<-1 <<endl;
		return 0;
	}

	vector<int> l(n + 1), r(n + 1);
	for(int i = 1; i <= s; i ++)
		l[i] = i - 1, r[i] = i + 1;
	l[1] = s, r[s] = 1;

	int cnt = 0, j = 1, idx = 1;
	vector<int> p(n + 1); 
	while(cnt != n)
	{
		auto x = v[j].back(); v[j].pop_back();
		p[x] = idx ++; cnt ++;

		if(!v[j].size())
		{
			r[l[j]] = r[j];
			l[r[j]] = l[j];
			if(j == s) s = l[j];
		}
		if(r[j] > j && v[r[j]].back() > x) j = r[j];
		else j = r[s];
	}
	tell(1, p);
	return 0;
}
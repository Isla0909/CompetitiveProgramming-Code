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

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<int> r(n + 1);
	iota(r.begin(), r.end(), 0);

	vector<int> lst(n + 2, 0), nex(n + 1, n + 1);
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] == 0) lst[i + 1] = i;
		else lst[i + 1] = lst[i];
	}
	for(int i = n; i >= 1; i --)
	{
		if(a[i] == 0) nex[i - 1] = i;
		else nex[i - 1] = nex[i];
	}

	for(int i = 1; i <= n; i ++)
	{
		if(a[i] == 1)
		{
			r[lst[i]] = max(r[lst[i]], i);
			r[i] = max(r[i], nex[i]);
		}
		else if(a[i] == 2) r[lst[i]] = max(r[lst[i]], nex[i]);
	}

	for(int i = 1; i <= n; i ++)
		r[i] = max(r[i], r[i - 1]);
	int ans = 0;
	for(int i = 1; i <= n; i = r[i] + 1)
		ans ++;
	cout <<ans <<endl;
	return 0;
}
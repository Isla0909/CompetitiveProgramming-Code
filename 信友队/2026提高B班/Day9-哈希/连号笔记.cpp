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

	int n; cin >>n;
	vector<int> f(n + 1), pre(n + 1, -1);
	unordered_map<int, int> mp;
	int ans = 0, last = n;
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		if(!mp.count(x - 1)) f[i] = 1;
		else f[i] = f[mp[x - 1]] + 1, pre[i] = mp[x - 1];

		mp[x] = i;

		if(f[i] > ans)
		{
			ans = f[i];
			last = i;
		}
	}

	vector<int> v;
	while(last != -1)
	{
		v.push_back(last);
		last = pre[last];
	}
	reverse(v.begin(), v.end());
	cout <<v.size() <<endl;
	tell(0, v);
	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	while(m --)
	{
		int x; cin >>x;
		vector<int> b(x + 1);
		unordered_map<int, int> mp;
		i64 ans = 0;
		for(int i = 1, j = x; i <= x; i ++, j --)
		{
			int c = a[i];
			b[j] = c;
			ans += mp[c];
			mp[c] ++;
		}
		cout <<ans <<endl;
		for(int i = 1; i <= x; i ++)
			a[i] = b[i];
	}
	return 0;
}
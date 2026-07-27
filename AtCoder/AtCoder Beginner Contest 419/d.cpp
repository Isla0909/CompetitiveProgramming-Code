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
	cin.tie(0) -> sync_with_stdio(false);

	 // freopen("in.txt", "r", stdin);
	 // freopen("WA.txt", "w", stdout);

	int n, m; cin >>n >>m;
	string s, t; cin >>s >>t;

	s = ' ' + s, t = ' ' + t;

	vector<int> nex(2 * n + 2);
	for(int i = 0; i < n; i ++)
		nex[i] = i + 1;
	for(int i = n + 1; i <= 2 * n; i ++)
		nex[i] = i + 1;

	while(m --)
	{
		int l, r; cin >>l >>r;
		swap(nex[l - 1], nex[l + n + 1 - 1]);
		swap(nex[r], nex[r + n + 1]);

		//tell(0, nex);

		// int cnt = 0; int idx = 0;
		// //cout <<nex[8] <<endl;
		// while(cnt != n)
		// {
		// 	idx = nex[idx];
		// 	//cout <<idx <<" ";
		// 	if(idx <= n) cout <<s[idx];
		// 	else cout <<t[idx - n - 1];
		// 	cnt ++;
		// 	//cout <<endl;
		// }
		// cout <<" ";
		// cnt = 0, idx = n;
		// while(cnt != n)
		// {
		// 	idx = nex[idx];
		// 	if(idx <= n) cout <<s[idx];
		// 	else cout <<t[idx - n];
		// 	cnt ++;
		// }
		// cout <<endl;
	}

	int cnt = 0; int idx = 0;
	while(cnt != n)
	{
		idx = nex[idx];
		if(idx <= n) cout <<s[idx];
		else cout <<t[idx - n - 1];
		cnt ++;
	}
	cout <<endl;
	// cnt = 0, idx = n;
	// while(cnt != n)
	// {
	// 	idx = nex[idx];
	// 	if(idx <= n) cout <<s[idx];
	// 	else cout <<t[idx - n];
	// 	cnt ++;
	// }
	return 0;
}
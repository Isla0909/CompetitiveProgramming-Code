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

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector<bool> st(k + 1);
		vector<int> deg(k + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			st[x] = 1;
		}

		map<pii, int> mp; int ans = 0;
		while(m --)
		{
			int a, b; cin >>a >>b;
			if(a > b) swap(a, b);

			if(st[a] && st[b]) ans ++;
			else if(a == b) deg[a] ++;
			else if(st[a]) deg[b] ++;
			else if(st[b]) deg[a] ++;
			else mp[{a, b}] ++; 
		}

		int s = 0;
		for(auto [e, c] : mp)
		{
			auto [u, v] = e;
			s = max(s, deg[u] + deg[v] + c);
			//cout <<u <<" " <<v <<" " <<s <<endl;
		}

		sort(deg.begin() + 1, deg.end(), greater<int>());
		s = max(s, k == 1 ? deg[1] : deg[1] + deg[2]);
		cout <<ans + s <<endl;
	}
	return 0;
}
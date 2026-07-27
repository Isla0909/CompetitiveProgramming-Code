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
		int n, k; cin >>n >>k;
		string s; cin >>s; s = ' ' + s;
		vector<int> l(k + 1), r(k + 1);
		for(int i = 1; i <= k; i ++) cin >>l[i];
		for(int i = 1; i <= k; i ++) cin >>r[i];

		int q; cin >>q;
		vector<int> diff(n + 1);
		while(q --)
		{
			int x; cin >>x;
			int i = upper_bound(l.begin() + 1, l.end(), x) - (l.begin() + 1);
			int ll = min(x, l[i] + r[i] - x), rr = max(x, l[i] + r[i] - x);

			diff[ll] ++;
			if(rr + 1 <= n) diff[rr + 1] --;
		}
		for(int i = 1; i <= n; i ++)
		{
			diff[i] += diff[i - 1];
			diff[i] %= 2;
		}

		for(int i = 1; i <= k; i ++)
		{
			for(int j = l[i], c = 1; c <= (r[i] - l[i] + 1) / 2; j ++, c ++)
				if(diff[j] & 1) swap(s[j], s[r[i] + 1 - c]);
		}
		for(int i = 1; i <= n; i ++)
			cout <<s[i];
		cout <<endl;
	}
	return 0;
}
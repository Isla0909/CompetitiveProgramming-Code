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
	vector<int> h(n);

	int mx = 0; i64 sum = 0;
	for(auto &x : h)
	{
		cin >>x;
		mx = max(mx, x);
		sum += x;
	}

	vector<int> cnt(mx + 2), suf(mx + 3);
	for(auto x : h)
		cnt[x] ++;

	for(int i = mx; i >= 1; i --)
		suf[i] = suf[i + 1] + cnt[i];

	vector<int> stk, w;
	for(int i = 1; i <= mx; i ++)
	{
		if(!cnt[i]) stk.push_back(i);
		else
		{
			int more = cnt[i] - 1;
			while(more && stk.size())
			{
				w.push_back(i - stk.back());
				stk.pop_back();
				more --;
			}
		}
	}

	for(auto x : stk)
		w.push_back(suf[x + 1]);
	sort(w.begin(), w.end(), greater<int>());

	int m = w.size();
	vector<i64> pre(m + 1);
	for(int i = 1; i <= m; i ++)
		pre[i] = pre[i - 1] + w[i - 1];

	int q; cin >>q;
	while(q --)
	{
		int k; cin >>k;
		if(!k) cout <<sum <<endl;
		else
		{
			int c = min(k - 1, m);
			cout <<pre[m] - pre[c] <<endl;
		}
	}
	return 0;
}

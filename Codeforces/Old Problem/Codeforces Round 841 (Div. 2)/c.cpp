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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] ^ a[i];
		}

		vector<int> suf(n + 2), cnt(2 * n + 1);
		cnt[0] = 1;
		for(int i = n; i >= 1; i --)
		{
			suf[i] = suf[i + 1] ^ a[i];
			cnt[suf[i]] ++;
		}

		i64 sum = n + 1LL * n * (n - 1) / 2;
		vector<int> v;
		for(int i = 0; i * i <= 2 * n; i ++)
			v.push_back(i * i);

		i64 bad = 0;
		for(int l = 1; l <= n; l ++)
		{
			cnt[suf[l]] --;
			for(auto y : v)
			{
				int x = pre[l - 1], z = pre[n] ^ x ^ y;
				if(z <= 2 * n) bad += cnt[z];
			}
		}
		cout <<sum - bad <<endl;
	}
	return 0;
}

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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n), b(n);

		map<int, int> cnt1, cnt2;
		for(auto &x : a)
		{
			cin >>x;
			x %= k;
			cnt1[x] ++;
		}
		for(auto &x : b)
		{
			cin >>x;
			x %= k;
			cnt2[x] ++;
		}

		bool f = 1; int ok = 0;
		for(auto [x, c] : cnt1)
		{
			if(cnt2[x] >= c)
			{
				cnt2[x] -= c;
				ok += c;
				cnt1[x] = 0;
			}
			else
			{
				ok += cnt2[x];
				cnt1[x] -= cnt2[x];
				cnt2[x] = 0;
			}

			if(!cnt1[x]) continue;
			int y = k - x;
			if(cnt2[y] >= cnt1[x])
			{
				cnt2[y] -= cnt1[x];
				ok += cnt1[x];
				cnt1[x] = 0;
			}
			else
			{
				ok += cnt2[y];
				cnt1[x] -= cnt2[y];
				cnt2[y] = 0;
				f = 0;
			}
		}
		if(!f || ok != n) cout <<"NO" <<endl;
		else cout <<"YES" <<endl;
	}
	return 0;
}
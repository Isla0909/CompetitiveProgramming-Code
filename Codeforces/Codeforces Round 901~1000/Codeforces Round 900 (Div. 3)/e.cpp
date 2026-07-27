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
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		int len = __lg(2 * n - 1) + 1;
		vector st(n + 1, vector<int>(len));
		for(int j = 0; j < len; j ++)
			for(int i = 1; i + (1 << j) - 1 <= n; i ++)
			{
				if(j == 0) st[i][j] = a[i];
				else st[i][j] = st[i][j - 1] & st[i + (1 << j - 1)][j - 1];
			}

		auto query = [&](int l, int r)
		{
			if(l > r) swap(l, r);
			int k = __lg(r - l + 1);
			return st[l][k] & st[r - (1 << k) + 1][k];
		};

		int q; cin >>q;
		while(q --)
		{
			int ll, k; cin >>ll >>k;

			int l = ll - 1, r = n + 1;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(query(ll, mid) >= k) l = mid;
				else r = mid;
			}
			if(l >= ll) cout <<l <<" ";
			else cout <<-1 <<" ";
		}
		cout <<endl;
	}
	return 0;
}
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
		string s; cin >>s;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >>a[i];

		bool h = 1;
		vector<int> cnt(26);
		for(auto c : s)
			cnt[c - 'a'] ++;

		for(int i = 0; i < 26; i ++)
			if(cnt[i] & 1)
			{
				h = 0;
				break;
			}

		if(n & 1 || !h)
		{
			cout <<-1 <<endl;
			continue;
		}

		vector f(n, vector<i64>(n, inf));
		for(int len = 2; len <= n; len += 2)
		{
			for(int i = 0; i + len - 1 < n; i ++)
			{
				int l = i, r = i + len - 1;

				i64 M = inf;
				for(int k = l + 1; k <= r; k += 2)
				{
					if(s[l] != s[k]) continue;

                    i64 left = (k == l + 1) ? 0 : f[l + 1][k - 1];
                    i64 right = (k == r) ? 0 : f[k + 1][r];
                    if(left == inf || right == inf) continue;

                    i64 c = left + right + 1LL * a[l] * a[k];
                    if(c < M) M = c;
				}
				f[l][r] = M;
			}
		}
		cout <<(f[0][n - 1] == inf ? -1 : f[0][n - 1]) <<endl;
	}
	return 0;
}

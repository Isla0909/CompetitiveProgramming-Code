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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		int p = n / m, q = n % m;
		int c = p + (q >= k);

		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >>a[i];

		vector<int> vis(n);
		i64 ans = -inf;
		for(int i = 0; i < n; i ++)
		{
			if(vis[i]) continue;

			vector<int> b;
			int x = i;
			while(!vis[x])
			{
				vis[x] = 1;
				b.push_back(a[x]);
				x = (x + m) % n;
			}

			int len = b.size();

			vector<i64> s(2 * len + 1);
			for(int j = 0; j < 2 * len; j ++)
				s[j + 1] = s[j] + b[j % len];

			for(int j = 0; j < len; j ++)
				ans = max(ans, s[j + c] - s[j]);
		}
		cout <<ans <<endl;
	}
	return 0;
}
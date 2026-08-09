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

constexpr int N = 1e7, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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
		vector<int> a(n + 1), ans(n + 1);
		int s = 1e9; f64 l = 0, r = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(a[i])
			{
				ans[i] = (a[i] - 0.5) * N;
				s -= ans[i];
				l += a[i] - 0.5, r += a[i] + 0.5;
			}
			else r += 0.5;
		}
		if(l > 100 || r <= 100)
		{
			cout <<"No" <<endl;
			continue;
		}
		cout <<"Yes" <<endl;
		for(int i = 1; i <= n; i ++)
		{
			int c = N - 1;
			if(!a[i]) c >>= 1;

			if(s >= c)
			{
				ans[i] += c;
				s -= c;
			}
			else
			{
				ans[i] += s;
				break;
			}
		}
		tell(1, ans);
	}
	return 0;
}

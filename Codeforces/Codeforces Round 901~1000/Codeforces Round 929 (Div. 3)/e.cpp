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
#define int long long
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
		vector<int> a(n + 1), pre(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pre[i] = pre[i - 1] + a[i];
		}

		auto fun = [&](int x, int l, int u) -> i64
		{
			i64 sum = 1LL * (pre[x] - pre[l - 1]) * u;
			int c = pre[x] - pre[l - 1] - 1;
			sum -= 1LL * c * (c + 1) / 2;
			return sum;
		};

		int m; cin >>m;
		while(m --)
		{
			int l, u; cin >>l >>u;

			int ll = l, rr = n;
			while(rr - ll > 2)
			{
				int mid1 = ll + (rr - ll) / 3;
				int mid2 = rr - (rr - ll) / 3;

				if(fun(mid1, l, u) >= fun(mid2, l, u)) rr = mid2;
				else ll = mid1;
			}

			//cout <<ll <<" " <<rr <<endl;
			if(ll == rr) cout <<ll <<" ";
			else if(fun(ll + 1, l, u) >= max(fun(ll, l, u), fun(rr, l, u)))
			{
				if(fun(ll + 1, l, u) == fun(ll, l, u)) cout <<ll <<" ";
				else cout <<ll + 1 <<" ";
			}
			else if(fun(ll, l, u) >= fun(rr, l, u)) cout <<ll <<" ";
			else cout <<rr <<" ";
		}
		cout <<endl;
	}
	return 0;
}
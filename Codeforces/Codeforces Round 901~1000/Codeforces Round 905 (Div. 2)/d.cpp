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
		int n, m; cin >>n >>m;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 2; i <= n; i ++)
			cin >>a[i];
		for(int i = 1; i <= n; i ++)
			cin >>b[i];
		auto calc = [&](int x) -> i32
		{
			auto aa = a, bb = b;
			aa[1] = x;
			sort(aa.begin() + 1, aa.end()), sort(bb.begin() + 1, bb.end());

			auto check = [&](int k) -> bool
			{
				for(int i = 1, j = k + 1; j <= n; i ++, j ++)
					if(aa[i] >= bb[j]) return false;
				return true;
			};

			int l = -1, r = n + 1;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(check(mid)) r = mid;
				else l = mid;
			}
			return r;
		};

		int l = 0, r = m + 1, x = -1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(calc(mid) == calc(1)) l = mid;
			else r = mid;
		}
		cout <<1LL * l * calc(l) + 1LL * (m - l) * calc(l + 1) <<endl;
	}
	return 0;
}
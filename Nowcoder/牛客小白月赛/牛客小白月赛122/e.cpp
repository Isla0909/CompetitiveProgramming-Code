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

	int n; cin >>n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	auto check = [&](int l, int r) -> bool
	{
		vector<int> b, c;
		for(int i = 1; i <= n; i ++)
		{
			if(i >= l && i <= r) b.push_back(a[i]);
			else c.push_back(a[i]);
		}
		int j = c.size() - 1;
		while(b.size())
		{
			auto t = b.back();
			while(j >= 0 && c[j] != t) j --;
			if(j == -1) return false;

			b.pop_back(); j --;
		}
		return true;
	};

	int ans = 0;
	for(int i = 2; i <= n - 1; i ++)
	{
		int l = i - 1, r = n;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(i, mid)) l = mid;
			else r = mid;
		}
		ans += l - i + 1;
	}
	cout <<ans <<endl;
	return 0;
}

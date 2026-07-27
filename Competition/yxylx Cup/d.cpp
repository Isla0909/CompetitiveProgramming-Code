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

	int n, q; cin >>n >>q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<array<int, 3>> v(q + 1);
	for(int i = 1; i <= q; i ++)
		cin >>v[i][0] >>v[i][1] >>v[i][2];

	auto check = [&](int x) -> bool
	{
		vector<int> diff(n + 1);
		for(int i = 1; i <= x; i ++)
		{
			auto [l, r, x] = v[i];
			diff[l] += x;
			if(r + 1 <= n) diff[r + 1] -= x;
		}
		for(int i = 1; i <= n; i ++)
		{
			diff[i] += diff[i - 1];
			if(diff[i] < a[i]) return false;
		}
		return true;
	};

	if(!check(q)) cout <<-1 <<endl;
	else
	{
		int l = -1, r = q + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid;
		}
		cout <<r <<endl;
	}
	return 0;
}

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

array<int, 3> get(const vector<int> &a, int k)
{
	const int n = a.size() - 1;
	vector<int> pre(n + 1);
	int l = 0, r = n + 1;
	int ansl = 1, ansr = n;
	while(l + 1 != r)
	{
		int x = l + r >> 1;
		for(int i = 1; i <= n; i ++)
			pre[i] = pre[i - 1] + (a[i] >= x ? 1 : -1);

		int min = 0; bool f = 0;
		int L = 1, R = n;
		for(int i = k; i <= n; i ++)
		{
			if(pre[i - k] < min)
			{
				min = pre[i - k];
				L = i - k + 1;
			}
			if(pre[i] >= min)
			{
				f = 1;
				R = i;
				break;
			}
		}
		if(f) l = x, ansl = L, ansr = R;
		else r = x;
	}
	return {l, ansl, ansr};
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >> a[i];

		auto [max, l, r] = get(a, k);
		cout <<max <<" " <<l <<" " <<r <<endl;
	}

	return 0;
}
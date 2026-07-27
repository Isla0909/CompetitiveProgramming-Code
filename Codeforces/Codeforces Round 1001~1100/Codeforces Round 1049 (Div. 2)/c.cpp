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
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		i64 sum = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(i & 1) sum += a[i];
			else sum -= a[i];
		}

		if(n == 1)
		{
			cout <<a[1] <<endl;
			continue;
		}

		int oddlen, evenlen;
		if(n & 1) oddlen = n - 1, evenlen = n - 1 - 2;
		else evenlen = n - 2, oddlen = n - 1 - 1;

		vector<int> odd, even, b(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			b[i] = 2 * a[i] - i;
			if(i & 1) odd.push_back(b[i]);
			else even.push_back(b[i]);
		}

		sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
		i64 res1 = sum + even.back() - odd[0];

		odd.clear(), even.clear();
		for(int i = 1; i <= n; i ++)
		{
			b[i] = 2 * a[i] + i;
			if(i & 1) odd.push_back(b[i]);
			else even.push_back(b[i]);
		}
		sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
		i64 res2 = sum + even.back() - odd[0];

		cout <<max(sum + max(oddlen, evenlen), max(res1, res2)) <<endl;	
	}
	return 0;
}
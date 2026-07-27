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

	int n; cin >>n;
	vector<int> a(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];
	for(int i = 1; i <= n; i ++) cin >>c[i];

	auto check = [&](int x) -> bool
	{
		multiset<int> s1, s0;
		for(int i = 1; i <= n; i ++)
		{
			if(c[i] == 1)
			{
				if(s0.size())
				{
					auto it = s0.lower_bound(x - a[i]);
					if(it == s0.end()) return false;
					s0.erase(it);
				}
				else s1.insert(a[i]);
			}
			else
			{
				if(s1.size())
				{
					auto it = s1.lower_bound(x - a[i]);
					if(it == s1.end()) return false;
					s1.erase(it);
				}
				else s0.insert(a[i]);
			}
		}
		return true;
	};
	int l = 1, r = 2e8 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout <<l <<endl;
	return 0;
}
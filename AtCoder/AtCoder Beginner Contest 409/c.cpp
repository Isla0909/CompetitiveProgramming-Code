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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, l; cin >>n >>l;
	vector<int> a(n), cnt(l, 0); 
	a[0] = 0, cnt[0] = 1;
	for(int i = 1; i < n; i ++)
	{
		int x; cin >>x;
		a[i] = (a[i - 1] + x) % l;
		cnt[a[i]] ++;
	}
	if(l % 3) cout <<0 <<endl;
	else
	{
		int x = l / 3; ll ans = 0;
		for(int i = 0; i < l; i ++)
		{
			if(!cnt[i]) continue;
			if(cnt[(i + x) % l] and cnt[(i + 2 * x) % l])
			{
				ans += 1LL * cnt[i] * cnt[(i + x) % l] * cnt[(i + 2 * x) % l];
				cnt[i] = cnt[(i + x) % l] = cnt[(i + 2 * x) % l] = 0;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
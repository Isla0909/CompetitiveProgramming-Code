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
		int n, k; cin >>n >>k;
		vector<int> a(n + 1), cnt(n + 1);
		int c = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(!cnt[a[i]]) c ++;

			cnt[a[i]] ++;
		}
		vector<int> st(n + 1, -1);
		sort(cnt.begin() + 1, cnt.end(), greater<int>());
		vector<int> v;
		for(int i = 1; i <= n; i ++)
			if(cnt[i]) v.push_back(cnt[i]);
		sort(v.begin(), v.end());
		//tell(0, v);
		int ans = 0, sum = n;
		for(int i = 0; i < v.size(); )
		{
			int h = v[i];

			int less = sum - (h - 1) * c;

			if(k >= less && (k - less) % c == 0) ans ++;

			while(i < v.size() && v[i] == h)
			{
				sum -= v[i];
				c --;
				i ++;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}

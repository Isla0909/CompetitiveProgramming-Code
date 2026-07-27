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

	int T; cin >>T;
	while(T --)
	{
		int n, l, r; cin >>n >>l >>r;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> v;
		for(int i = l + 1; i <= r; i ++)
			v.push_back(a[i]);
		int m = *min_element(v.begin(), v.end());
		int len = v.size();
		for(int i = 0; i + 1 < len; i ++)
			v.push_back(v[i]);
		int idx = -1;
		for(int i = 0; i < len; i ++)
			if(v[i] == m)
			{
				idx = i;
				break;
			}
		vector<int> stk;
		for(int i = n; i >= 1; i --)
		{
			if(i <= l || i > r) stk.push_back(a[i]);
		}
		while(stk.size() && stk.back() < m)
		{
			cout <<stk.back() <<" ";
			stk.pop_back();
		}
		for(int i = 0; i < r - l; i ++)
			cout <<v[idx + i] <<" ";
		while(stk.size())
		{
			cout <<stk.back() <<" ";
			stk.pop_back();
		}
		cout <<endl;
	}
	return 0;
}

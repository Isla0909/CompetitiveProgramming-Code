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
constexpr long double PI = 3.14159265358979, eps = 1e-10;

void tell(int l, vector<f64> &v)
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
		vector<f64> v;
		for(int i = 1; i <= n; i ++)
		{
			int x, y; cin >>x >>y;
			if(x == 0)
			{
				if(y > 0) v.push_back(PI / 2);
				else v.push_back(-PI / 2);
			}
			else v.push_back(atan2(y, x));
		}
		if(n == 1)
		{
			cout <<fixed <<setprecision(10) <<2 * PI <<endl;
			continue;
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i ++)
			v.push_back(v[i] + 2 * PI);
		f64 ans = 0;
		for(int i = 0; i + k < v.size(); i ++)
			ans = max(ans, v[i + k] - v[i]);
		cout <<fixed <<setprecision(10) <<ans <<endl;
	}
	return 0;
}
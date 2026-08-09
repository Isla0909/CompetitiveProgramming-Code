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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		double r0, c0, p, L, R; cin >>r0 >>c0 >>p >>L >>R;
		
		vector<double> c(n + 1); c[0] = c0;
		vector<double> r(n + 1, L); r[0] = r0;
		for(int i = 0; i < k; i ++)
		{
			int x; double get; cin >>x >>get;
			r[x] = get;
		}

		double eat = 0, out = 0;
		for(int i = 1; i <= n; i ++)
		{
			c[i] = 1.0 * p * c[i - 1] + 1.0 * (1 - p) * r[i - 1];
			out += c[i];
		}
		for(int i = 1; i <= n; i ++)
			eat += r[i];
		cout <<fixed <<setprecision(8) <<out - eat <<endl;
	}
	return 0;
}
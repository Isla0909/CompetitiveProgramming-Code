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
	vector<int> x(n + 1), y(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>x[i] >>y[i];

	int a = 1, b = 1, s = -INF;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
		{
			int dx = x[i] - x[j], dy = y[i] - y[j];
			if(dx * dx + dy * dy > s)
			{
				s = dx * dx + dy * dy;
				a = i, b = j;
			}
		}
	cout <<x[a] <<" " <<y[a] <<" " <<x[b] <<" " <<y[b] <<endl;
	return 0;
}

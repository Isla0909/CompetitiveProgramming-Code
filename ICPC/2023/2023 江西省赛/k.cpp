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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<int> a(n + 1), v;
	for(int i = 1; i <= n; i ++) cin >>a[i];

	for(int i = 1; i + 1 <= n; i ++)
	{
		int x = a[i] - a[i + 1];
		v.push_back(x);
	}

	int s = a[1] - a[n];

	sort(v.begin(), v.end(), greater<>());
	vector<i64> pre(n);
	pre[0] = 0;
	for(int i = 0; i < v.size(); i ++)
		pre[i + 1] = pre[i] + v[i];

	int q; cin >>q;
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int k; cin >>k;
			k --;
			cout <<s - pre[k] <<endl;
		}
		else
		{
			int x; cin >>x;
		}
	}

	return 0;
}

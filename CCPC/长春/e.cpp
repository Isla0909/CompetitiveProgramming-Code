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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i ++)
	{
		cin >>a[i] >>b[i];
		a[i] -= i, b[i] = i - b[i];
		c[i] = i;
	}

	auto cmp = [&](int i, int j) -> bool
	{
		if(a[i] != a[j])  return a[i] < a[j];
		return b[i] < b[j];
	};

	sort(c.begin(), c.end(), cmp);

	int stk[n + 1], top = 0, cur = c[0];//cur 表示当前考虑的王国编号
	for(int i = 1; i < n; i ++)
	{
		if(b[c[i]] >= b[cur])
			while(top > 0 && b[stk[top]] <= b[c[i]]) top --;
		else
		{
			if(a[cur] != a[c[i]]) stk[++ top] = cur;
			cur = c[i];
		}
	}
	stk[++ top] = cur;
	cout <<top <<endl;
	return 0;
}
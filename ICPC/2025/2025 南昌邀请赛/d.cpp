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
int ans = 0;
int n, x, y, z; 

struct point
{
	int a1, b1, c1;
	int a2, b2, c2;
}p[N];

void init(vector<int> &v)
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

void calc(vector<int> &a)
{
	vector<int> b = a;
	init(b);

	auto find = [&](int x) -> int
	{
		return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
	};

	vector<int> d(2 * n + 1), s(2 * n + 1);
	for(int i = 0; i < a.size(); i += 2)
	{
		int l = find(a[i]), r = find(a[i + 1]);
		if(l > r) swap(l, r);
		//cout <<l <<" " <<r <<endl;
		d[l] += 1, d[r + 1] -= 1;
	}
	//cout <<d[0] <<" " <<d[1] <<endl;
	//s[0] = d[0];
	for(int i = 1; i <= 2 * n; i ++)
	{
		s[i] = s[i - 1] + d[i];
		//cout <<s[i] <<" ";
		ans = max(ans, s[i]);
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	cin >>n >>x >>y >>z;
	vector<int> a, b, c;
	for(int i = 1; i <= n; i ++)
	{
		cin >>p[i].a1 >>p[i].b1 >>p[i].c1 >>p[i].a2 >>p[i].b2 >>p[i].c2;
		a.push_back(p[i].a1), a.push_back(p[i].a2);
		b.push_back(p[i].b1), b.push_back(p[i].b2);
		c.push_back(p[i].c1), c.push_back(p[i].c2);
	}
	calc(a), calc(b), calc(c);
	cout <<ans <<endl;
	return 0;
}
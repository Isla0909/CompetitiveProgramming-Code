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
#define ff first
#define se second
#define endl '\n'
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	int x, y;
	int l;
};

bool cmp(const cxy &a, const cxy &b)
{
	if(a.l != b.l)
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	vector <cxy> v;
	for(int i = 1; i <= 250; i ++)
		for(int j = 1; j <= 250; j ++)
		{
			int a = (i - 1) * 3 + 1, b = (j - 1) * 3 + 1;
			v.push_back({a, b, a + b});
			v.push_back({a + 1, b, a + b + 1});
			v.push_back({a, b + 1, a + b + 1});
			v.push_back({a + 1, b + 1, a + b + 2});
		}

	sort(v.begin(), v.end(), cmp);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;	
	}
	return 0;
}
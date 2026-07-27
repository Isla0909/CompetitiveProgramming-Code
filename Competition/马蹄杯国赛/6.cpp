#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d; cin >>n >>d;

	vector<int> p(n); int k = n - d + 1;
	for(int i = 0; i < n; i ++)
	{
		if(i < k) p[i] = 0;
		else p[i] = i - k + 1;
	}

	auto print = [&](int x) -> void
	{
		for(int i = 0; i < n; i ++)
		{
			cout <<p[x] <<" ";
			x = (x + 1) % n;
		}
		cout <<endl;
	};

	for(int i = 0; i < n; i ++)
		print(i);
	return 0;
}
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
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		for(int i = 1; i <= n; i ++) cin >>b[i];

		vector<pii> v;
		for(int i = 1; i <= n; i ++)
			v.emplace_back(a[i] + b[i], i);

		sort(v.begin(), v.end(), greater<>());

		i64 s1 = 0, s2 = 0; int idx = 0;
		for(int i = 1; i <= n; i ++)
		{
			auto [x, id] = v[idx];
			if(i & 1) s1 += a[id] - 1;
			else s2 += b[id] - 1;
			idx ++;
		}
		cout <<s1 - s2 <<endl;	
	}
	return 0;
}
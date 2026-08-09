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
#include <array>
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

	int n = 1e6;
	vector<int> cnt(n + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j += i)
			cnt[j] ++;

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> v;
		for(int i = 1; i * i <= k; i ++)
		{
			if(k % i) continue;
			v.push_back(i);
			if(i * i != k) v.push_back(k / i);
		}

		i64 sum = 0;
		for(auto p : v)
			sum += cnt[p];

		cout <<(sum & 1 ? "YES" : "NO") <<endl;
	}
	return 0;
}

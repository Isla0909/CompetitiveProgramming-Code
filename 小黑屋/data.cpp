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

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

double random(double l, double r)
{
	return 1.0 * rng() / rng.max() * (r - l) + l;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	freopen("in.txt", "w", stdout);

	int T = rng() % 100 + 100;
	cout <<T <<endl;
	while(T --)
	{
		int n = rng() % 100 + 100;
		cout <<n <<endl;

		vector<int> a(n);
		iota(a.begin(), a.end(), 1);
		shuffle(a.begin(), a.end(), rng);

		for(int i = 0; i < n; i ++)
			cout <<a[i] <<" \n"[i == n - 1];
	}
	return 0;
}
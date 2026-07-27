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

struct cxy
{
	int w;
	int a, b;
	int id;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<cxy> v(n);
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			int a = x / k, b = x % k;
			if(!b) b = k;
			int id = i + 1;
			v[i] = {x, a, b, id};
		}
		sort(v.begin(), v.end(), [&](auto a, auto b)
		{
			if(a.b != b.b) return a.b > b.b;
			return a.id < b.id;
		});
		for(int i = 0; i < n; i ++)
			cout <<v[i].id <<" \n"[i == n - 1];
	}
	return 0;
}
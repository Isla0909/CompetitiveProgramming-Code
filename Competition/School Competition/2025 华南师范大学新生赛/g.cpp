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

	vector<int> f(1000000 + 1, -1);
	auto dfs = [&](this auto &&self, int x, int u)
	{
		if(f[x] != -1) return f[x];
		if(x == 1 || x == 3 || x == 4) return f[x] = u;

		//cout <<x <<" " <<u <<endl;
		bool c = 0;
		if(x > 1) c |= self(x - 1, u ^ 1) ^ 1;
		if(x > 2) c |= self(x - 3, u ^ 1) ^ 1;
		if(x > 4) c |= self(x - 4, u ^ 1) ^ 1;
		return f[x] = c;
	};

	for(int i = 1; i <= 1000000; i ++)
	{
		if(f[i] == -1) dfs(i, 1);
		//cout <<i <<" " <<f[i] <<endl;
	}

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		if(!n) cout <<"ice" <<endl;
		else if(n < 1000000) cout <<(f[n] ? "Orange" : "ice") <<endl;
		else cout <<(n % 7 == 0 || n % 7 == 2 ? "ice" : "Orange") <<endl;
	}
	return 0;
}

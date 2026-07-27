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
	cin.tie(0) -> sync_with_stdio(false);

	string s = "";
	int n; cin >>n;
	vector<pair<char, ll>> v(n);
	ll sum = 0; bool f = 1;
	for(int i = 0; i < n; i ++)
	{
		cin >>v[i].ff >>v[i].se;
		if(f) sum += v[i].se;

		if(sum > 100) f = 0;
	}
	if(f)
	{
		for(int i = 0; i < n; i ++)
		{
			int x = v[i].se;
			while(x --) cout <<v[i].ff;
		}
		cout <<endl;
	}
	else cout <<"Too Long" <<endl;
	return 0;
}
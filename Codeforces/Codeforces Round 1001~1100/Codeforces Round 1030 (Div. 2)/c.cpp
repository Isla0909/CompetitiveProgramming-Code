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
#define int long long
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

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int count(int x)
{
	int res = 0;
	for(int i = 30; i >= 0; i --)
		if(x >> i & 1) res ++;
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		int ans = 0;
		vector<int> a(n); priority_queue<int, vector<int>, greater<int>> q;
		for(auto &x : a)
		{
			cin >>x;
			ans += __builtin_popcount(x);
			for(int i = 0; i <= 60; i ++)
				if(~ x >> i & 1)
					q.push(1LL << i);
		}
		while(q.size())
		{
			auto t = q.top(); q.pop();
			if(k - t >= 0) ans ++, k -= t;
			else break;
		}
		cout <<ans <<endl;
	}
	return 0;
}
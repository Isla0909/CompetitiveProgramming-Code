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

	deque<pii> q;
	int m; cin >>m;
	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int c, x; cin >>c >>x;
			q.push_back({c, x});
		}
		else
		{
			int k; cin >>k;
			ll sum = 0;
			while(k)
			{
				auto t = q.front(); q.pop_front();
				if(k - t.ff >= 0) k -= t.ff, sum += 1LL * t.ff * t.se;
				else
				{
					int less = t.ff - k;
					sum += 1LL * k * t.se, k = 0; 
					q.push_front({less, t.se});
				}
			}
			cout <<sum <<endl;
		}
	}

	return 0;
}
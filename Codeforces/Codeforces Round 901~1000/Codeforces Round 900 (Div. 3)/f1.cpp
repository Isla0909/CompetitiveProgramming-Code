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

constexpr int N = 1e6 + 1, INF = 0x3f3f3f3f, mod = 1e9 + 7;

vector<int> minp, primes;
int cnt[N];

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			primes.push_back(i);
			minp[i] = i;
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(1e6);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;

		int d = 1;
		auto add = [&](int x) -> void
		{
			while(x > 1)
			{
				int p = minp[x];
				x /= p;
				d /= cnt[p] + 1;
				cnt[p] += 1;
				d *= cnt[p] + 1;
			}
		};

		vector<int> s;
		s.push_back(n); add(n);

		while(q --)
		{
			int op; cin >>op;
			if(op & 1)
			{
				int x; cin >>x;
				s.push_back(x);
				add(x);

				int v = 1;
				for(auto x : s)
					v = 1LL * v * x % d;
				cout <<(v ? "NO" : "YES") <<endl;
			}
			else
			{
				fill(cnt, cnt + N, 0);
				d = 1;
				s.clear();
				s.push_back(n); add(n);
			}
		}
		fill(cnt, cnt + N, 0);
		cout <<endl;
	}
	return 0;
}
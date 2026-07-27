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

vector<int> minp, primes;
vector<ll> pre;
int cnt;

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear(); cnt = 0;

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
		}
	}
	
	cnt = primes.size();
	pre.assign(cnt + 1, 0);
	for(int i = 1; i <= cnt; i ++)
	    pre[i] = pre[i - 1] + primes[i - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(1e6);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		sort(s.begin(), s.end());
		bool f = 0;
		do
		{
			if(s[0] == '0') continue;
			int x = stoi(s);
			if(minp[x] != x)
			{
				cout <<x <<endl;
				f = 1;
				break;
			}
		}while(next_permutation(s.begin(), s.end()));
		if(!f) cout <<-1 <<endl;
	}
	return 0;
}
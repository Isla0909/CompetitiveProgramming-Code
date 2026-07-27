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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), b(n + 1); 
		for(int i = 1; i <= n; i ++) cin >>a[i]; 
		for(int i = 1; i <= n; i ++) cin >>b[i];

		vector<int> d(30); int rank = 0;
		vector<int> path(30), who(30);
		auto insert = [&](int x, int idx)
		{
			int mask = 0;
			for(int i = 29; i >= 0; i --)
			{
				if(!(x >> i & 1)) continue;

				if(!d[i])
				{
					int id = rank ++;
					who[id] = idx;
					d[i] = x;
					path[i] = mask ^ (1 << id);
					return ;
				}
				x ^= d[i];
				mask ^= path[i];
			}
		};

		auto check = [&](int x, int &mask) -> bool
		{
			mask = 0;
			for(int i = 29; i >= 0; i --)
			{
				if(!(x >> i & 1)) continue;
				if(!d[i]) return false;

				x ^= d[i];
				mask ^= path[i];
			}
			return true;
		};

		int s = 0;
		for(int i = 1; i <= n; i ++)
		{
			insert(a[i] ^ b[i], i);
			s ^= a[i];
		}

		int mask = 0;
		if(!check(s, mask)) cout <<-1 <<endl;
		else
		{
			vector<int> st(n + 1);
			for(int i = 0; i < rank; i ++)
			{
				if(mask >> i & 1)
				{
					st[ who[i] ] ^= 1;
				}
			}
			for(int i = 1; i <= n; i ++)
				cout <<(st[i] ? b[i] : a[i]) <<" \n"[i == n];
		}
	}
	return 0;
}

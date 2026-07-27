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
		int a, b, l; cin >>a >>b >>l;
		unordered_map<int, int> mp;
		for(int k = 1; k * k <= l; k ++)
		{
			if(l % k) continue;

			int c = l / k, d = k;
			int lhs = 1;
			for(int x = 0; x <= 20; x ++)
			{
				if(lhs > c) break;
				int rhs = 1;
				for(int y = 0; y <= 20; y ++)
				{
					if(rhs > c) break;
					if(1LL * lhs * rhs == c) mp[k] ++;

					rhs *= b;
				}
				lhs *= a;
			}

			lhs = 1;
			for(int x = 0; x <= 20; x ++)
			{
				if(lhs > d) break;
				int rhs = 1;
				for(int y = 0; y <= 20; y ++)
				{
					if(rhs > d) break;
					if(1LL * lhs * rhs == d) mp[c] ++;

					rhs *= b;
				}
				lhs *= a;
			}

		}
		cout <<mp.size() <<endl;
	}
	return 0;
}
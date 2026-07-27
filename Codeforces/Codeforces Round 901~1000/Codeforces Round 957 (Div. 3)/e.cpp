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

int calc(int x)
{
	int res = 0;
	while(x)
	{
		res ++;
		x /= 10;
	}
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n; vector<pii> v;
		for(int a = 1; a <= 10000; a ++)
		{
			int k = calc(n);

			for(int b = max(1, k * a - 7); b <= min(10000, k * a - 1); b ++)
			{
				int ans = n * a - b;
				int len = calc(ans);

				if(k * a - b != len) continue;

				//if(a == 1262) cout <<a <<" " <<b <<" " <<ans <<endl;

				string s = to_string(ans), t = to_string(n);
				int idx = 0; bool f = 1;
				for(int i = 0; s[i]; i ++)
				{
					if(s[i] != t[idx])
					{
						f = 0;
						break;
					}
					idx ++;
					if(idx == k) idx = 0;
				}
				if(f) v.emplace_back(a, b);
			}
		}
		cout <<v.size() <<endl;
		for(auto x : v)
			cout <<x.ff <<" " <<x.se <<endl;
	}
	return 0;
}
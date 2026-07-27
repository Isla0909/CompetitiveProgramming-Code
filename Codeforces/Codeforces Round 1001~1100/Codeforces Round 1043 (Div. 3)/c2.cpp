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
		int n, k; cin >>n >>k;
		int cnt = 0;
		map<int, int, greater<int>> mp;
		while(n)
		{
			for(int i = 0; ; i ++)
			{
				if(n < (i64)pow(3, i + 1))
				{
					n -= pow(3, i);
					mp[i] += 1;
					cnt ++;
					break;
				}
			}
		}
		if(k < cnt)
		{
			cout <<-1 <<endl;
			continue;
		}

		int delta = k - cnt;

		for(auto &[x, c] : mp)
		{

			// cout <<x <<" " <<c <<endl;
			// cout <<mp[0] <<endl;
			// cout <<delta <<endl;

			if(delta < 2) break;
			if(x == 0) break;

			int cnt = delta / 2;
			if(c <= cnt)
			{
				delta -= c * 2;
				mp[x - 1] += c * 3;
				c = 0;
			}
			else
			{
				c -= cnt;
				mp[x - 1] += cnt * 3;
				break;
			}
		}

		i64 ans = 0;
		for(auto [x, c] : mp)
			ans += 1LL * c * (pow(3, x + 1) + 1LL * x * (i64)pow(3, x - 1));
		cout <<ans <<endl;
	}
	return 0;
}
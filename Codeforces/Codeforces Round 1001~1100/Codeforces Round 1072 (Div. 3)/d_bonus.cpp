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

constexpr int N = 30, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int f[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0][0] = 1;
    for(int i = 1; i < N; i ++)
        for(int j = 0; j <= i; j ++)
        {
            if(j == 0) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;

		if(k >= 60)
		{
			cout <<0 <<endl;
			continue;
		}

		k --;
		int ans = 0, h = __lg(n);
		for(int i = 0; i < h; i ++)
		{
			int c = k - i;//最多容忍多少1
			if(c < 0) ans += (1 << i);
			else
			{
				c = min(c, i);
				ans += (1 << i);
				for(int j = 0; j <= c; j ++)
					ans -= f[i][j];
			}
		}
		
		int c = k - h, len = n - (1 << h) + 1;
		if(c < 0) ans += len;
		else if(c >= h);
		else
		{
			int win = 0, use = 0;
			for(int i = h - 1; i >= 0; i --)
			{
				if(n >> i & 1)
				{
					int lim = c - use;
					if(lim >= 0)
					{
						int up = min(lim, i);
						for(int j = 0; j <= up; j ++)
							win += f[i][j];
					}
					use ++;
					if(use > c) break;
				}
			}
			if(use <= c) win ++;
			ans += len - win;
		}
		cout <<ans <<endl;
	}
	return 0;
}

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
//1 2 2 3 3 3 3
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<array<int, 3>> v(n + 1, {-1, 0, n});
		int j = 0;
		for(int i = 1; i <= n; i ++)
		{
			while(j + 1 <= n && a[j + 1] == a[i]) j ++;
			int len = j - i + 1;
			if(len < a[i])
			{
				i = j;
				continue;
			}
			while(i <= j)
			{
				auto &[f, l, r] = v[i];
				int len = j - i + 1;
				if(len >= a[i])
				{
					f = 1;
					r = i + a[i] - 1;
				}
				i ++;
			}
			i = j;
		}

		i64 ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			auto [f, l, r] = v[i];
			//cout <<i <<" " <<l <<" " <<r <<endl;
			if(f != -1) ans ++;
		}
		//cout <<"ans " <<ans <<endl;
		for(int i = 1; i <= n; i ++)
		{
			auto [f, l, r] = v[i];
			if(f == -1) continue;

			int j = i, c = 0;
			
			while(j <= n)
			{
				int nex = v[j][2] + 1;
				if(nex <= n && v[nex][0] == 1)
				{
					c ++;
					j = nex;
				}
				else break;
			}
			
			i = v[j][2];
			//cout <<"hhh " <<i <<" " <<j <<" " <<c <<endl;
			ans += 1LL * (1 + c) * c / 2;
		}
		cout <<ans <<endl;
	}
	return 0;
}
//1 2 2 1 2 2 1 2 2 1 2 2
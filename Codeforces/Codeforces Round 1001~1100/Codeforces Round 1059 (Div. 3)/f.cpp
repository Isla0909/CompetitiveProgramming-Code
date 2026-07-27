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
	if(a.ff != b.ff) return a.ff < b.ff;
	return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> diff(n + 1);
		vector<bool> hasL(n + 1), hasR(n + 1);
		for(int i = 0; i < m; i ++)
		{
			int l, r; cin >>l >>r;
			hasL[l] = hasR[r] = 1;
			diff[l] ++;
			if(r + 1 <= n) diff[r + 1] --;
		}
		for(int i = 1; i <= n; i ++)
			diff[i] += diff[i - 1];
		
		int pos0 = -1, pos1 = -1;
		for(int i = 1; i <= n; i ++)
			if(diff[i] == m)
			{
				pos0 = i;
				break;
			}
		
		vector<int> st(n + 1); int idx = 0;
		vector<int> p(n + 1);
		if(pos0 != -1)
		{
			p[pos0] = idx ++; st[pos0] = 1;
			for(int i = 1; i <= n; i ++)
				if(!st[i]) p[i] = idx ++;
			tell(1, p);
		}
		else
		{
			for(int i = 1; i + 1 <= n; i ++)
			{
				if(hasR[i] && hasL[i + 1]) continue;
				if(!hasR[i])
				{
					pos0 = i, pos1 = i + 1;
					break;
				}
				if(!hasL[i + 1])
				{
					pos0 = i + 1, pos1 = i;
					break;
				}
			}

			if(pos0 == -1 && pos1 == -1) pos0 = 1, pos1 = n;

			p[pos0] = idx ++, st[pos0] = 1;
			p[pos1] = idx ++, st[pos1] = 1;
			for(int i = 1; i <= n; i ++)
				if(!st[i]) p[i] = idx ++;
			tell(1, p);	
		}
	}
	return 0;
}
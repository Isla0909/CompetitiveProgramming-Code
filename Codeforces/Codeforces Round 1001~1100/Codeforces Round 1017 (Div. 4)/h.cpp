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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

	vector<vector<int>> v(N);

	int T; cin >>T;
	while(T --)
	{
		int n, q; cin >>n >>q;
		vector<int> a(n + 1);
		
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x; a[i] = x;
			v[x].push_back(i);
		}
		while(q --)
		{
			int k, l, r; cin >>k >>l >>r;
			int idx = l, pre = l; i64 ans = 0;

			if(r - l + 1 <= 3000)
			{
				for(int i = l; i <= r; i ++)
				{
					while(k % a[i] == 0) k /= a[i];
					ans += k;
				}
				cout <<ans <<endl;
				continue;
			}

			while(k != 1 && idx <= r)
			{
				vector<int> div;
				for(int i = 1; i * i <= k; i ++)
				{
					if(k % i) continue;
					if(i != 1) div.push_back(i);
					if(i * i != k) div.push_back(k / i);
				}
				vector<int> pos;
				for(auto x : div)
				{
					auto left = lower_bound(v[x].begin(), v[x].end(), idx);
					auto right = upper_bound(v[x].begin(), v[x].end(), r);
					if(left == v[x].end() || left >= right) continue;
					//cout <<x <<" " <<left - v[x].begin() <<endl;
					pos.push_back(*left);
				}
				
				if(!pos.size()) break;
				int c = *min_element(pos.begin(), pos.end());
				ans += 1LL * k * (c - pre);
				while(k % a[c] == 0)
				{
					k /= a[c];
				}
				idx = c + 1, pre = c;
			}
			int c = r + 1;
			ans += 1LL * k * (c - pre);
			cout <<ans <<endl;
		}
		for(int i = 1; i <= n; i ++)
			v[a[i]].clear();
	}
	return 0;
}
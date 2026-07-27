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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se > b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<string> a(n);
		for(auto &x : a) cin >>x;

		vector<bool> st(n);

		vector b(m, vector<string>(n));
		for(int i = 0; i < m; i ++)
			for(int j = 0; j < n; j ++)
			{
				cin >>b[i][j];
				if(b[i][j] == a[j]) st[j] = 1;
			}
		bool f = 1;
		for(int i = 0; i < n; i ++)
			f &= st[i];
		if(!f)
		{
			cout <<-1 <<endl;
			continue;
		}

		int ans = 0, now = 0; vector<bool> h(n, 0);
		vector<bool> used(m, 0);
		bool first = 1;
		while(now != n)
		{
			vector<pii> v;
			for(int i = 0; i < m; i ++)
			{
				if(used[i]) continue;

				int c = 0;
				for(int j = 0; j < n; j ++)
				{
					if(!h[j] && b[i][j] == a[j])
						c ++;
				}
				v.emplace_back(i, c);
			}
			sort(v.begin(), v.end(), cmp);

			auto t = v[0];
			int idx = t.ff, c = t.se;
			
			if(first)
			{
			    first = 0;
			    ans += n;
			    now += c;
			}
            else ans += c * 2, now += c;
            
            //cout <<idx <<" " <<c <<" " <<ans <<endl;;
            
			used[idx] = 1;
			for(int i = 0; i < n; i ++)
				if(a[i] == b[idx][i])
					h[i] = 1;
		}
		cout <<ans <<endl;
	}
	return 0;
}
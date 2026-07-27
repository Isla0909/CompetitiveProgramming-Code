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
#define int long long
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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		vector g(n + 1, vector<int>(m + 1));
		vector<array<i64, 4>> v; vector<int> cnt(n + 1);
		vector<int> w(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x; i64 s = 0;
			w[i] = x;
			for(int j = 1; j <= m; j ++)
			{
				cin >>g[i][j];
				if(g[i][j] == -1) cnt[i] ++;
				else s += g[i][j];
			}
			v.push_back({x, i, s, s + cnt[i] * k});
		}
		sort(v.begin(), v.end(), [&](auto a, auto b)
		{
			if(a[0] != b[0]) return a[0] > b[0];
			else if(a[3] != b[3]) return a[3] > b[3];
			return cnt[a[1]] > cnt[b[1]];
		});

		i64 up = v[0][3]; bool f = 1;
		int id = v[0][1];
		for(int j = 1; j <= m; j ++)
			if(g[id][j] == -1) g[id][j] = k;

		for(int i = 1; i < v.size(); i ++)
		{
			int x = v[i][1], sumx = v[i][2];
			if(w[x] == w[id])//上限不受限
			{
				i64 s = up;
				if(sumx > s)
				{
					f = 0;
					break;
				}
				s -= sumx;
				for(int j = 1; j <= m; j ++)
					if(g[x][j] == -1)
					{
						if(s >= k) g[x][j] = k, s -= k;
						else if(s) g[x][j] = s, s = 0;
						else g[x][j] = 0;
					}
				up = accumulate(g[x].begin() + 1, g[x].end(), 0LL);
			}
			else
			{
				i64 s = up - 1;
				if(sumx > s)
				{
					f = 0;
					break;
				}
				s -= sumx;
				for(int j = 1; j <= m; j ++)
					if(g[x][j] == -1)
					{
						if(s >= k) g[x][j] = k, s -= k;
						else if(s) g[x][j] = s, s = 0;
						else g[x][j] = 0;
					}
				up = accumulate(g[x].begin() + 1, g[x].end(), 0LL);
			}
			id = x;
		}
		if(!f) cout <<"No" <<endl;
		else
		{
			cout <<"Yes" <<endl;
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= m; j ++)
					cout <<g[i][j] <<" \n"[j == m];
		}
	}
	return 0;
}
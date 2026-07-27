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

void display(vector<vector<int>> &g)
{
	for(int i = 0; i < g.size(); i ++)
	{
		for(int j = 0; j < g[i].size(); j ++)
			cout <<g[i][j];
		cout <<endl;
	}
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector g(n, vector<int>(n));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < i; j ++)
			g[i][j] = 1;

	//display(g);
	int c = 0;
	while(1)
	{
		for(int i = 0; i < n; i ++)
			shuffle(g[i].begin(), g[i].end(), rng);
		
		shuffle(g.begin(), g.end(), rng);

		vector<int> row(n), col(n);
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(g[i][j]) row[i] ++, col[j] ++;
		set<int> s1, s2;
		for(auto x : row)
			s1.insert(x);
		for(auto x : col)
			s2.insert(x);
		if(s1.size() != n || s2.size() != n) continue;

		vector st(n, vector<int>(n, -1));
		int cnt = 0;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(st[i][j] == -1)
				{
					cnt ++;
					queue<pii> q; st[i][j] = 1;
					q.emplace(i, j);
					while(q.size())
					{
						auto [x, y] = q.front(); q.pop();
						for(int u = 0; u < 4; u ++)
						{
							int a = x + dx[u], b = y + dy[u];
							if(a >= 0 && a < n && b >= 0 && b < n && st[a][b] == -1 && g[a][b] == g[i][j])
							{
								st[a][b] = 1;
								q.emplace(a, b);
							} 
						}
					}
				}
		if(cnt == n)
		{
			c ++;
			display(g);
			cout <<endl;
			//break;
		}
		if(c > 10) break;
	}
	return 0;
}

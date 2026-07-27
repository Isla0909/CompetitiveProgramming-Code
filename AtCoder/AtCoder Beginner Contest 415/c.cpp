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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;

		s = ' ' + s; int m = n + 1;
		vector<bool> st(1 << n);
		for(int i = 1; s[i]; i ++)
		{
			if(s[i] == '1') st[i] = 1;
		}
		

		queue<int> q; q.push(0);
		bool f = 0; vector<bool> vis(1 << n);
		while(q.size())
		{
			auto t = q.front(); q.pop();

			if(t == (1 << n) - 1)
			{
				f = 1;
				break;
			}

			for(int i = 0; i < n; i ++)
			{
				if(t >> i & 1) continue;

				int x = t + (1 << i);
				if(x >= (1 << n)) continue;
				if(!st[x] && !vis[x])
				{
					q.push(x);
					vis[x] = 1;
				}
			}
		}
		cout <<(f ? "Yes" : "No") <<endl;
	}
	return 0;
}
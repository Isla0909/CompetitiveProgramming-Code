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
#include <array>
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

struct cxy
{
	i64 need, gain;
	int ed;
	cxy() {}
	cxy(i64 need, i64 gain, int ed) : need(need), gain(gain), ed(ed) {}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; i64 x; cin >>n >>x;
		vector<vector<i64>> a(n + 1), b(n + 1);
		vector<int> siz(n + 1);
		vector<vector<cxy>> seg(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>siz[i];
			a[i].resize(siz[i] + 1), b[i].resize(siz[i] + 1);
			for(int j = 1; j <= siz[i]; j ++)
				cin >>a[i][j];
			for(int j = 1; j <= siz[i]; j ++)
				cin >>b[i][j];

			i64 sum = 0, need = 0;
			for(int j = 1; j <= siz[i]; j ++)
			{
				need = max(need, a[i][j] - sum);
				sum += b[i][j] - a[i][j];

				if(sum > 0)
				{
					seg[i].emplace_back(need, sum, j);
					sum = need = 0;
				}
			}
		}
		vector<int> pos(n + 1), h(n + 1);
		priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> q;
		for(int i = 1; i <= n; i ++)
			if(seg[i].size())
				q.emplace(seg[i][0].need, i);

		while(q.size())
		{
			auto [need, id] = q.top();
			if(need > x) break;

			q.pop();

			int p = pos[id];
			x += seg[id][p].gain;

			h[id] = seg[id][p].ed;
			pos[id] ++;

			if(pos[id] < seg[id].size())
				q.emplace(seg[id][p + 1].need, id);
		}

		int ansh = -1, ansid = -1;
		for(int i = 1; i <= n; i ++)
		{
			i64 now = x;
			int j = h[i] + 1;
			while(j <= siz[i] && now >= a[i][j])
			{
				now += b[i][j] - a[i][j];
				j ++;
			}
			if(j - 1 > ansh)
			{
				ansh = j - 1;
				ansid = i;
			}
		}
		cout <<ansh <<" " <<ansid <<endl;
	}
	return 0;
}

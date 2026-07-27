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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int p[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		for(int i = 0; i <= n; i ++)
			p[i] = i;

		vector<pii> v;
		for(int i = 0; i < n; i ++)
		{
			int op; cin >>op;
			if(op == 1)
			{
				int x; cin >>x;
				v.emplace_back(x, n - 1);
			}
			else if(op == 2)
			{
				int x; cin >>x;
				v.emplace_back(0, x);
			}
			else
			{
				int x, y; cin >>x >>y;
				v.emplace_back(x, y);
			}
		}
		sort(v.begin(), v.end(), cmp);
		char c = 'Y';
		for(int i = 0; i < n; i ++)
		{
			auto [l, r] = v[i];
			int pos = find(l);
			if(pos > r)
			{
				c = 'N';
				break;
			}
			p[pos] = pos + 1;
		}
		cout <<c <<endl;
	}
	return 0;
}

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

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}

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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> ans;
		vector<int> a(n + 1);
		set<int> s;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			s.insert(a[i]);
		}
		int x = a[n], y;
		if(s.size() == n) y = a[1];
		else
		{
			for(int i = 1; i <= n; i ++)
				if(s.find(i) == s.end())
				{
					y = i;
					break;
				}
		}
		ans.push_back(y);
		k --;
		while(k --)
		{
			int c = rand(1, n);
			while(c == x || c == y) c = rand(1, n);
			ans.push_back(c);
			x = y, y = c;
		}
		tell(0, ans);
	}
	return 0;
}
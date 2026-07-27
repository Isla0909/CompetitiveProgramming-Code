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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1);
		vector<int> c1, c2;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(a[i] & 1) c1.push_back(a[i]);
			else c2.push_back(a[i]);
		}

		if(max(c1.size(), c2.size()) == n) cout <<0 <<endl;
		else
		{
			int s1 = *max_element(c1.begin(), c1.end()), s2 = *max_element(c2.begin(), c2.end());
			int ans = 0;
			sort(c2.begin(), c2.end());
			for(int i = 0; i < c2.size(); i ++)
			{
				if(s1 < c2[i])
				{
					while(s1 < s2) ans ++, s1 += s2;
				}
				ans ++;
				c2[i] += s1;
				if(c2[i] > s1) s1 = c2[i];
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}

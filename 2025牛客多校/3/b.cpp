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

int hbit(int x)
{
	return __lg(x);
}

int getbit(int x, int c)
{
	return x >> c & 1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int a, b, c; cin >>a >>b >>c;
		if(a == 0 && b == 0)
		{
			if(!c) cout <<0 <<endl <<endl;
			else cout <<-1 <<endl;
			continue;
		}

		vector<int> ans;
		if(hbit(a) < hbit(b))
		{
			a ^= b;
			ans.push_back(3);
		}
		if(hbit(a) > hbit(b))
		{
			b ^= a;
			ans.push_back(4);
		}

		int h = hbit(a);
		for(int i = 30; i > h; i --)
		{
			if(getbit(c, i) != getbit(a, h))
			{
				a ^= b;
				ans.push_back(3);
			}
			a <<= 1;
			ans.push_back(1);
		}
		for(int i = h; i >= 0; i --)
		{
			if(getbit(c, i) != getbit(a, i))
			{
				a ^= b;
				ans.push_back(3);
			}
			b >>= 1;
			ans.push_back(2);
		}
		ans.push_back(4);
		cout <<ans.size() <<endl;
		tell(0, ans);
	}
	return 0;
}

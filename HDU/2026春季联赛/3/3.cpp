#pragma GCC optimize ("O3")
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

int calc(int a, int b)
{
	if(a > b) swap(a, b);
	if(a == 1) return b;
	return a + b;
}

pii decode(int x)
{
	if(x <= 3) return {1, x};
	if(x == 6) return {3, 3};
	return {2, x - 2};
}

int lowbit(int x)
{
	return x & -x;
}

bool is_perfect(int x)
{
	return x == lowbit(x);
}

int ceilLog(int x)
{
	return __lg(2 * x - 1);
}

int lev(int x)//求一个数的二进制有多少位
{
	return __lg(x);
}

int len(int x)
{
	return __lg(x) + 1;
}

int hbit(int x)
{
	return __lg(x);
}

int getbit(int x, int c)
{
	return (x >> c & 1);
}

int count1(int x)
{
	return __builtin_popcount(x);
}

int count0(int x)
{
	return len(x) - count1(x);
}

int remove_bit(int mask, int x)//删除二进制的某一位并自动右移
{
	return (mask & ((1 << x) - 1)) | ((mask >> (x + 1)) << x);
}

struct cxy
{
	int a, b;
	int w;
	cxy() {}
	cxy(int a, int b, int w) : a(a), b(b), w(w) {}
};

int f[20][8][8][8];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{	
		for(int u = 0; u < 20; u ++)
			for(int i = 0; i < 8; i ++)
				for(int j = 0; j < 8; j ++)
					for(int k = 0; k < 8; k ++)
						f[u][i][j][k] = -INF;
		f[0][0][0][0] = 0;
		int n; cin >>n;
		vector<vector<int>> vec(7);
		for(int i = 0; i < n; i ++)
		{
			int a, b, w; cin >>a >>b >>w;
			vec[calc(a, b)].push_back(w);
		}
		for(int i = 1; i <= 6; i ++)
		{
			if(vec[i].empty()) continue;
			sort(vec[i].begin(), vec[i].end(), greater<>());
			if(i == 1)
			{
				while(vec[i].size() > 9) vec[i].pop_back();
			}
			else if(i == 2)
			{
				while(vec[i].size() > 4) vec[i].pop_back();
			}
			else if(i == 3)
			{
				while(vec[i].size() > 3) vec[i].pop_back();
			}
			else
			{
				while(vec[i].size() > 1) vec[i].pop_back();
			}
		}
		vector<cxy> v;
		for(int i = 1; i <= 6; i ++)
			for(auto x : vec[i])
			{
				auto [a, b] = decode(i);
				v.emplace_back(a, b, x);
			}

		vector pre(7, vector<int>(10));
		
	}	
	return 0;
}

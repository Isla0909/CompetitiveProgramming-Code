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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
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
	return __lg(2 * x + 1);
}

int lev(i64 x)//求一个数的二进制有多少位
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
	int res = 0;
	while(x)
	{
		x -= lowbit(x);
		res ++;
	}
	return res;
}

int count0(int x)
{
	return len(x) - count1(x);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int k; i64 x; cin >>k >>x;
		int a = 1LL << k, b = a;

		vector<int> ans;
		int ea = x, eb = (1LL << (k + 1)) - x;
		while(!(ea == (1LL << k)))
		{
			if(eb >= ea)
			{
				ans.push_back(1);
				ea <<= 1;
				eb = (1LL << (k + 1)) - ea;
			}
			else
			{
				ans.push_back(2);
				eb <<= 1;
				ea = (1LL << (k + 1)) - eb;
			}
		}
		reverse(ans.begin(), ans.end());
		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
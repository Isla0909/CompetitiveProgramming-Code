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

constexpr int N = 3e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

//等价于求最大异或和最小异或

int trie[N * 30][2];
int idx[N * 30 * 2];
int tot;

int newNode()
{
	tot ++;
	fill(trie[tot], trie[tot] + 2, 0);
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

void insert(int x, int pos)
{
	int p = 1;
	for(int i = 29; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(!trie[p][d]) trie[p][d] = newNode();
		p = trie[p][d];
	}
	idx[p] = pos;
}

pii max_query(int x)
{
	int p = 1, res = 0;
	for(int i = 29; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(!trie[p][d ^ 1]) p = trie[p][d];
		else
		{
			p = trie[p][d ^ 1];
			res |= 1 << i;
		}
	}
	return {res, idx[p]};
}

pii min_query(int x)
{
	int p = 1, res = 0;
	for(int i = 29; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(trie[p][d]) p = trie[p][d];
		else
		{
			p = trie[p][d ^ 1];
			res |= 1 << i;
		}
	}
	return {res, idx[p]};
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n, q; cin >>n >>q;
	vector<i64> c(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x; c[i] = x;
		insert(x, i);
	}

	while(q --)
	{
		int a, b; cin >>a >>b;
	
		auto [s1, p1] = max_query(a);
		auto [s2, p2] = min_query(a);

		auto f = [&](int i) -> i64
		{
			return (a ^ c[i]) - b;
		};

		if(f(p1) * f(p2) <= 0)
		{
			int l = p1, r = p2;
			if(l > r) swap(l, r);

			l --;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(f(mid) * f(r) > 0) r = mid;
				else l = mid;
			}
			cout <<l <<endl;
			assert(f(l) * f(l + 1) <= 0);
		}
		else cout <<-1 <<endl;
	}

	return 0;
}
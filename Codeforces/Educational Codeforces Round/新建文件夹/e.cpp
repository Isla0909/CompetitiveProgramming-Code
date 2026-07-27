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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int trie[N * 30][2], cnt[N * 30];
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

void add(int x, int c)
{
	int p = 1;
	for(int i = 30; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(!trie[p][d]) trie[p][d] = newNode();
		p = trie[p][d];
		cnt[p] += c;
	}
}

int query(int x, int l)
{
	int p = 1, ans = 0;
	for(int i = 30; i >= 0; i --)
	{
		if(!p) break;
		int d1 = x >> i & 1, d2 = l >> i & 1;
		if(d2 == 0) p = trie[p][d1];
		else//d2 = 1
		{
			if(trie[p][d1]) ans += cnt[trie[p][d1]];
			p = trie[p][d1 ^ 1];
		}
	}
	return ans;
}
//注:函数开始时必须调用initial

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int q; cin >>q;
	while(q --)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int x; cin >>x;
			add(x, 1);
		}
		else if(op == 2)
		{
			int x; cin >>x;
			add(x, -1);
		}
		else
		{
			int x, l; cin >>x >>l;
			cout <<query(x, l) <<endl;
		}
	}
	return 0;
}

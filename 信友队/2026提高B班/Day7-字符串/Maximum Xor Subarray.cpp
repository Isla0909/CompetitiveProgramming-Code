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

constexpr int N = 2e5 + 10, M = 30 * N, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int trie[M][2];
int tot = 0;

int newNode()
{
	tot ++;
	trie[tot][0] = trie[tot][1] = 0;
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

void insert(int x)
{
	int p = 1;
	for(int i = 29; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(!trie[p][d]) trie[p][d] = newNode();
		p = trie[p][d];
	}
}

int query(int x)
{
	int p = 1, res = 0;
	for(int i = 29; i >= 0; i --)
	{
		int d = x >> i & 1;
		if(trie[p][d ^ 1])
		{
			res |= 1 << i;
			p = trie[p][d ^ 1];
		}
		else p = trie[p][d];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	vector<int> a(n + 1), pre(n + 1);
	insert(pre[0]);
	for(int i = 1; i <= n; i ++)
	{
		cin >>a[i];
		pre[i] = pre[i - 1] ^ a[i];
		insert(pre[i]);
	}

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, query(pre[i]));
	cout <<ans <<endl;
	return 0;
}

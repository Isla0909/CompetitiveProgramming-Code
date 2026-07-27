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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int trie[N][26], cnt[N];
int val[N][26];
int tot;

int newNode()
{
	tot ++;
	fill(trie[tot], trie[tot] + 26, 0);
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

void add(const string &s, char offset = 'a')
{
	int p = 1;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - offset;
		if(!trie[p][x]) trie[p][x] = newNode();
		//cout <<p <<" " <<x <<endl;
		val[p][x] ++, p = trie[p][x];
	}
	cnt[p] ++;
}

int query(const string &s, char offset = 'a')
{
	int res = 0;
	int p = 1;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - offset;
		res += val[p][x];
		p = trie[p][x];
		if(!p) return res;
	}
	return res;
}
//注:函数开始时必须调用initial

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	initial();

	int n; cin >>n;
	vector<string> v; int ans = 0;
	for(int i = 0; i < 2 * n; i ++)
	{
		string s; cin >>s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < 2 * n; i ++)
	{
		if(i % 2 == 0) add(v[i]);
	}
	for(int i = 0; i < 2 * n; i ++)
		if(i & 1) ans += query(v[i]);
	cout <<ans <<endl;
	return 0;
}
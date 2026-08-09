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

int trie[N][26], cnt[N * 26];
int tot = 0;

int newNode()
{
	tot ++;
	memset(trie[tot], 0, sizeof trie[tot]);
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

int ans = 0;

void insert(string &s, const char offset = 'a')
{
	int p = 1, ed = 0;
	for(auto c : s)
	{
		int x = c - 'a';
		if(!trie[p][x]) trie[p][x] = newNode();

		p = trie[p][x];

		if(cnt[p]) ed ++;
	}
	cnt[p] ++;

	ans = max(ans, ed + 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		insert(s);
	}
	cout <<ans <<endl;
	return 0;
}

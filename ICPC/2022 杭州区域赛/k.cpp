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

constexpr int N = 1e6 + 5e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
constexpr char c = 'a' - 1;

int trie[N][27], cnt[N][27];
i64 f[27][27];
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

void insert(const string &s, char offset = 'a')
{
	int p = 1;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - offset;
		for(int y = 0; y < 27; y ++)
		{
			if(y != x) f[y][x] += cnt[p][y];
		}

		if(!trie[p][x]) trie[p][x] = newNode();

		cnt[p][x] ++;
		p = trie[p][x];
	}
	int x = 26;
	for(int y = 0; y < 27; y ++)
	{
		if(y != x) f[y][x] += cnt[p][y];
	}

	if(!trie[p][x]) trie[p][x] = newNode();

	cnt[p][x] ++;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n, q; cin >>n >>q;
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		insert(s);
	}

	while(q --)
	{
		string s; cin >>s;
		vector<int> rank(27);
		rank[26] = 0;
		for(int i = 0; s[i]; i ++)
			rank[s[i] - 'a'] = i + 1;

		i64 ans = 0;
		for(int i = 0; i < 27; i ++)
			for(int j = 0; j < 27; j ++)
				if(rank[i] < rank[j])
					ans += f[j][i];
		cout <<ans <<endl;
	}

	return 0;
}
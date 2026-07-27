#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
constexpr long long inf = 1e18;

typedef pair<int, int> pii;

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int trie[N][26];
int cnt[N * 26];
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

void insert(string s)
{
	int p = 1;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - 'a';
		if(!trie[p][x]) trie[p][x] = newNode();
		p = trie[p][x];

		cnt[p] ++;
	}
}

i64 query(string s)
{
	int p = 1; i64 res = 0;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - 'a';
		//cout <<p <<" " <<x <<endl;
		p = trie[p][x];
		//cout <<p <<" " <<res <<endl;
		//cout <<p <<" " <<trie[1][0] <<endl;
		if(!p) return res;
		else res += cnt[p];
		//cout <<"123" <<endl;
	}
	//cout <<endl;
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	i64 ans = 0;
	vector<string> v(n);
	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		v[i] = s;
		insert(s);
	}
	//cout <<cnt[2] <<endl;
	for(int i = 0; i < n; i ++)
	{
		string s = v[i];
		ans += query(s);
		ans %= mod;
	}
	cout <<ans <<endl;
	return 0;
}
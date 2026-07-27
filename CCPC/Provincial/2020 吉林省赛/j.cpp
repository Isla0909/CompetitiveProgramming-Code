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

constexpr int N = 20000, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int f[N][2];

int decode(const string &s)
{
	int x = 0;
	for(int i = 0; i < 9; i ++)
	{
		int v = 0;
		if(s[i] == 'O') v = 1;
		else if(s[i] == 'X') v = 2;
		x = x * 3 + v; 
	}
	return x;
}

int calc(const string &s)
{
	static int line[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};

	int a = 0, b = 0;
	for(int i = 0; i < 8; i ++)
	{
		char x = s[line[i][0]], y = s[line[i][1]], z = s[line[i][2]];
		if(x == y && y == z && x != '.')
		{
			if(x == 'O') a ++;
			else b ++;
		}
	}
	return a - b;
}

int dfs(string &s, int u)
{
	int x = decode(s);
	if(f[x][u] != INF) return f[x][u];

	int c = 0;
	for(int i = 0; s[i]; i ++)
		c += (s[i] == '.');
	if(!c) return f[x][u] = calc(s);

	if(u == 1)
	{
		int mmax = -INF;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '.')
			{
				s[i] = 'O';
				mmax = max(mmax, dfs(s, u ^ 1));
				s[i] = '.';
			}
		}
		return f[x][u] = mmax;
	}
	else
	{
		int mmin = INF;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '.')
			{
				s[i] = 'X';
				mmin = min(mmin, dfs(s, u ^ 1));
				s[i] = '.';
			}
		}
		return f[x][u] = mmin;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(f, 0x3f, sizeof f);

	int T; cin >>T;
	while(T --)
	{
		int u; cin >>u;
		string s = "";
		for(int i = 0; i < 3; i ++)
		{
			string t; cin >>t;
			s += t;
		}
		dfs(s, u);
		cout <<f[decode(s)][u] <<endl;
	}
	return 0;
}

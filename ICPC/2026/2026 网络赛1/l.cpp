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

constexpr int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int tr[N][26];
int f[N], cnt[N];
int tot;
i64 ans;

int newNode()
{
	tot ++;
	return tot;
}

void initial()
{
	tot = 0;
	newNode();
}

void add(const string &s)
{
	int p = 1, d = 0;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - 'a';

		if(!tr[p][x]) tr[p][x] = newNode();
		p = tr[p][x];

		d ++;
		int c = ++ cnt[p];

		if(d > f[c])
		{
			ans -= f[c] ^ c;
			f[c] = d;
			ans += f[c] ^ c;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	int n; cin >>n;
	for(int i = 1; i <= n; i ++)
	{
		string s; cin >>s;
		ans += i;
		add(s);
		cout <<ans <<endl;
	}
	return 0;
}

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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector g(4, vector<int>(4));
	vector<int> row(4), col(4), cnt(10);
	for(int i = 1; i <= 3; i ++)
		for(int j = 1; j <= 3; j ++)
		{
			cin >>g[i][j];
			row[i] += g[i][j];
			col[j] += g[i][j];
			cnt[g[i][j]] ++;
		}
	bool f = 1;
	for(int i = 1; i <= 9; i ++)
		if(cnt[i] != 1) f = 0;
	int c = row[1];
	if(row[2] != c || row[3] != c || col[1] != c || col[2] != c || col[3] != c || g[1][1] + g[2][2] + g[3][3] != c || g[1][3] + g[2][2] + g[3][1] != c) f = 0;
	cout <<(f ? "Yes" : "No") <<endl;
	return 0;
}

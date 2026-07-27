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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int nex[N], nexval[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >>s;

	string p = s.substr(0, 1000);
	int n = p.size(), m = s.size();

	for(int i = 1, j = 0; i < n; i ++)
	{
		while(j && p[i] != p[j]) j = nex[j];

		if(p[j] == p[i]) nex[i + 1] = ++ j;
	}

	for(int i = 0; i <= n; i ++)
	{
		int k = nex[i];
		if(p[i] == p[k]) nexval[i] = nexval[k];
		else nexval[i] = k;
	}

	int cnt = 0;
	for(int i = 0, j = 0; i < m; i ++)
	{
		while(j && s[i] != p[j]) j = nexval[j];

		if(s[i] == p[j]) j ++;

		if(j == n)
		{
			cnt ++;
			j = 0;
		}
	}
	//cout <<cnt <<endl;
	cout <<(cnt >= 100 && cnt <= 1000 ? "No" : "Yes") <<endl;
	return 0;
}

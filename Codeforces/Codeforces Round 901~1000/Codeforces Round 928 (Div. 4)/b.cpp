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

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector g(n, vector<char>(n));
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				cin >>g[i][j];

		bool f = 0, h = 0;
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < n; j ++)
				if(g[i][j] == '1' && i + 1 < n && j + 1 < n)
				{
					if(g[i + 1][j] == '1' && g[i][j + 1] == '1') f = 1;
					h = 1;
					break;
				}
			if(h) break;
		}
		cout <<((f) ? "SQUARE" : "TRIANGLE") <<endl;
	}
	return 0;
}
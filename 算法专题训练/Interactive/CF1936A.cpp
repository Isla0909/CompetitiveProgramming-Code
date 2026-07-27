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

int query(int a, int b, int c, int d)
{
	cout <<"? " <<a <<" " <<b <<" " <<c <<" " <<d <<endl;
	char ch; cin >>ch;
	if(ch == '=') return 0;
	else if(ch == '>') return 1;
	return 2;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int h = __lg(n - 1);
		int mask = (1 << (h + 1)) - 1;
		int M = n - 1, m = mask ^ M;

		int x = 0;
		for(int i = 1; i < n; i ++)
		{
			int c = query(x, x, i, i);
			if(c == 2) x = i;
		}

		int a = x, b = 0, c = x;
		vector<int> ans;
		ans.push_back(0);
		for(int y = 1; y < n; y ++)
		{
			int v = query(a, b, c, y);
			if(v == 2)
			{
				ans.clear();
				b = y;
				ans.push_back(y);
			}
			else if(!v) ans.push_back(y);
		}

		int y = ans[0];
		for(int i = 1; i < ans.size(); i ++)
		{
			int c = query(y, y, ans[i], ans[i]);
			if(c == 1) y = ans[i];
		}
		cout <<"! " <<x <<" " <<y <<endl;
	}
	return 0;
}

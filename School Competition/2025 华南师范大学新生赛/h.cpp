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

char g[5][37] = {"*****...******...***...**...**....**",
				 "**......**.......****..**...**....**", 
				 "*****...**.......**.**.**...**....**", 
				 "...**...**.......**..****...**....**", 
				 "*****...******...**...***...********"};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	int k; cin >>k;
	for(int i = 0; i < 5; i ++)
	{
		for(int z = 0; z < k; z ++)
		{
			for(int j = 0; j < 36; j ++)
			{
				for(int u = 0; u < k; u ++)
					cout <<g[i][j];
			}
			cout <<endl;
		}
	}

	return 0;
}

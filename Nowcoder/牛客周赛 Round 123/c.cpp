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

vector<int> f[N][4];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	for(int i = 0; i < n; i ++)
	{
		int x; char c; cin >>x >>c;
		if(f[x][c - 'A'].empty()) f[x][c - 'A'].push_back(i + 1);
	}

	vector<pii> ans;
	for(int i = 1; i <= 2e5; i ++)
	{
		int s = 0, M = 0;
		for(int j = 0; j < 4; j ++)
		{
			s += f[i][j].size();
			if(f[i][j].size() > f[i][M].size()) M = j;
		}
		
		if(!s) continue;
		if(f[i][M].size() <= s / 2)
		{
			for(int x = 0; x < 4; x ++)
				for(int y = x + 1; y < 4; y ++)
				{
					if(f[i][x].empty()) break;

					while(f[i][x].size() && f[i][y].size())
					{
						auto a = f[i][x].back(); f[i][x].pop_back();
						auto b = f[i][y].back(); f[i][y].pop_back();
						ans.emplace_back(a, b);
					}
				}
		}
		else
		{
			for(int j = 0; j < 4; j ++)
			{
				if(j == M) continue;
				while(f[i][j].size())
				{
					auto p = f[i][j].back();
					f[i][j].pop_back();
					ans.emplace_back(p, f[i][M].back());
					f[i][M].pop_back();
				}
			}
		}
	}


	cout <<ans.size() * 2 <<endl;
	for(auto [x, y] : ans)
		cout <<x <<" " <<y <<endl;
	return 0;
}

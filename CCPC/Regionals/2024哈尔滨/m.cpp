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
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
	string type;
	int a, b, c, d;
	char x;
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<cxy> v(n);

	auto find = [&](int u, int x, int y) -> void
	{
		bool f = 0;
		//cout <<x <<" " <<y <<endl;
		for(int i = u - 1; i >= 0; i --)
		{
			if(v[i].type == "Render") continue;

			if(v[i].type == "Circle")
			{
				int a = v[i].a, b = v[i].b, r = v[i].c; char c = v[i].x;
				if(1LL * abs(x - a) * abs(x - a) + 1LL * abs(y - b) * abs(y - b) <= 1LL * r * r)
				{
					f = 1;
					cout <<c;
					return ;
				}
			}
			else
			{
				auto [_, x1, y1, x2, y2, c] = v[i];
				if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
				{
					f = 1;
					cout <<c;
					return ;
				}
			}
		}
		cout <<'.';
	};

	for(int u = 0; u < n; u ++)
	{
		string s; cin >>s;
		v[u].type = s;
		if(s == "Circle") cin >>v[u].a >>v[u].b >>v[u].c >>v[u].x;
		else if(s == "Rectangle") cin >>v[u].a >>v[u].b >>v[u].c >>v[u].d >>v[u].x;
		else
		{
			int x1, x2, y1, y2;
			cin >>x1 >>y1 >>x2 >>y2;
			//cout <<x1 <<" " <<y1 <<" " <<x2 <<" " <<y2 <<endl;
			for(int i = y2; i >= y1; i --)
				for(int j = x1; j <= x2; j ++)
				{
					find(u, j, i);
					if(j == x2) cout <<endl;
				}
		}
	}

	return 0;
}
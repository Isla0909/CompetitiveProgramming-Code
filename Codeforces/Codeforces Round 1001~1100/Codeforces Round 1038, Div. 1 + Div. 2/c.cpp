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

struct Point
{
	int x, y;
	int id;
};

bool cmpx(const Point &a, const Point &b)
{
	return a.x < b.x;
}

bool cmpy(const Point &a, const Point &b)
{
	return a.y < b.y;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<Point> p(n);
		for(int i = 0; i < n; i ++)
		{
			cin >>p[i].x >>p[i].y;
			p[i].id = i;
		}
		vector<int> col(n);
		sort(p.begin(), p.end(), cmpx);
		for(int i = 0; i < n / 2; i ++) col[p[i].id] ++;
		sort(p.begin(), p.end(), cmpy);
		for(int i = 0; i < n / 2; i ++) col[p[i].id] += 2;

		vector<vector<int>> v(4);
		for(int i = 0; i < n; i ++)
			v[col[i]].push_back(i);
		for(int i = 0; i < v[1].size(); i ++)
			cout <<v[1][i] + 1 <<" " <<v[2][i] + 1 <<endl; 
		for(int i = 0; i < v[0].size(); i ++)
			cout <<v[0][i] + 1 <<" " <<v[3][i] + 1 <<endl;
	}
	return 0;
}
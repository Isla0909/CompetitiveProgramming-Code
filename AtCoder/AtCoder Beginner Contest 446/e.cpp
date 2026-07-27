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

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, A, B; cin >>M >>A >>B;
	queue<pii> q;
	vector st(M, vector<int>(M));
	for(int i = 0; i < M; i ++)
	{
		st[0][i] = 1;
		q.emplace(0, i);
	}

	auto get = [&](int c) -> vector<int>
	{
		vector<int> v;
		int x, y;
		int d = exgcd(B, M, x, y);
		if(c % d) return v;

		int x0 = 1LL * c / d * x % M;
		if(x0 < 0) x0 += M;

		int k = M / d;
		for(int i = 0; i < d; i ++)
			v.push_back((x0 + 1LL * i * k) % M);
		return v;
	};

	while(q.size())
	{
		auto [c, d] = q.front(); q.pop();

		int x = (d - A * c) % M;
		if(x < 0) x += M;

		vector<int> v = get(x);

		for(auto pre : v)
		{
			if(!st[pre][c])
			{
				st[pre][c] = 1;
				q.emplace(pre, c);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < M; i ++)
		for(int j = 0; j < M; j ++)
			if(!st[i][j]) ans ++;
	cout <<ans <<endl;

	return 0;
}

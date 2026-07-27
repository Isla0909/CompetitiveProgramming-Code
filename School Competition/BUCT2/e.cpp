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

	i64 x = 59084709587505;
	vector<i64> p3(60, -1), p5(60, -1), p7(60, -1);
	p3[0] = p5[0] = p7[0] = 1;
	for(int i = 1; i < 60; i ++)
	{
		p3[i] = p3[i - 1] * 3;
		if(p3[i] > x) p3[i] = -1;
		p5[i] = p5[i - 1] * 5;
		if(p5[i] > x) p5[i] = -1;
		p7[i] = p7[i - 1] * 7;
		if(p7[i] > x) p7[i] = -1;
	}

	int cnt = 0;
	for(int i = 0; p3[i] != -1; i ++)
		for(int j = 0; p5[j] != -1; j ++)
		{
			i128 s = (i128)p3[i] * p5[j];
			if(s > x) break;

			for(int k = 0; p7[k] != -1; k ++)
			{
				i128 ss = s * p7[k];
				if(ss > x) break;

				if(ss <= x) cnt ++;
			}
		}
		cout <<cnt - 1 <<endl;
	return 0;
}

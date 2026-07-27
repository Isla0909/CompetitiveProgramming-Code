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

i64 lcm(int a, int b)
{
	return 1LL * a / __gcd(a, b) * b;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >>a[i];

	vector<vector<int>> div(n + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; i * j <= n; j ++)
			div[i * j].push_back(i);

	int len = 500;
	vector<i64> sum(len + 1);//sum[i]表示所有i的倍数的和 -> 真实值
	for(int i = 1; i <= len; i ++)
		for(int j = 1; i * j <= n; j ++)
			sum[i] += a[i * j];

	vector<i64> c(n + 1);//c[i] 表示需要给所有i的倍数额外增加的增量
	while(m --)
	{
		int op; cin >>op;
		if(op == 1)
		{
			int x, k; cin >>x >>k;
			if(x <= len) c[x] += k;//小数在数组上修改
			else//大数暴力修改
			{
				for(int i = x; i <= n; i += x)
					a[i] += k;
			}
			for(int i = 1; i <= len; i ++)
				sum[i] += 1LL * k * (n / lcm(i, x));
		}
		else if(op == 2)
		{
			int x, k; cin >>x >>k;
			for(auto i : div[x])
				a[i] += k;

			for(int i = 1; i <= len; i ++)
				if(x % i == 0)//x有多少个因子是i的倍数呢?也就是(x / i)这个数因子的个数
					sum[i] += 1LL * k * div[x / i].size();
		}
		else if(op == 3)
		{
			int x; cin >>x;
			if(x <= len) cout <<sum[x] <<endl;
			else
			{
				i64 res = 0;
				for(int i = x; i <= n; i += x)
					res += a[i];
				for(int i = 1; i <= len; i ++)
					res += c[i] * (n / lcm(i, x));
				cout <<res <<endl; 
			}
		}
		else
		{
			int x; cin >>x;
			i64 res = 0;
			for(auto i : div[x])
			{
				res += a[i];
				if(i <= len) res += c[i] * div[x / i].size();
			}
			cout <<res <<endl;
		}
	}
	return 0;
}
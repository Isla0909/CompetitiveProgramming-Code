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

//1. 拆位算贡献
//2. 字典树 线性基
//3. 偶数个相同的数异或等于 0, 奇数个相同的数异或等于 1
//4. 异或是不进位加法

//x ^ y <= x + y
//当x, y >= 2, x * y >= x + y >= x ^ y

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	i64 res = 1;
	int cnt = 0; vector<int> v;
	for(int i = 1; i <= n; i ++)
	{
		int x; cin >>x;
		if(x & 1 && x != 1) res = res * x % mod;
		else if(x & 1) cnt ++;
		else v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < min((int)v.size(), cnt); i ++)
		res = res * (v[i] + 1) % mod;
	for(int i = cnt; i < v.size(); i ++)
		res = res * v[i] % mod;
	cout <<res <<endl;
	return 0;
}

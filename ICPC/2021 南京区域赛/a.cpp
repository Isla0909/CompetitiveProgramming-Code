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

	int n, a, b; cin >>n >>a >>b;

	auto calc = [&](char c1, char c2, int x, int y) -> string
	{
		string s = "";
		for(int i = 1; i < n; i ++)
		{
			s.push_back(c1);
			s.push_back(c2);
		}
		for(int i = 0; i < abs(x - a); i ++)
		{
			if(x < a) s.push_back('D');
			else s.push_back('U');
		}
		for(int i = 0; i < abs(y - b); i ++)
		{
			if(y < b) s.push_back('R');
			else s.push_back('L');
		}
		return s;
	};

	string s = calc('L', 'U', 1, 1);
	if(s.size() <= 3 * (n - 1)) cout <<s <<endl;
	else cout <<calc('R', 'D', n, n);
	return 0;
}
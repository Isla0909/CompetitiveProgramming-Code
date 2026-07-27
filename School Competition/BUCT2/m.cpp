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

bool check(int x)
{
	if(x % 100 == 0) return x % 400 == 0;
	return x % 4 == 0;
}

string get(int y, int m, int d)
{
	char s[20];
	sprintf(s, "%d%02d%02d", y, m, d);
	string res = "";
	for(int i = 0; s[i]; i ++)
		res.push_back(s[i]);
	return res;
}

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//cout <<get(2017, 4, 4) <<endl;

	int y, m, k;
	while(cin >>y >>m >>k)
	{
		if(check(y)) month[2] = 29;
		else month[2] = 28;
		int cnt = 0;
		for(int d = 1; d <= month[m]; d ++)
		{
			string s = get(y, m, d);
			for(int j = 0; s[j]; j ++)
				cnt += (s[j] - '0' == k);
		}
		cout <<cnt <<endl;
	}
	return 0;
}

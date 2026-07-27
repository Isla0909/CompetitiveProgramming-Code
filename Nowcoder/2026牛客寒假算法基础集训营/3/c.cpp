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

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;

		string s0 = "", s1 = "";
		for(int i = 0; i < n; i ++)
		{
			if(i % 2 == 0) s0.push_back('0'), s1.push_back('1');
			else s0.push_back('1'), s1.push_back('0');
		}
		
		auto calc = [&](const string &t) -> vector<int>
		{
			vector<int> v;
			for(int i = 0; i < n; i ++)
				if(s[i] == t[i])
				{
					if(s[i] == '0') v.push_back(1);
					else v.push_back(-1);
				}
			return v;
		};
		
		auto get = [&](const vector<int> &v)
		{
			int sum = 0, M = 0, m = 0;
			for(auto x : v)
			{
				sum = max(0, sum) + x;
				M = max(M, sum);
			}
			sum = 0;
			for(auto x : v)
			{
				sum = min(0, sum) + x;
				m = min(m, sum);
			}
			return max(M, abs(m));
		};

		auto v0 = calc(s0), v1 = calc(s1);
		cout <<min(get(v0), get(v1)) <<endl;
	}
	return 0;
}

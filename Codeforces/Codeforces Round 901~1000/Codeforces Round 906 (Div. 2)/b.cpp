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

bool check(string s)
{
	for(int i = 1; i < s.size(); i ++)
		if(s[i] == s[i - 1]) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		string s, t; cin >>s >>t;
		if(check(s)) cout <<"Yes" <<endl;
		else if(!check(t)) cout <<"No" <<endl;
		else if(t[0] != t[m - 1]) cout <<(check(s) ? "Yes" : "No") <<endl;
		else
		{
			bool f = 1;
			if(t[0] == '0')
			{
				for(int i = 1; i < n; i ++)
					if(s[i] == s[i - 1] && s[i] == '0')
					{
						f = 0;
						break;
					}
			}
			else
			{
				for(int i = 1; i < n; i ++)
					if(s[i] == s[i - 1] && s[i] == '1')
					{
						f = 0;
						break;
					}
			}
			cout <<(f ? "Yes" : "No") <<endl;
		}
	}
	return 0;
}
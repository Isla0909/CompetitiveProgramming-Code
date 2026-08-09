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

int calc(string s)
{
	int c = 0;
	for(int i = 0; i + 6 < s.size(); i ++)
	{
		if(s[i] != 'n') continue;
		if(s.substr(i, 7) == "nanjing") c ++;
	}
	return c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		k = min(6, k);
		string s; cin >>s;
		if(s.size() < 7)
		{
			cout <<0 <<endl;
			continue;
		}
		//cout <<calc(s) <<endl;
		int ans = 0;
		for(int i = 0; i <= k; i ++)
		{
			string t = s.substr(i) + s.substr(0, i);
			//cout <<t <<endl;
			ans = max(ans, calc(t));
		}
		cout <<ans <<endl;	
	}
	return 0;
}
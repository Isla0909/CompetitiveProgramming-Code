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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
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

bool check(string s)
{
	int c0 = 0;
	for(int i = 0; s[i]; i ++)
		c0 += (s[i] == '0');
	return c0 != s.size() - c0;
} 

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	string s; cin >>s;
	if(check(s)) cout <<-1 <<endl;
	else
	{
		int c0 = 0, c1 = 0; int idx = 1;
		vector<pii> v;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '0' && !c0)
			{
				c1 ++;
				v.emplace_back(idx, 1);
			}
			else if(s[i] == '0' && c0)
			{
				c0 --;
				idx ++;
			}
			else if(s[i] == '1' && !c1)
			{
				c0 ++;
				v.emplace_back(idx, 2);
			}
			else if(s[i] == '1' && c1)
			{
				c1 --;
				idx ++;
			}
		}
		cout <<v.size() <<endl;
		for(auto [x, y] : v)
			cout <<x <<" " <<y <<endl;
	}
	return 0;
}
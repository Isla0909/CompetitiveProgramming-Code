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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<char, int> pci;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

map <char, int> mp;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	mp['N'] = 1, mp['S'] = 2, mp['W'] = 3, mp['E'] = 4;

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<pci> v; char s; int now = -1;
		for(int i = 0; i < n; i ++)
		{
			char c; int d; cin >>c >>d;
			if(now == -1)
			{
				s = c;
				now = mp[c];
				v.emplace_back('Z', d);
			}
			else
			{
				if(now == 1)
				{
					if(c == 'W') v.emplace_back('L', -1);
					else v.emplace_back('R', -1);
				}
				else if(now == 2)
				{
					if(c == 'E') v.emplace_back('L', -1);
					else v.emplace_back('R', -1);
				}
				else if(now == 3)
				{
					if(c == 'S') v.emplace_back('L', -1);
					else v.emplace_back('R', -1);
				}
				else
				{
					if(c == 'N') v.emplace_back('L', -1);
					else v.emplace_back('R', -1);
				}
				now = mp[c];
				v.emplace_back('Z', d);
			}
		}
		cout <<v.size() <<" " <<s <<" " <<endl;
		for(auto x : v)
		{
			if(x.se == -1) cout <<x.ff <<endl;
			else cout <<x.ff <<" " <<x.se <<endl;
		}
	}
	return 0;
}
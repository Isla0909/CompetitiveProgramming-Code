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

	int T; cin >>T;
	while(T --)
	{
		int x, y; cin >>x >>y;
		string s; cin >>s;

		int a = 0, b = 0;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == 'U') b ++;
			else if(s[i] == 'D') b --;
			else if(s[i] == 'R') a ++;
			else a --;
		}
		if(a == x && b == y)
		{
			cout <<"Impossible" <<endl;
			continue;
		}

		if(!x && !y)
		{
			cout <<"Impossible" <<endl;
			continue;
		}

		auto check1 = [&](string s) -> bool
		{
			for(int i = 0; s[i]; i ++)
				if(s[i] != 'U' && s[i] != 'D') return false;
			
			//(0, 0) -> (0, b)

			if(x == 0 && y >= min(0, b) && y <= max(0, b)) return true;
			return false;
		};

		auto check2 = [&](string s) -> bool
		{
			for(int i = 0; s[i]; i ++)
				if(s[i] != 'L' && s[i] != 'R') return false;
			
			//(0, 0) -> (a, 0)

			if(y == 0 && x >= min(0, a) && x <= max(0, a)) return true;
			return false;
		};

		if(check1(s) || check2(s))
		{
			cout <<"Impossible" <<endl;
			continue;
		}


		auto check = [&]() -> bool
		{
			a = 0, b = 0;
			for(int i = 0; s[i]; i ++)
			{
				if(s[i] == 'U') b ++;
				else if(s[i] == 'D') b --;
				else if(s[i] == 'R') a ++;
				else a --;

				if(a == x && y == b) return true;
			}
			return false;
		};


		vector<int> c(4);
		for(int i = 0; s[i]; i ++)
		{
			c[0] += (s[i] == 'U');
			c[1] += (s[i] == 'D');
			c[2] += (s[i] == 'R');
			c[3] += (s[i] == 'L');
		}

		unordered_map<int, char> mp;
		mp[0] = 'U', mp[1] = 'D', mp[2] = 'R', mp[3] = 'L';

		vector<int> p(4);
		iota(p.begin(), p.end(), 0);
		do
		{
			string t = "";
			for(int i = 0; i < 4; i ++)
			{
				for(int j = 0; j < c[p[i]]; j ++)
					t.push_back(mp[p[i]]);
			}
			s = t;
			if(!check())
			{
				cout <<s <<endl;
				break;
			}
		}while(next_permutation(p.begin(), p.end()));

	}
	return 0;
}
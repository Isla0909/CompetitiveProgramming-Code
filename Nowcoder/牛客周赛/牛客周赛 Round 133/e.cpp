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

	int n, x1, y1, x2, y2; cin >>n >>x1 >>y1 >>x2 >>y2;
	vector<char> ans; bool f = 1;

	if(n == 1)
	{
		if(x1 != x2)
		{
			if(x1 == 1) cout <<"D" <<endl;
			else cout <<"U" <<endl;
		}
		else cout <<-1 <<endl;
		return 0;
	}

	if(x1 != x2 && y1 == y2)
	{
		if(y1 == 1)
		{
			int c = n - 1;
			while(c --) ans.push_back('R');
			ans.push_back((x1 == 1) ? 'D' : 'U');
			c = n - 1;
			while(c --) ans.push_back('L');
		}
		else if(y1 == n)
		{
			int c = n - 1;
			while(c --) ans.push_back('L');
			ans.push_back((x1 == 1) ? 'D' : 'U');
			c = n - 1;
			while(c --) ans.push_back('R');
		}
		else
		{
			f = 0;
			cout <<-1 <<endl;
		}
		if(f)
		{
			for(auto c : ans)
				cout <<c;
			cout <<endl;
		}
		return 0;
	}

	if(x1 == x2)
	{
		if(y1 == y2) f = 0;
		else if(abs(y1 - y2) % 2 == 0) f = 0;
		else
		{
			if(x1 == 1)
			{
				if(y1 < y2)
				{
					int c = y1 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('D');
					c = y1 - 1;
					while(c --) ans.push_back('R');
					int d = abs(y2 - y1);
					c = d / 2;
					while(c --)
					{
						ans.push_back('R');
						ans.push_back('U');
						ans.push_back('R');
						ans.push_back('D');
					}
					ans.push_back('R');
					c = n - y2;
					while(c --) ans.push_back('R');
					ans.push_back('U');
					c = n - y2;
					while(c --) ans.push_back('L');
				}
				else//x1 = x2 = 1, y1 > y2
				{
					int c = n - y1;
					while(c --) ans.push_back('R');
					ans.push_back('D');
					c = n - y1;
					while(c --) ans.push_back('L');
					int d = abs(y2 - y1);
					c = d / 2;
					while(c --)
					{
						ans.push_back('L');
						ans.push_back('U');
						ans.push_back('L');
						ans.push_back('D');
					}
					ans.push_back('L');
					c = y2 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('U');
					c = y2 - 1;
					while(c --) ans.push_back('R');
				}
			}
			else
			{
				if(y1 < y2)//x1 = x2 = 2, y1 < y2
				{
					int c = y1 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('U');
					c = y1 - 1;
					while(c --) ans.push_back('R');
					int d = abs(y2 - y1);
					c = d / 2;
					while(c --)
					{
						ans.push_back('R');
						ans.push_back('D');
						ans.push_back('R');
						ans.push_back('U');
					}
					ans.push_back('R');
					c = n - y2;
					while(c --) ans.push_back('R');
					ans.push_back('D');
					c = n - y2;
					while(c --) ans.push_back('L');
				}
				else//x1 = x2 = 2, y1 > y2
				{
					int c = n - y1;
					while(c --) ans.push_back('R');
					ans.push_back('U');
					c = n - y1;
					while(c --) ans.push_back('L');
					int d = abs(y2 - y1);
					c = d / 2;
					while(c --)
					{
						ans.push_back('L');
						ans.push_back('D');
						ans.push_back('L');
						ans.push_back('U');
					}
					ans.push_back('L');
					c = y2 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('D');
					c = y2 - 1;
					while(c --) ans.push_back('R');
				}
			}
		}
	}
	else
	{
		if(y1 == y2) f = 0;
		else if(abs(y1 - y2) & 1) f = 0;
		else
		{
			if(x1 == 1)//x1 = 1, x2 = 2, y1 < y2
			{
				if(y1 < y2)//x1 = 1, x2 = 2, y1 < y2
				{
					int c = y1 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('D');
					c = y1 - 1;
					while(c --) ans.push_back('R');
					int d = abs(y2 - y1) / 2;
					c = d - 1;
					while(c --)
					{
						ans.push_back('R');
						ans.push_back('U');
						ans.push_back('R');
						ans.push_back('D');
					}
					ans.push_back('R');
					ans.push_back('U');
					ans.push_back('R');
					c = n - y2;
					while(c --) ans.push_back('R');
					ans.push_back('D');
					c = n - y2;
					while(c --) ans.push_back('L');
				}
				else//x1 = 1, x2 = 2, y1 > y2
				{
					int c = n - y1;
					while(c --) ans.push_back('R');
					ans.push_back('D');
					c = n - y1;
					while(c --) ans.push_back('L');
					int d = abs(y2 - y1) / 2;
					c = d - 1;
					while(c --)
					{
						ans.push_back('L');
						ans.push_back('U');
						ans.push_back('L');
						ans.push_back('D');
					}
					ans.push_back('L');
					ans.push_back('U');
					ans.push_back('L');
					c = y2 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('D');
					c = y2 - 1;
					while(c --) ans.push_back('R');
				}
			}
			else
			{
				if(y1 < y2)//x1 = 2, x2 = 1, y1 < y2
				{
					int c = y1 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('U');
					c = y1 - 1;
					while(c --) ans.push_back('R');
					int d = abs(y2 - y1) / 2;
					c = d - 1;
					while(c --)
					{
						ans.push_back('R');
						ans.push_back('D');
						ans.push_back('R');
						ans.push_back('U');
					}
					ans.push_back('R');
					ans.push_back('D');
					ans.push_back('R');
					c = n - y2;
					while(c --) ans.push_back('R');
					c = n - y2;
					ans.push_back('U');
					while(c --) ans.push_back('L');
				}
				else//x1 = 2, x2 = 1, y1 > y2
				{
					int c = n - y1;
					while(c --) ans.push_back('R');
					ans.push_back('U');
					c = n - y1;
					while(c --) ans.push_back('L');
					int d = abs(y2 - y1) / 2;
					c = d - 1;
					while(c --)
					{
						ans.push_back('L');
						ans.push_back('D');
						ans.push_back('L');
						ans.push_back('U');
					}
					ans.push_back('L');
					ans.push_back('D');
					ans.push_back('L');
					c = y2 - 1;
					while(c --) ans.push_back('L');
					ans.push_back('U');
					c = y2 - 1;
					while(c --) ans.push_back('R');
				}
			}
		}
	}
	if(f)
	{
		for(auto c : ans)
			cout <<c;
		cout <<endl;
		int x = x1, y = y1;
		for(auto c : ans)
		{
			if(c == 'R') y ++;
			else if(c == 'L') y --;
			else if(c == 'U') x --;
			else x ++;
		}
		assert(x == x2 && y == y2);
	}
	else cout <<-1 <<endl;
	return 0;
}

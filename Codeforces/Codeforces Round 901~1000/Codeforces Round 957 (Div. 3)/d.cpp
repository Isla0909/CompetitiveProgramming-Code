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

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m, k; cin >>n >>m >>k;
		string s; cin >>s;
		s = 'L' + s;

		int x = 0; bool f = 1; int now = 0;
		while(x <= n)
		{
			if(x + m > n || !f) break;


			int j = x + m;
			while(j > x && s[j] != 'L') j --;

			if(j > x) x = j;
			else
			{
				j = x + m;
				while(j > x && s[j] != 'W') j --;
				if(j == x) f = 0;
				else
				{
					for(int i = j; now <= k; i ++)
					{
						now ++;
						if(s[i + 1] == 'L' || i == n)
						{
							x = i + 1;
							break;
						}
						else if(s[i + 1] == 'C')
						{
							f = 0;
							break;
						}
					}
					if(now > k) f = 0;
				}
			}
		}
		cout <<((f) ? "YES" : "NO") <<endl;
	}
	return 0;
}
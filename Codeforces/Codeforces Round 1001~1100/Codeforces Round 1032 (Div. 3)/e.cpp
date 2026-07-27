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
		string l, r; cin >>l >>r;
		int ans = 0; bool f = 1;


		auto check = [&](int x) -> bool
		{
			int a = stoi(l.substr(0, x + 1));
			int b = stoi(r.substr(0, x + 1));
			return b - a == 1;
		};

		for(int i = 0; l[i]; i ++)
		{
			if(!i)
			{
				int x = r[i] - l[i];
				if(x == 0) ans += 2;
				else if(x == 1) ans ++;
			}
			else
			{
				if(l[i - 1] != r[i - 1]) f = 0;
				if(f)
				{
					int x = r[i] - l[i];
					if(x == 0) ans += 2;
					else if(x == 1) ans ++;
				}
				if(r[i] - l[i] < 0)
				{
					bool up = check(i);
					if(up) ans ++;
				}
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
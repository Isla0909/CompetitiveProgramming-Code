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
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
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
		int n, x; cin >>n >>x;

		if(!x && n == 1)
		{
			cout <<-1 <<endl;
			continue;
		}

		vector<int> st(32, 0); int cnt = 0;
		for(int i = 31; i >= 0; i --)
		{
			if(x >> i & 1)
				st[i] = 1, cnt ++;
		}

		int s = 0;
		if(cnt <= n)
		{
			int pre = 0;
			for(int i = 31; i >= 1; i --)
			{
				if(st[i])
				{
					s += (1 << i);
					pre ++;
				}
			}
			int less = n - pre;
			if(x & 1)
			{
				if(less & 1) s += less;
				else
				{
					if(pre) s += less + 1;
					else s += 2 * 2 + less - 1;
				}
			}
			else
			{
				if(less & 1)
				{
					if(pre) s += less + 1;
					else s += 2 * 2 + less - 1;
				}
				else s += less;
			}
			cout <<s <<endl;
		}
		else cout <<x <<endl;
	}
	return 0;
}
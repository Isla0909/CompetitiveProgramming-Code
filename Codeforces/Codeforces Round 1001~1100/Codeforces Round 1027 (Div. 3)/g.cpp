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
#define int long long
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
		int n, k; cin >>n >>k;
		int x = k - n, cnt = 0;
		vector<int> a(n);
		for(auto &x : a) cin >>x;

		int sum = 0;
		for(int i = 0; i < n; i ++)
		{
			int x = a[i];
			if(x % 2 == 0)
			{
				int hhh = 0;
				for(int u = 31; u >= 1; u --)
				{
					if(x >> u & 1)
					{
						sum += pow(2, u) - 1;
						hhh ++;
					}
				}
				sum += hhh - 1;
			}
			else sum ++;
		}
		cout <<sum <<endl;
		if(sum < k) cout <<"NO" <<endl;
		else cout <<"YES" <<endl; 
	}
	return 0;
}
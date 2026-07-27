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
		int n; cin >>n;
		vector<int> cnt(30);
		vector<bool> st(n, true);
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < 30; j ++)
				if(i >> j & 1) cnt[j] ++;

			bool f = 0;
			for(int j = 0; j < 30; j ++)
				if(cnt[j] & 1)
				{
					f = 1;
					break;
				}
			if(!f) st[i] = false;
		}
		
		if(!st[n - 1]) cout <<"impossible" <<endl;
		else
		{
			for(int i = 0; i < n; i ++)
			{
				if(!st[i])
				{
					cout <<i + 1 <<" " <<i <<" ";
					i ++;
				}
				else cout <<i <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}
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
		int n; ll k; cin >>n >>k;
		ll mmax = 0;
		for(int i = 1, j = n; i <= n; i ++, j --)
			mmax += abs(j - i);
		if(k > mmax || (k - mmax) & 1) cout <<"No" <<endl;
		else
		{
			cout <<"Yes" <<endl;
			ll sum = k / 2; vector<int> p(n + 1);
			for(int i = 1; i <= n; i ++) p[i] = i;

			int j = n;
			for(int i = 1; sum > 0; i ++)
			{
				while(j > i && sum < (j - i)) j --;
				sum -= (j - i);
				p[i] = j, p[j] = i;
				j --;
			}
			tell1(p);

			// auto check = [&]() -> bool
			// {
			// 	vector<bool> st(n + 1);
			// 	for(int i = 1; i <= n; i ++)
			// 	{
			// 		if(!st[p[i]]) st[p[i]] = 1;
			// 		else return true;
			// 	}
			// 	return false;
			// };

			// ll ans = 0;
			// for(int i = 1; i <= n; i ++)
			// 	ans += abs(p[i] - i);
			// if(check())
			// {
			// 	cout <<"WA" <<endl;
			// 	cout <<n <<" " <<k <<endl;
			// }
			//cout <<ans <<endl;
		}

	}
	return 0;
}
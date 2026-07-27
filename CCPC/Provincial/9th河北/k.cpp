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

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<int> a(n);
	for(auto &x : a) cin >>x;

	string s; cin >>s;
	vector<int> l(n), r(n);
	l[0] = n - 1, r[n - 1] = 0;
	r[0] = 1, l[n - 1] = n - 2;
	for(int i = 1; i < n - 1; i ++)
		r[i] = i + 1, l[i] = i - 1;

	int idx = 0, f = 1;
	for(int i = 0; s[i]; i ++)
	{
		if(s[i] == 'S')
		{
			a[idx] --;
			if(!a[idx])
			{
				r[l[idx]] = r[idx];
				l[r[idx]] = l[idx];
			}
			if(f == 1) idx = r[r[idx]];
			else idx = l[l[idx]];
		}
		else if(s[i] == 'R')
		{
			a[idx] --;
			if(!a[idx])
			{
				r[l[idx]] = r[idx];
				l[r[idx]] = l[idx];
			}
			f = -f;
			if(f == 1) idx = r[idx];
			else idx = l[idx];
		}
		else if(s[i] == 'D')
		{
			a[idx] --;
			if(!a[idx])
			{
				r[l[idx]] = r[idx];
				l[r[idx]] = l[idx];
			}
			if(f == 1)
			{
				idx = r[idx];
				a[idx] += 2;
				idx = r[idx];
			}
			else
			{
				idx = l[idx];
				a[idx] += 2;
				idx = l[idx];
			} 
		}
		else
		{
			a[idx] --;
			if(!a[idx])
			{
				r[l[idx]] = r[idx];
				l[r[idx]] = l[idx];
			}
			if(f == 1) idx = r[idx];
			else idx = l[idx];
		}
		// cout <<i <<" " <<idx <<endl;
		// for(int i = 0; i < n; i ++)
		// cout <<a[i] <<" \n"[i == n - 1];
	}
	for(int i = 0; i < n; i ++)
		cout <<a[i] <<endl;
	return 0;
}
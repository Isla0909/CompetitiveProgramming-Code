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

bool check(vector<int> &a)
{
	for(int i = 0; i + 1 < a.size(); i ++)
		if(a[i + 1] < a[i]) return false;
	return true;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n), b(n);
		for(auto &x : a) cin >>x;
		for(auto &x : b) cin >>x;

		vector<pii> ans;
		while(!check(a))
		{
			for(int i = 0; i + 1 < n; i ++)
				if(a[i + 1] < a[i])
				{
					ans.push_back({1, i});
					swap(a[i], a[i + 1]);
				}
		}
		while(!check(b))
		{
			for(int i = 0; i + 1 < n; i ++)
				if(b[i + 1] < b[i])
				{
					ans.push_back({2, i});
					swap(b[i], b[i + 1]);
				}
		}
		for(int i = 0; i < n; i ++)
			if(a[i] > b[i])
				ans.push_back({3, i});

		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x.ff <<" " <<x.se + 1 <<endl;
	}
	return 0;
}
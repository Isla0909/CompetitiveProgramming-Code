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

	int n; cin >>n;
	vector<int> a(n);
	for(auto &x : a) cin >>x;

	if(is_sorted(a.begin(), a.end())) cout <<"Sorted" <<endl;
	else
	{
		bool f = 0;
		for(int i = 0; i < n - 1; i ++)
		{
			int idx = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
			if(idx == n)
			{
				if(a[n - 1] != a[i])
				{
					swap(a[n - 1], a[i]);
					if(is_sorted(a.begin(), a.end())) f = 1;
					break;
				}
			}
			else if(a[idx - 1] != a[i])
			{
				swap(a[i], a[idx - 1]);
				if(is_sorted(a.begin(), a.end())) f = 1;
				break;
			}
		}
		cout <<(f ? "Sorted" : "Failed") <<endl;
	}	

	return 0;
}
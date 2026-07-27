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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];
		
		int x = a[k];
		sort(a.begin() + 1, a.end());
		int s = 1; bool f = 1;
		while(1)
		{
			auto it = upper_bound(a.begin() + 1, a.end(), x);

			if(it == a.end()) break;
			if(*it - x > x - s + 1)
			{
				f = 0;
				break;
			}
			else
			{
				int delta = *it - x;
				x = *it;
				s += delta;
			} 
		}
		cout <<(f ? "YES" : "NO") <<endl;
	}
	return 0;
}
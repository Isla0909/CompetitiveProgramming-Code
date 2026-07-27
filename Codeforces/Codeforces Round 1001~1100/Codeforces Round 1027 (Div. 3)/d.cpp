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
		int n; cin >>n;
		vector<int> a(n), b(n);
		map<int, int> mp1, mp2;
		for(int i = 0; i < n; i ++)
		{
			cin >>a[i] >>b[i];
			mp1[a[i]] ++, mp2[b[i]] ++;
		}
		vector<int> aa = a, bb = b;
		if(n == 1)
		{
			cout <<1 <<endl;
			continue;
		}
		if(n == 2)
		{
			cout <<2 <<endl;
			continue;
		}

		sort(a.begin(), a.end()), sort(b.begin(), b.end());

		
		int ans = inf;
		for(int i = 0; i < n; i ++)
		{
			int x = a[0], y = b[0], p = a[n - 1], q = b[n - 1];
			if(aa[i] == a[0] && mp1[a[0]] == 1)
				x = a[1];
			if(aa[i] == a[n - 1] && mp1[a[n - 1]] == 1)
				p = a[n - 2];

			if(bb[i] == b[0] && mp2[b[0]] == 1)
				y = b[1];
			if(bb[i] == b[n - 1] && mp2[b[n - 1]] == 1)
				q = b[n - 2];
			//cout <<x <<" " <<y <<" " <<p <<" " <<q <<endl;

			if((p - x + 1) * (q - y + 1) != n - 1) ans = min(ans, (p - x + 1) * (q - y + 1));
			else ans = min(ans, min((p - x + 2) * (q - y + 1), (p - x + 1) * (q - y + 2)));
		}
		cout <<ans <<endl;
	}
	return 0;
}
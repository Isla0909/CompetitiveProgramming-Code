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
#define int long long
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
		int n; cin >>n;
		vector<int> a(n);
		for(auto &x : a) cin >>x;
		bool f = 0;
		sort(a.begin(), a.end());

		if(a[0] == a[1]) f = 1;
		else
		{
			vector<int> v;
			for(int i = 1; i < n; i ++)
				if(a[i] % a[0] == 0) v.push_back(a[i]);
			if(v.size() && v.size() == 1 && v[0] != a[0]) f = 0;
			else if(v.size())
			{
				//tell(v);
				int x = v[0];
				for(int i = 1; i < v.size(); i ++)
				{
					//cout <<x <<endl;
					x = __gcd(x, v[i]);
				}
				if(x == a[0]) f = 1;
			}
		}
		
		if(f) cout <<"Yes" <<endl;
		else cout <<"No" <<endl;
	}
	return 0;
}
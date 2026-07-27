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
		int n; cin >>n;
		vector<int> a(n), b(n - 1);
		for(int i = 0; i < n; i ++) cin >>a[i];

		for(int i = 0; i < n - 1; i ++)
			b[i] = __gcd(a[i], a[i + 1]);

		//tell(b);

		bool f = 1;
			bool first = 1;
			for(int i = 0; i < b.size() - 1; i ++)
			{
				if(b[i] > b[i + 1])
				{
					if(!first)
					{
						f = 0;
						break;
					}

					first = 0;

					if(!i || i + 1 == b.size() - 1) continue;
					bool h = 0;
					int x = __gcd(a[i - 1], a[i + 1]);
					if(x <= b[i + 1]) h = 1;

					x = __gcd(a[i], a[i + 2]);
					if(x >= b[i] && x <= b[i + 2]) h = 1;


					x = __gcd(b[i + 1], b[i + 3]);
					if(x >= b[i + 1]) h = 1;

					f = h;

					i ++;
				}
			}

		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}
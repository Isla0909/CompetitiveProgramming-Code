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

		vector<int> a(n + 1), b(n + 1), idx(n + 1);
		vector<bool> st(n + 1, 0);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			idx[a[i]] = i;
		}
		for(int i = 1; i <= n; i ++) cin >>b[i];

		bool f = 1; int cnt = 0;
		for(int i = 1; i <= n; i ++)
		{
			int x = b[i]; cnt += (a[i] == b[i]);
			if(b[idx[b[i]]] != a[i] || cnt >= 2)
			{
				f = 0;
				break;
			}
		}

		if(!f) cout <<-1 <<endl;
		else
		{
			vector<int> p(n + 1); int c = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(!st[i] && a[i] != b[i])
				{
					c ++;
					p[c] = a[i], p[n + 1 - c] = b[i];
					st[i] = st[idx[b[i]]] = 1;
					// cout <<i <<" " <<idx[b[i]] <<endl;
					// cout <<"a[i] is " <<a[i] <<endl;
				}
			}
			//cout <<"c is " <<c <<endl;
			//if(st[2]) cout <<"1223" <<endl;
			for(int i = 1; i <= n; i ++)
			{
				if(!st[i] && a[i] == b[i])
				{
					c ++;
					p[c] = a[i];
					//cout <<"hhh" <<a[i] <<endl;
				}
			}
			vector<pii> ans;
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] != p[i])
				{
					//cout <<i <<" " <<a[i] <<" " <<p[i] <<endl;
					int j = idx[p[i]];
					ans.push_back({i, j});

					swap(a[i], a[j]);
					swap(b[i], b[j]);
					swap(idx[a[i]], idx[a[j]]);
				}
			}
			cout <<ans.size() <<endl;
			for(auto x : ans)
				cout <<x.ff <<" " <<x.se <<endl;
		}
	}
	return 0;
}
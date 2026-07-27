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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector <int> p(n + 1), s(n + 1, 1);
		for(int i = 1; i <= n; i ++) p[i] = i;

		auto find = [&](auto&&self, int x) -> int
		{
			if(x != p[x]) p[x] = self(self, p[x]);
			return p[x];
		};

		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			if(i - x > 0)
			{
				int j = i - x;
				int a = find(find, i), b = find(find, j);
				if(a != b)
				{
					s[a] += s[b];
					p[b] = a;
				}
				//cout <<a <<" 1 " <<b <<endl;
			}
			if(i + x <= n)
			{
				int j = i + x;
				int a = find(find, i), b = find(find, j);
				if(a != b)
				{
					s[a] += s[b];
					p[b] = a;
				}
				//cout <<a <<" 2 " <<b <<endl;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(p[i] == i) cnt ++;
		cout <<cnt - 1 <<endl;
	}
	return 0;
}
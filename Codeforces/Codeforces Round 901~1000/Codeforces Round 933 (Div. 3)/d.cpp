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
		int n, m, x; cin >>n >>m >>x;
		vector <int> v[m + 1];
		v[0].push_back(x);
		for(int i = 1; i <= m; i ++)
		{
			int c; char op; cin >>c >>op;
			for(auto x : v[i - 1])
			{
				int a = (x + c) % n, b = (x - c + n) % n;
				if(op == '0') v[i].push_back(a);
				else if(op == '1') v[i].push_back(b);
				else v[i].push_back(a), v[i].push_back(b);
			}
			sort(v[i].begin(), v[i].end());
			v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		}
		for(int i = 0; i < v[m].size(); i ++)
		{
			if(!v[m][i]) v[m][i] = n;
		}
		sort(v[m].begin(), v[m].end());
		cout <<v[m].size() <<endl;
		for(auto x : v[m])
		{
			if(!x) cout <<n <<" ";
			else cout <<x <<" ";
		}
		cout <<endl;
	}
	return 0;
}
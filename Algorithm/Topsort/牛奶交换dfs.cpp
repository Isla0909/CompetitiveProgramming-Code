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
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	ll n, m; cin >>n >>m;
	ll sum = 0;
	string s; cin >>s;
	vector <int> a(n), din(n);
	for(int i = 0; i < n; i ++) cin >>a[i], sum += a[i];

	for(int i = 0; i < n; i ++)
	{
		if(s[i] == 'L') din[(i - 1 + n) % n] ++;
		else din[(i + 1 + n) % n] ++;
	}

	auto dfs = [&](auto self, int u) -> ll
	{
		if(din[u] > 1) return 0;
		return a[u] + self(self, s[u] == 'L' ? (u - 1 + n) % n : (u + 1 + n) % n);
	};

	ll add = 0;
	for(int i = 0; i < n; i ++)
		if(!din[i]) add += min((ll)m, dfs(dfs, i));
	cout <<sum - add <<endl;
	return 0;
}
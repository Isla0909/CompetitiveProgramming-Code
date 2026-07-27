#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e3 + 10, INF = 0x3f3f3f3f;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n; cin >>n;
	vector<int> a(n);
	for(auto &i : a) cin >>i;

	vector f(n, vector<int>(n, -1e18));
	auto solve = [&](auto &&self, int l, int r) -> int{
		if(l > r) return (ll)0;
		if(f[l][r] != -1e18) return f[l][r];
		f[l][r] = max(a[l] - self(self, l + 1, r), a[r] - self(self, l, r - 1));
		return f[l][r];
	};
	cout <<solve(solve, 0, n - 1) <<endl;
	return 0;
}
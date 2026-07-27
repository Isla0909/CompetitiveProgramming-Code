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
#define int long long
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

	int n, m; cin >>n >>m;
	vector <int> a(n), b(m);
	for(auto &x : a) cin >>x;
	for(auto &x : b) cin >>x;
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int s = 0; int idx = 0;
	for(int i = 0; i < min(n, m); i ++)
	{
		if(b[i] < 0)
		{
			idx = i;
			break;
		}
		int x = a[i] + b[i];
		if(x > 0) s += x;
		else
		{
			idx = i;
			break;
		}
		idx = i + 1;
	}
	for(int i = idx; i < n; i ++)
		if(a[i] > 0) s += a[i];
	cout <<s <<endl;
	return 0;
}
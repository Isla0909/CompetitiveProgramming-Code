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
int a[N * 2], b[N * 2];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void display(vector <int> &v)
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

		map <int, bool> mp;
		for(int i = 1; i <= 2 * n; i ++)
		{
			int x; cin >>x;
			b[i] = x;
			mp[x] = 1;
		}

		sort(b + 1, b + 1 + 2 * n);

		int x = b[2 * n] + b[2 * n - 1];

		for(int i = 1; i <= 2 * n - 2; i += 2)
			x += b[i + 1] - b[i];
		cout <<b[2 * n] <<" " <<x <<" " <<b[2 * n - 1] <<" ";
		for(int i = 1; i <= 2 * n - 2; i += 2)
			cout <<b[i] <<" " <<b[i + 1] <<" ";
		cout <<endl;
	}
	return 0;
}
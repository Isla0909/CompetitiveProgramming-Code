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

	int n; cin >>n;
	vector <int> v(n); bool f = 0;
	for(auto &x : v) cin >>x;
	for(int i = 1; i < n - 1; i ++)
		if(v[i] == v[i - 1] && v[i] == v[i + 1])
		{
			f = 1;
			//cout <<v[i] <<endl;
			break;
		}
	if(f) cout <<"Yes" <<endl;
	else cout <<"No" <<endl;
	return 0;
}
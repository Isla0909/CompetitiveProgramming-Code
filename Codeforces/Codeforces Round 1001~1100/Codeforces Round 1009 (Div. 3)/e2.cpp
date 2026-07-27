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

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n; cin >>n;

	int i[3] = {1, 2, 3};
	while(1)
	{
		cout <<"? " <<i[0] <<" " <<i[1] <<" " <<i[2] <<endl;

		int p; cin >>p;
		if(p == 0) break;

		int x = rng() % 3;
		i[x] = p;
	}
	cout <<"! " <<i[0] <<" " <<i[1] <<" " <<i[2] <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}
	return 0;
}
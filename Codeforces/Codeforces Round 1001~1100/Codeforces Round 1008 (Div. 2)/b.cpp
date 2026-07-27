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

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		if(k & 1)
		{
			for(int i = 1; i < n; i ++)
				cout <<n <<" ";
			cout <<n - 1 <<endl;
		}
		else
		{
			for(int i = 1; i <= n - 2; i ++)
				cout <<n - 1 <<" ";
			cout <<n <<" " <<n - 1 <<endl;
		}
	}
	return 0;
}
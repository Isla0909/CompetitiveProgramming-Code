#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

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
		int k; cin >>k;
		int n = 0; vector <int> v;
		while(k)
		{
			int j = 2;
			while(j * (j - 1) / 2 <= k) j ++;

			k -= (j - 1) * (j - 2) / 2;

			n += j - 1; v.push_back(j - 1);
		}
		cout <<n <<endl;

		int y = 1; int h = 1;
		for(int i = 0; i < v.size(); i ++)
		{
			int c = v[i];
			while(c --)
				cout <<y <<" " << h ++ <<endl;
			y ++;
		}
	}
	return 0;
}
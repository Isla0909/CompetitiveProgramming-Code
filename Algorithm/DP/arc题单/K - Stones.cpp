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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 300 + 10, INF = 0x3f3f3f3f;
int a[N];

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	for(int i = 0; i < n; i ++) cin >>a[i];

	//sort(a, a + n);

	vector <bool> f(k + 1);
	for(int i = 1; i <= k; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			int x = a[j];
			if(i - x < 0)
			{
				f[i] = 0;
				continue;
			}
			if(f[i - x] == 0)
			{
				f[i] = 1;
				break;
			}
		}
	}
	if(f[k]) cout <<"First" <<endl;
	else cout <<"Second" <<endl;
	return 0;
}
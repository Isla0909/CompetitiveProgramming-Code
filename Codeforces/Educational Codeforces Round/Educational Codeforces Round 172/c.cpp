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
int a[N];

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
		string s; cin >>s;

		int c1 = 0, c0 = 0;
		for(int i = n - 1; i >= 0; i --)
		{
			a[i] = c1 - c0;
			//cout <<a[i] <<" ";
			if(s[i] == '1') c1 ++;
			else c0 ++;
		}

		// for(int i = 0; i < n; i ++)
		// 	cout <<a[i] <<" \n"[i == n - 1];

		sort(a, a + n - 1, greater<int>());

		// for(int i = 0; i < n; i ++)
		// 	cout <<a[i] <<" \n"[i == n - 1];

		int sum = 0, cnt = 0;
		bool f = 0;
		for(int i = 0; i < n; i ++)
		{
			sum += a[i]; cnt ++;
			if(sum >= k)
			{
				f = 1;
				break;
			}
		}
		if(f) cout <<cnt + 1 <<endl;
		else cout <<-1 <<endl;
	}
	return 0;
}
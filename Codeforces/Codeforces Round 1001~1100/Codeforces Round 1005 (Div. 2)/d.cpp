#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int a[N];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		for(int i = 0; i < n; i ++) cin >>a[i];

		vector <array<int, 30>> left(n);
		vector <array<int, 30>> pre(n);

		for(int i = 0; i < n; i ++)
		{
			if(i) left[i] = left[i - 1], pre[i] = pre[i - 1];
			else left[i].fill(-1);

			int bit_size = __lg(a[i]);
			for(int j = 0; j <= bit_size; j ++)
			{
				left[i][j] = i;
				pre[i][j] = 0;
			}
			for(int j = bit_size + 1; j < 30; j ++)
				pre[i][j] ^= a[i];
		}
		while(m --)
		{
			int x; cin >>x;
			int j = n - 1;
			while(x > 0 && j >= 0)
			{
				int bit_size = __lg(x);
				int k = left[j][bit_size];
				x ^= pre[j][bit_size];
				j = k;

				if(j == -1 || x < a[j]) break;

				x ^= a[j];
				j --;
			}
			cout <<n - 1 - j <<" ";
		}
		cout <<endl;
	}
	return 0;
}
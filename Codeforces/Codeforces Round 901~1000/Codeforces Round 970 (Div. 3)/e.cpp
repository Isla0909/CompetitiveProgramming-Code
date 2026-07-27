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
		int n; string s; cin >>n >>s;
		if(n & 1)
		{
			vector <vector<int>> even(n + 1, vector <int> (26, 0));
			vector <vector<int>> odd(n + 1, vector <int> (26, 0));
			vector <vector<int>> se(n + 1, vector <int> (26, 0));
			vector <vector<int>> so(n + 1, vector <int> (26, 0));
			
			for(int i = 0; s[i]; i ++)
			{
				int x = s[i] - 'a';
				if(i % 2 == 0) odd[i + 1][x] ++;
				else even[i + 1][x] ++;
			}
			for(int j = 0; j < 26; j ++)
			{
				for(int i = 0; s[i]; i ++)
				{
					se[i + 1][j] = se[i][j] + even[i + 1][j];
					so[i + 1][j] = so[i][j] + odd[i + 1][j];
				} 
			}
			int ans = INF;
			for(int i = 0; s[i]; i ++)
			{
				int m1 = -1, m2 = -1;
				for(int j = 0; j < 26; j ++)
				{
					m1 = max(m1, so[i][j] + se[n][j] - se[i + 1][j]);
					m2 = max(m2, se[i][j] + so[n][j] - so[i + 1][j]);
				}
				ans = min(ans, n - m1 - m2);
			}
			cout <<ans <<endl;
		}
		else
		{
			int cnt[2][26] = {0};
			for(int i = 0; i < n; i ++)
			{
				int x = s[i] - 'a';
				cnt[(i + 1) % 2][x] ++;
			}
			int m1 = -1, m2 = -1;
			for(auto x : cnt[0])
			{
				m2 = max(x, m2);
			}
			for(auto x : cnt[1])
			{
				m1 = max(x, m1);
			}
			cout <<n - m1 - m2 <<endl;
		}
	}
	return 0;
}
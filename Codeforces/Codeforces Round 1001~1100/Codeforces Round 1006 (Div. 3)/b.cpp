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
		int n; cin >>n;
		string s; cin >>s;

		int s1 = 0, s2 = 0;
		for(int i = 0; s[i]; i ++)
		{
			char x = s[i];
			if(x == '-') s1 ++;
			else s2 ++;
		}
		if(s1 < 2 || s2 == 0) cout <<0 <<endl;
		else cout <<s1 * s1 / 4 * s2 <<endl;
	}
	return 0;
}
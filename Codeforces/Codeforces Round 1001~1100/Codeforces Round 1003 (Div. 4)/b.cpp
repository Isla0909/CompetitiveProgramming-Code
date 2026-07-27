#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		bool f = 0;
		for(int i = 0; i < s.size() - 1; i ++)
		{
			if(s[i] == s[i + 1])
			{
				f = 1;
				break;
			}
		}
		if(f) cout <<1 <<endl;
		else cout <<s.size() <<endl;
	}
	return 0;
}
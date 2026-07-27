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

const int N = 2e5 + 10, INF = 0x3f3f3f3f, up = 2e5;

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;

		int a[n + 1];
		for(int i = 1; i <= n; i ++) cin >>a[i];

		set <int> s;
		for(int i = 0; i <= n; i ++) s.insert(i);

		int cnt = 0;
		for(int i = n; i; i --)
		{

			if(a[i] < *s.begin())
			{
				s.insert(0);
				cnt --;
			}
			s.erase(a[i]);
			cnt ++;
		}
		cout <<cnt <<endl;
	}
	return 0;
}
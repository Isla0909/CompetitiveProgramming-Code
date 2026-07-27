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
		int n; cin >>n;
		int a = 0, b = 0, c = 0;
		for(int i = 0; i < n; i ++)
		{
			string s; cin >>s;
			if(s == "Au") a ++;
			if(s == "Ag") b ++;
			if(s == "Cu") c ++;
		}
		cout <<a + min(b, c) <<endl;
	}
	return 0;
}
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
#include <ctime>
#include <random>
#include <chrono>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int a[N];
int n; 

void insert(int idx, int x)
{
	for(int i = n + 1; i > idx + 1; i --)
		a[i] = a[i - 1];
	a[idx + 1] = x;
	n ++;
}

void solve()
{
	cin >>n;
	string s; cin >>s;

	if(count(s.begin(), s.end(), s[0]) == n)
	{
		cout <<-1 <<endl;
		return ;
	}

	vector<int> cnt(3, 0);
	for(int i = 1; i <= n; i ++)
	{
		char x = s[i - 1];
		if(x == 'L') a[i] = 0;
		else if(x == 'I') a[i] = 1;
		else a[i] = 2;

		cnt[a[i]] ++;
	}

	vector<int> ans;
	while(cnt[0] != cnt[1] || cnt[1] != cnt[2] || cnt[0] != cnt[2])
	{
		int idx[3] = {INF, INF, INF};
		
		for(int i = 1; i < n; i ++)
			if(a[i] != a[i + 1])
				idx[3 - a[i] - a[i + 1]] = i;

		vector<pii> v;
		for(int i = 0; i <= 2; i ++)
			v.emplace_back(cnt[i], i);
		sort(v.begin(), v.end());

		for(int i = 0; i <= 2; i ++)
		{
			int j = v[i].se;
			if(idx[j] != INF)
			{
				insert(idx[j], j);
				ans.push_back(idx[j]);
				cnt[j] ++;
				break;
			}
		}
	}
	cout <<ans.size() <<endl;
	for(auto x : ans)
		cout <<x <<endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}
	return 0;
}
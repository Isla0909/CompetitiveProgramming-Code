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
#include <functional>
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> pos(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			pos[x] = i;
		}

		if(n == 1)
		{
			cout <<1 <<endl;
			continue;
		}

		int l = min(pos[n], pos[n - 1]), r = max(pos[n], pos[n - 1]);
		int ans = r - l + 1, cnt = 0; 
		for(int i = n - 2; i >= 1; i --)
		{
			if(pos[i] > l && pos[i] < r)
			{
				cnt ++;
				continue;
			}

			if(pos[i] < l)
			{
				l = pos[i];
				cnt ++;
				ans = max(ans, r - l + 1 - cnt);
			}
			if(pos[i] > r)
			{
				r = pos[i];
				cnt ++;
				ans = max(ans, r - l + 1 - cnt);
			}
			//cout <<"l and r " <<l <<" " <<r <<" " <<ans <<" " <<cnt <<endl;
		}
		cout <<ans <<endl;
	}
	return 0;
}
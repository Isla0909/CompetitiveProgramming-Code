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
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<vector<int>> ver(n + 1);
		int s = 1, c = 1;
		for(int i = 1; i <= n; i ++)
		{
			cout <<"? " <<i <<" " <<n <<" ";
			for(int j = 1; j <= n; j ++)
				cout <<j <<" ";
			cout <<endl;

			int x; cin >>x;
			ver[x].push_back(i);
			if(x > s)
			{
				s = x;
				c = i;
			}
		}
		vector<int> ans;
		ans.push_back(c);

		for(int d = s - 1; d >= 1; d --)
		{
			for(auto v : ver[d])
			{
				cout <<"? " <<c <<" " <<2 <<" " <<c <<" " <<v <<endl;
				int x; cin >>x;
				if(x == 2)
				{
					c = v;
					ans.push_back(v);
					break;
				}
			}
		}
		cout <<"! " <<ans.size() <<" ";
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
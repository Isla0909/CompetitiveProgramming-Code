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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> v;

		for(int i = 1; i <= n / i; i ++)
		{
			if(n % i == 0)
			{
				v.push_back(i);
				v.push_back(n / i);
			}
		}

		sort(v.begin(), v.end());

		// for(auto x : v)
		// 	cout <<x <<" ";
		// cout <<endl;

		int ans = 0;
		for(int i = 1; i < v.size(); i ++)
			ans += (v[i] - v[i - 1]) * (n / v[i - 1]);
		cout <<ans + 1 <<endl;
	}
	return 0;
}
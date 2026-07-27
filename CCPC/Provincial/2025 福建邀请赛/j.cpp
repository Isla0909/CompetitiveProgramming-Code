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
#define int long long
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

int lowbit(int x)
{
	return x & -x;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		ll n; cin >>n;
		vector<ll> ans;
		
		int x = sqrt(n);
		if(1LL * x * x == n)
		{
			cout <<0 <<endl;
			cout <<endl;
			continue;
		}
		
		while(1)
		{
			int x = __lg(n);
			if((1LL << x) == n)
			{
				if(x & 1) ans.push_back(n);
				break;
			}
			int c = lowbit(n);
			n += c;
			ans.push_back(c);
		}
		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
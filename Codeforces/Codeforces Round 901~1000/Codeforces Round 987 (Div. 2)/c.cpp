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
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e6, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[27] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		if(n < 27 && n & 1) cout <<-1 <<endl;
		else if(n & 1)
		{
			for(auto x : a)
				cout <<x <<" ";
			n -= 27;
			for(int x = 100, i = 0; i < n / 2; i ++, x ++)
				cout <<x <<" " <<x <<" ";
			cout <<endl;
		}
		else
		{
			for(int i = 0; i < n / 2; i ++)
			{
				int x = (rng() + rng()) % N;
				cout <<x <<" " <<x <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}
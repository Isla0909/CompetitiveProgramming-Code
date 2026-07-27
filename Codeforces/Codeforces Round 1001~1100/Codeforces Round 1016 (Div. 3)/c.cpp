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

bool is_prime(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i <= n / i; i ++)
		if(n % i == 0) return 0;
	return 1; 
}


signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int x, k; cin >>x >>k;
		
		if(x == 1)
		{
			int sum = 0;
			while(k --)
			{
				sum += x;
				x *= 10;
			}
			if(is_prime(sum)) cout <<"YES" <<endl;
			else cout <<"NO" <<endl;
		}
		else if(k == 1)
		{
			if(is_prime(x)) cout <<"YES" <<endl;
			else cout <<"NO" <<endl;
		}
		else cout <<"NO" <<endl;
	}
	return 0;
}
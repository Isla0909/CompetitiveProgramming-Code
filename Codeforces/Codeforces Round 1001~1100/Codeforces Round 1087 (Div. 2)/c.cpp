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
#include <array>
#define ff first
#define se second
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int query(int a, int b)
{
	cout <<"? " <<a <<" " <<b <<endl;
	int x; cin >>x;
	return x;
}

void answer(int x)
{
	cout <<"! " <<x <<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		bool f = 0;
		for(int i = 2 * n; i > 2; i -= 2)
		{
			if(query(i, i - 1))
			{
				f = 1;
				answer(i);
				break;
			}
		}
		if(!f)
		{
			if(!query(1, 3) && !query(1, 4)) answer(2);	
			else answer(1);
		}
	}
	return 0;
}

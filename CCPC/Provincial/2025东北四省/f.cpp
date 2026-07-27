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

double calc(double a, double b, double c, double d)
{
	return min(abs(c - a), 360 - abs(c - a)) + min(abs(d - b), 360 - abs(d - b));
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int a, b, c, d, e, f; cin >>a >>b >>c >>d >>e >>f;
		double ans = 1e18; int x = -1, y = -1;
		for(int i = 0; i < 12; i ++)
		{
			for(int j = 0; j <= 59; j ++)
			{
				if(i >= c and i <= e)
				{

					if(i == c and j < d) continue;
					if(i == e and j > f) continue;


					double du1 = i * 30 + j * 0.5;
					double du2 = j * 6;
					double dx = a * 30 + b * 0.5;
					double dy = b * 6;
					double res = calc(dx, dy, du1, du2);
					
					// if(i == 0)
					// {
					 	//cout <<i <<" " <<j <<" " <<res <<endl;
					 	//cout <<du1 <<" " <<du2 <<" " <<dx <<" " <<dy <<endl;
					// }

					if(res < ans)
					{
						ans = res;
						x = i, y = j;
					}
				}
			}
		}
		cout <<x <<" " <<y <<endl;	
	}
	return 0;
}
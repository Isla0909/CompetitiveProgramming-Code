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
#define endl '\n'
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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x0, y0;
    int d = exgcd(b, a % b, x0, y0);
    x = y0, y = x0 - a / b * y0;
    return d;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int x, y; cin >>x >>y;
		vector<int> a(n + 1), pos(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pos[a[i]] = i;
		}

		bool f = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == i) continue;
			int dis = abs(a[i] - i);
			int d = __gcd(x, y);
			// cout <<i <<" " <<dis <<" " <<d <<endl;
			if(dis % x == 0 || dis % y == 0) continue;
			if(dis % d)
			{
				f = 0;
				break;
			}
		}
		cout <<(f ? "Yes" : "No") <<endl;
	}
	return 0;
}

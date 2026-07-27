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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int a, b; cin >>a >>b;
		if(a >= b)
		{
			int p = a / (b + 1), q = a % (b + 1);
			for(int i = 1; i <= b + 1; i ++)
			{
				int n = p;
				if(i <= q) n ++;
				for(int j = 0; j < n; j ++)
					cout <<0;
				if(i != b + 1) cout <<1;
			}
		}
		else// a < b
		{
			int p = b / (a + 1), q = b % (a + 1);
			for(int i = 1; i <= a + 1; i ++)
			{
				int n = p;
				if(i <= q) n ++;
				for(int j = 0; j < n; j ++)
					cout <<1;
				if(i != a + 1) cout <<0;
			}
		}
		cout <<endl;
	}
	return 0;
}

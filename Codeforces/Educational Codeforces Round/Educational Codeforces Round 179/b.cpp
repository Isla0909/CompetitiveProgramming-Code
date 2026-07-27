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

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
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
		int n, m; cin >>n >>m;
		vector<int> f(n + 1);
		f[1] = 1, f[2] = 2;
		for(int i = 3; i <= n; i ++)
			f[i] = f[i - 1] + f[i - 2];
		int a = f[n], b = f[n - 1];
		string s = "";
		while(m --)
		{
			int v[3];
			for(int i = 0; i < 3; i ++)
				cin >>v[i];
			sort(v, v + 3);
			if(v[2] >= a + b && min(v[0], v[1]) >= a) s.push_back('1');
			else s += '0';
		}
		cout <<s <<endl;
	}
	return 0;
}
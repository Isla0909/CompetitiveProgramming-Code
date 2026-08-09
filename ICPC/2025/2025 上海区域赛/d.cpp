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

constexpr int N = 44000000, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int a[N], s[N];
int p[20];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	p[0] = 1;
	for(int i = 1; i <= 16; i ++)
		p[i] = p[i - 1] * 3;

	memset(s, -1, sizeof s);

	int n; cin >>n;	
	for(int i = 0; i < (1 << n); i ++)
	{
		cin >>a[i];
		int x = 0;
		for(int j = 0; j < n; j ++)
			if(i >> j & 1) x += p[j];
		s[x] = a[i];
	}

	int r = p[n];
	for(int i = 0; i < r; i ++)
	{
		if(s[i] != -1) continue;

		for(int j = 0; j < n; j ++)
		{
			if(i / p[j] % 3 == 2)
			{
				int x = i;
				x -= p[j];
				s[i] = s[x];
				x -= p[j];
				s[i] += s[x];
				break;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < r; i ++)
		ans ^= s[i];
	cout <<ans <<endl;
	return 0;
}
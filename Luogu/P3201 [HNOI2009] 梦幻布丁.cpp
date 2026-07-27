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

constexpr int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m;
int h[M], val[N], nex[N]; int idx;
int col[N], siz[M], p[M];
int ans;

void add(int a, int b)
{
	nex[idx] = h[a], val[idx] = b, h[a] = idx ++;
	siz[a] ++;
}

void merge(int &x, int &y)
{
	if(x == y) return ;
	if(siz[x] > siz[y]) swap(x, y);
	
	for(int i = h[x]; ~ i; i = nex[i])
	{
		int j = val[i];
		ans -= (col[j - 1] == y) + (col[j + 1] == y);
	}
	for(int i = h[x]; ~ i; i = nex[i])
	{
		int j = val[i];
		col[j] = y;
		if(nex[i] == -1)
		{
			nex[i] = h[y], h[y] = h[x];
			break;
		}
	}
	h[x] = -1;
	siz[y] += siz[x], siz[x] = 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(h, -1, sizeof h);

	cin >>n >>m;
	for(int i = 1; i <= n; i ++) 
	{
		cin >>col[i];
		ans += (col[i] != col[i - 1]);
		add(col[i], i);
	}

	for(int i = 0; i < M; i ++) p[i] = i;

	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int x, y; cin >>x >>y;
			merge(p[x], p[y]);
		}
		else cout <<ans <<endl;
	}

	return 0;
}

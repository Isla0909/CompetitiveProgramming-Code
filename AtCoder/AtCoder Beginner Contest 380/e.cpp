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

constexpr int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

int p[N], siz[N], L[N], R[N], col[N], cnt[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int merge(int a, int b)
{
	a = find(a), b = find(b);
	if(a == b) return a;

	if(siz[a] < siz[b]) swap(a, b);

	siz[a] += siz[b];
	p[b] = a;

	L[a] = min(L[a], L[b]);
	R[a] = max(R[a], R[b]);
	return a;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >>n >>q;
	for(int i = 1; i <= n; i ++)
	{
		p[i] = L[i] =  R[i] = i;
		siz[i] = cnt[i] = 1;
		col[i] = i;
	}
	
	while(q --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int x, c; cin >>x >>c;

			int root = find(x);;
			int old = col[root];

			//if(old == c) continue;

			cnt[old] -= siz[root];
			cnt[c] += siz[root];

			if(L[root] != 1)
			{
				int a = find(L[root] - 1);
				if(col[a] == c) root = merge(root, a);
			}
			if(R[root] != n)
			{
				int b = find(R[root] + 1);
				if(col[b] == c) root = merge(root, b);
			}

			root = find(root);
			col[root] = c;
		}
		else
		{
			int c; cin >>c;
			cout <<cnt[c] <<endl;
		}
	}
	return 0;
}

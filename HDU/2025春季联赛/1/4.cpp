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
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m; 
int h[N], st[N], s[N];

struct node
{
	int l, r;
	int pre, mid, last;
	int v;
}tree[N << 2];

void pushup(node &u, node &l, node & r)
{
	u.mid = max(l.last + r.pre, max(l.mid, r.mid));
	if(l.pre == l.r - l.l + 1) u.pre = l.pre + r.pre;
	else u.pre = l.pre;
	if(r.last == r.r - r.l + 1) u.last = r.last + l.last;
	else u.last = r.last;

	u.v = max(u.pre, max(u.mid, u.last)); 
}

void pushup(int u)
{
	pushup(tree[u], tree[u << 1], tree[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	tree[u] = {l, r};
	if(l == r)
	{
		tree[u].v = tree[u].pre = tree[u].mid = tree[u].last = st[l];
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

node query(int u, int l, int r)
{
	if(tree[u].l >= l && tree[u].r <= r) return tree[u];

	int mid = tree[u].l + tree[u].r >> 1;
	if(r <= mid) return query(u << 1, l, r);
	else if(l > mid) return query(u << 1 | 1, l, r);
	else
	{
		auto left = query(u << 1, l, r);
		auto right = query(u << 1 | 1, l, r);
		node res;
		pushup(res, left, right);
		return res;
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		cin >>n >>m;
		for(int i = 1; i <= n; i ++) cin >>h[i];

		memset(st, 0, sizeof st), memset(s, 0, sizeof s);
		// if(n >= 2)
		// {
		// 	if(h[1] != h[2]) st[1] = 1;
		// 	if(h[n] != h[n - 1]) st[n] = 1;
		// }
		for(int i = 2; i < n; i ++)
		{
			bool f = 0;
			if(h[i] < h[i - 1] && h[i] < h[i + 1]) f = 1;
			if(h[i] > h[i - 1] && h[i] > h[i + 1]) f = 1;

			st[i] = (f) ? 1 : 0;
		}
		for(int i = 1; i <= n; i ++)
			cout <<st[i] <<" \n"[i == n];

		for(int i = 1; i <= n; i ++)
			s[i] = s[i - 1] + st[i];

		build(1, 1, n);
		ll ans = 0;
		for(int i = 1; i <= m; i ++)
		{
			int a, b; cin >>a >>b;
			auto res = query(1, a, b);
			
			int l = res.v; 
			cout <<l <<" ";
			if(a - b == 0) ans += 0, cout <<0 <<endl;
			else if(l == 0)
			{
				set <int> s; bool f = 0;
				for(int j = a; j <= b; j ++)
				{
					s.insert(h[j]);
					if(s.size() >= 2)
					{
						f = 1;
						break;
					}
				}
				if(f) ans += 2 * i, cout <<2 <<endl;
				else cout <<0 <<endl;
			}
			else if(l == b - a + 1) ans += i * l, cout <<l <<endl;
			else if(l == b - a) ans += i * (l + 1), cout <<l + 1<<endl;
			else ans += i * (l + 2), cout <<l + 2<<endl;
			ans %= mod;
		}
		cout <<ans <<endl;
		
	}
	return 0;
}
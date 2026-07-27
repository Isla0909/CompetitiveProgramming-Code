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
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct gate
{
	char op;
	int c;

	int add_new(int x)
	{
		return (op == '+') ? c : x * (c - 1);
	}

	friend bool operator== (gate a, gate b)
	{
		if(a.op == b.op)
		{
			if(a.op == '+') return true;
			else return a.c == b.c;
		}
		return false;
	}
	friend bool operator< (gate a, gate b)
	{
		if(a.op == b.op) return a.c < b.c;
		return b.op == 'x';
	}
};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector <gate[2]> v(n);
		for(int i = 0; i < n; i ++)
			cin >>v[i][0].op >>v[i][0].c >>v[i][1].op >>v[i][1].c;
		vector <int> f(n);
		f[n - 1] = v[n - 1][0] < v[n - 1][1];
		for(int i = n - 2; i >= 0; i --)
		{
			if(v[i][0] == v[i][1])
				f[i] = f[i + 1];
			else
				f[i] = v[i][0] < v[i][1];
		}
		int l = 1, r = 1;
		for(int i = 0; i < n; i ++)
		{
			int al = v[i][0].add_new(l);
			int ar = v[i][1].add_new(r);

			if(i + 1 < n)
			{
				if(f[i + 1] == 0) l += al + ar;
				else r += al + ar;
			}
			else l += al + ar;
		}
		cout <<l + r <<endl;
	}
	return 0;
}
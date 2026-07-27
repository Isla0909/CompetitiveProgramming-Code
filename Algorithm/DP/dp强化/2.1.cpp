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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, M = 4e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int h[N], val[M], nex[M], w[M]; int idx;
int d[N];
bool st[N];
bool del[N];

void add(int a, int b, int c)
{
	nex[idx] = h[a], val[idx] = b, w[idx] = c, h[a] = idx ++;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	memset(h, -1, sizeof h);

	int n, m; cin >>n >>m;
	int x; 
	while(m --)
	{
		cin >>x;
		st[x] = 1;
	}
	int sum = 0;
	for(int i = 1; i < n; i ++)
	{
		int a, b, c; cin >>a >>b >>c;
		add(a, b, c), add(b, a, c);
		d[a] ++, d[b] ++;
		sum += c;
	}
	//cout <<sum <<endl;
	queue <int> q;
	for(int i = 1; i <= n; i ++)
		if(d[i] == 1) q.push(i);
	while(q.size())
	{
		auto t = q.front();
		if(st[t]) q.pop();
		else
		{
			q.pop(); del[t] = 1;
			//cout <<"del" <<t <<endl;
			for(int i = h[t]; ~ i; i = nex[i])
			{
				int j = val[i], c = w[i];
				if(del[j]) continue;
			   	//cout <<"sub" <<c <<endl;
				d[j] --, sum -= c;
				if(d[j] == 1) q.push(j);
			}
		}
	}
	cout <<x <<endl;
	cout <<sum * 2 <<endl;
	return 0;
}
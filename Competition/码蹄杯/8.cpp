#include <bits/stdc++.h>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int x, vector<int> &v)
{
	for(int i = 0; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	vector<int> a(n), b(m), st(n);

	for(auto &x : a) cin >>x;
	for(auto &x : b) cin >>x;

	bool f1 = 0, f2 = 0;
	for(int i = 0, j = 0; i < n && j < m; i ++)
	{
		if(a[i] == b[j])
		{
			st[i] = 1;
			j ++;
		}
		if(j == m)
		{
			f1 = 1;
			break;
		}
	}
	for(int i = 0, j = 0; i < n && j < m; i ++)
	{
		if(!st[i] && a[i] == b[j]) j ++;
		if(j == m) 
		{
			f2 = 1;
			break;
		}
	}
	if(f1 && f2) cout <<"Yes" <<endl;
	else cout <<"No" <<endl;
	return 0;
}
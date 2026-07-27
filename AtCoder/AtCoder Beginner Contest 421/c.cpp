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

	int n; cin >>n; n *= 2;
	string s; cin >>s; s = ' ' + s;

	string t = " ";
	for(int i = 1; i <= n; i ++)
	{
		char c = (i & 1) ? 'A' : 'B';
		t.push_back(c);
	}	
	vector<queue<int>> v(3);
	string p = s;
	for(int i = 1; i <= n; i ++)
	{
		if(p[i] == t[i]) continue;
		
		if(p[i] == 'A') v[1].push(i);
		else v[2].push(i);
	}

	i64 ans1 = 0;
	while(v[1].size())
	{
		auto t1 = v[1].front(); v[1].pop();
		auto t2 = v[2].front(); v[2].pop();
		//cout <<t1 <<" " <<t2 <<endl;
		ans1 += abs(t1 - t2);
	}

	t = " ";
	for(int i = 1; i <= n; i ++)
	{
		char c = (i & 1) ? 'B' : 'A';
		t.push_back(c);
	}
	vector<queue<int>> vv(3);
	p = s;
	for(int i = 1; i <= n; i ++)
	{
		if(p[i] == t[i]) continue;
		
		if(p[i] == 'A') vv[1].push(i);
		else vv[2].push(i);
	}

	i64 ans2 = 0;
	while(vv[1].size())
	{
		auto t1 = vv[1].front(); vv[1].pop();
		auto t2 = vv[2].front(); vv[2].pop();
		ans2 += abs(t1 - t2);
	}	
	cout <<min(ans1, ans2) <<endl;
	return 0;
}
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

	int T; cin >>T;
	while(T --)
	{
		int sum1 = 0, sum2 = 0;
		int x = 0, y = 0;
		int n; cin >>n;
		string s; cin >>s;
		for(auto c : s)
		{
			if(c == 'N' || c == 'S')
			{
				sum1 ++;
				if(c == 'N') x ++;
				else x --;
			}
			else
			{
				sum2 ++;
				if(c == 'E') y ++;
				else y --;
			}
		}
		if(x & 1 || y & 1 || (n == 2 && x == 0 && y == 0)) cout <<"NO" <<endl;
		else
		{
			vector<bool> st(n);
			int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
			if(x > 0) s1 = x / 2;
			else s2 = -x / 2;
			if(y > 0) s3 = y / 2;
			else s4 = -y / 2;

			int n1 = 0, n2 = 0, n3 = 0,n4 = 0;
			for(int i = 0; i < n; i ++)
			{
				if(s[i] == 'N' && n1 < s1) st[i] = 1, n1 ++;
				if(s[i] == 'S' && n2 < s2) st[i] = 1, n2 ++;
				if(s[i] == 'E' && n3 < s3) st[i] = 1, n3 ++;
				if(s[i] == 'W' && n4 < s4) st[i] = 1, n4 ++;
			}
			if(x == 0 && y == 0)
			{
				if(sum1) st[s.find('N')] = 1, st[s.find('S')] = 1;
				else if(sum2) st[s.find('E')] = 1, st[s.find('W')] = 1;
			}
			for(int i = 0; i < n; i ++)
				cout <<(st[i] ?  'R' : 'H');
			cout <<endl;
		}
	}
	return 0;
}
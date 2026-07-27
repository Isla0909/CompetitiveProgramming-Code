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
		int n, k; cin >>n >>k;
		string s; cin >>s;
		int cnt = 0;
		int l = 0, r = n + 1;
		for(auto c : s)
		{
			if(c == '0') l ++;
			else if(c == '1') r --;
			else cnt ++;
		}

		if(n - l - (n - r + 1) == cnt)
		{
			for(int i = 1; i <= n; i ++)
				cout <<'-';
			cout <<endl;
			continue;
		}

		vector<int> st(n + 1);
		for(int i = 1; i <= l; i ++) st[i] = -1;
		for(int i = n; i >= r; i --) st[i] = -1;
		for(int i = l + cnt + 1; i < r - cnt; i ++) st[i] = 1;

		for(int i = 1; i <= n; i ++)
		{
			if(st[i] == -1) cout <<'-';
			else if(st[i] == 1) cout <<'+';
			else cout <<'?';
		} 
		cout <<endl;
	}
	return 0;
}
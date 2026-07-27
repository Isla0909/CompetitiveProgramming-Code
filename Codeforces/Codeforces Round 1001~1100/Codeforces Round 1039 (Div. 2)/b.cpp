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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> p(n);
		for(auto &x : p) cin >>x;

		int l = 0, r = n - 1;
		vector<char> ans;
		int f = 1;
		while(l < r)
		{
			if(f)
			{
				if(p[l] > p[r]) ans.push_back('L'), ans.push_back('R');
				else ans.push_back('R'), ans.push_back('L');
			}
			else
			{
				if(p[l] < p[r]) ans.push_back('L'), ans.push_back('R');
				else ans.push_back('R'), ans.push_back('L');
			}
			f = 1 - f;
			l ++, r --;
			if(l == r)
			{
				ans.push_back('L');
				break;
			}
		}
		//cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x;
		cout <<endl;
	}
	return 0;
}
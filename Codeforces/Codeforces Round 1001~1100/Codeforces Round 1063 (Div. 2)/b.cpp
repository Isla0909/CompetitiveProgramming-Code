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
using f64 = long double;
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
		int n; cin >>n;
		vector<int> a(n + 1), pos(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			pos[a[i]] = i;
		}

		string s; cin >>s; s = ' ' + s;

		int c1 = pos[1], c2 = pos[n];
		if(s[c1] == '1' || s[c2] == '1')
		{
			cout <<-1 <<endl;
			continue;
		}

		if(s[1] != '1' && s[n] != '1')
		{
			vector<pii> ans;
			ans.emplace_back(c1, c2);
			ans.emplace_back(1, c1);
			ans.emplace_back(1, c2);
			ans.emplace_back(c1, n);
			ans.emplace_back(c2, n);
			cout <<5 <<endl;
			for(auto [x, y] : ans)
			{
				if(x <= y) cout <<x <<" " <<y <<endl;
				else cout <<y <<" " <<x <<endl;
			}
		}
		else cout <<-1 <<endl;
	}
	return 0;
}

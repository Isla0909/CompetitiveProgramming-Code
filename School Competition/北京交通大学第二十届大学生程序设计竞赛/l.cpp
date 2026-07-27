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
		int n, m; cin >>n >>m;
		unordered_map<string, bool> in;
		unordered_map<string, int> cnt;
		for(int i = 1; i <= n; i ++)
		{
			string s; cin >>s;
			in[s] = 1;
		}
		int M = 0;
		while(m --)
		{
			string s; cin >>s;
			if(in[s])
			{
				cnt[s] ++;
				M = max(M, cnt[s]);
			}
		}
		vector<string> ans;
		for(auto [name, c] : cnt)
			if(c == M)
				ans.push_back(name);
		if(ans.empty()) cout <<"HaHa,YiDuiQu." <<endl;
		else
		{
			sort(ans.begin(), ans.end(), greater<string>());
			for(auto x : ans)
				cout <<x <<endl;
		}
	}
	return 0;
}

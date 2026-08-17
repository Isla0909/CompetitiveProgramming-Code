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

	string s; cin >>s;
	int n = s.size();
	vector<int> nex(n + 1);
	s = " " + s;
	for(int i = 2, j = 0; i <= n; i ++)
	{
		while(j && s[i] != s[j + 1]) j = nex[j];

		if(s[i] == s[j + 1]) j ++;
		nex[i] = j;
	}

	vector<int> ans;
	for(int j = n; j; j = nex[j])
		ans.push_back(j);

	vector<int> cnt(n + 1, 1);
	for(int i = n; i >= 1; i --)
		cnt[nex[i]] += cnt[i];

	reverse(ans.begin(), ans.end());

	cout <<ans.size() <<endl;
	for(auto x : ans)
		cout <<x <<" " <<cnt[x] <<endl;
	return 0;
}

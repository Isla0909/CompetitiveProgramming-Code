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

	int n; cin >>n;

	auto kmp = [&](string &s, string &t, vector<int> &nex)
	{
		int n = s.size(), m = t.size();
		nex.assign(m + 1, 0);
		s = " " + s, t = " " + t;
		for(int i = 2, j = 0; i <= m; i ++)
		{
			while(j && t[i] != t[j + 1])
				j = nex[j];
			if(t[i] == t[j + 1]) j ++;
			nex[i] = j;
		}

		vector<int> pos;
		for(int i = 1, j = 0; i <= n; i ++)
		{
			while(j && s[i] != t[j + 1])
				j = nex[j];
			if(s[i] == t[j + 1]) j ++;
			if(j == m)
			{
				pos.push_back(i - m + 1);
				j = nex[j];
			}
		}
		return pos;
	};
	//注意 s 和 t 传入的时候是引用, 现在已经是 1-based

	string t; cin >>t;
	vector<string> ans;
	while(n --)
	{
		string s; cin >>s;
		string p = t;
		vector<int> nex;
		auto pos = kmp(s, p, nex);
			
		if(pos.empty()) continue;	
		s = s.substr(1);
		ans.push_back(s);
	}
	sort(ans.begin(), ans.end());
	for(auto x : ans)
		cout <<x <<endl;
	return 0;
}

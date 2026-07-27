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

	int n; cin >>n;
	
	unordered_map<string, int> mp; int idx = 1;
	vector<vector<int>> v(11);
	for(int i = 0; i < n; i ++)
	{
		string a, b; cin >>a >>b;
		if(!mp.count(a)) mp[a] = idx ++;
		if(!mp.count(b)) mp[b] = idx ++;
		
		int c1 = mp[a], c2 = mp[b];
		v[c1].push_back(c2);
	}

	auto check = [&](vector<int> &v)
	{
		//tell(0, v);
		for(int i = 0; i + 4 < v.size(); i ++)
		{
			set<int> s;
			for(int j = i; j <= i + 4; j ++)
				s.insert(v[j]);
			if(s.size() == 5)
			{
				return true;
			}
		}
		return false;
	};

	bool f = 0;
	for(auto [_, c] : mp)
	{
		if(check(v[c]))
		{
			f = 1;
			break;
		}
	}

	cout <<(f ? "PENTA KILL!" : "SAD:(") <<endl;
	return 0;
}

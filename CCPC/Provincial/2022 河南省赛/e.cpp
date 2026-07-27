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
		string s; cin >>s;
		vector<vector<int>> pos(26);
		for(int i = 0; i < s.size(); i ++)
		{
			int x = s[i] - 'a';
			pos[x].push_back(i);
		}

		auto check = [&](int i, int j, int k) -> bool
		{
			if(pos[i].size() < 5) return false;
			int x = pos[i][4];
			int it2 = upper_bound(pos[j].begin(), pos[j].end(), x) - pos[j].begin();
			if(it2 + 7 - 1 >= pos[j].size()) return false;
			x = pos[j][it2 + 6];
			int it3 = upper_bound(pos[k].begin(), pos[k].end(), x) - pos[k].begin();
			if(it3 + 5 - 1 >= pos[k].size()) return false;
			return true;
		};

		bool f = 0;
		for(int i = 0; i < 26 && !f; i ++)
			for(int j = 0; j < 26 && !f; j ++)
				for(int k = 0; k < 26 && !f; k ++)
					if(check(i, j, k))
					{
						f = 1;
						for(int u = 0; u < 5; u ++)
							cout <<char(i + 'a');
						for(int u = 0; u < 7; u ++)
							cout <<char(j + 'a');
						for(int u = 0; u < 5; u ++)
							cout <<char(k + 'a');
						cout <<endl;
						break;	
					}
		if(!f) cout <<"none" <<endl;
		return 0;
	}

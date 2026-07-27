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

int rand(int l, int r)//[l, r]
{
	return rng() % (r - l + 1) + l;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		auto b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		auto find = [&](int x) -> i32
		{
			return lower_bound(b.begin(), b.end(), x) - b.begin();
		};

		int c = b.size();
		vector<vector<int>> vec(c + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x = a[i];
			vec[find(x)].push_back(i);
		}

		auto calc = [&](int x, int l, int r) -> i32
		{
			x = find(x);
			int tot = upper_bound(vec[x].begin(), vec[x].end(), r) - vec[x].begin();// <= r
			int c = lower_bound(vec[x].begin(), vec[x].end(), l) - vec[x].begin();// < l
			return tot - c;
		};

		while(m --)
		{
			int l, r; cin >>l >>r;

			set<int> s; int len = r - l + 1;
			int cnt = 110;
			while(cnt --)
			{
				int idx = rand(l, r);
				if(calc(a[idx], l, r) > len / 3) s.insert(a[idx]);

				if(s.size() == 2) break;
			}
			
			if(!s.size()) cout <<-1 <<endl;
			else
			{
				for(auto x : s)
					cout <<x <<" ";
				cout <<endl;
			}
		}
	}
	return 0;
}
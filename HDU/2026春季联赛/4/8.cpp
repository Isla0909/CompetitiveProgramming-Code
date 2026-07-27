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
typedef pair<int, string> pis;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pis &a, const pis &b)
{
	return a.ff > b.ff;
}

string get(int x)
{
	string res = "";
	string s = to_string(x);
	int c = 4 - s.size();
	while(c --) res.push_back('0');
	return res + s;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<pis> v(n);
		for(int i = 0; i < n; i ++)
			cin >>v[i].se >>v[i].ff;

		auto check = [&](int x) -> bool
		{
			string s = get(x);
			for(int i = 0; i < v.size(); i ++)
			{
				int c = 0;
				for(int j = 0; j < 4; j ++)
					c += s[j] == v[i].se[j];
				if(c != v[i].ff) return false;
			}
			return true;
		};

		int ans = -1;
		for(int i = 0; i < 10000; i ++)
			if(check(i))
			{
				ans = i;
				break;
			}
		cout <<get(ans) <<endl;
	}
	return 0;
}

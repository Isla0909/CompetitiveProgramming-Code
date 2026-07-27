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
		string s; cin >>s;
		int n = s.size();
		string t1 = "", t2 = "";
		for(int i = 0; i < n; i ++)
		{
			if(i & 1)
			{
				t1.push_back('a');
				t2.push_back('b');
			}
			else
			{
				t1.push_back('b');
				t2.push_back('a');
			}
		}

		auto check = [&](string &s, string &p) -> bool
		{
			string a = s;
			int l = 0, r = n - 1; bool f = 0;
			for(int i = 0; i < n; i ++)
			{
				if(a[i] != p[i])
				{
					l = i;
					f = 1;
					break;
				}
			}
			for(int i = n - 1; i >= 0; i --)
			{
				if(a[i] != p[i])
				{
					r = i;
					f = 1;
					break;
				}
			}
			// cout <<l <<" " <<r <<endl;
			
			if(!f) return true;
			reverse(a.begin() + l, a.begin() + r + 1);
			if(a == p) return true;

			reverse(a.begin() + l, a.begin() + r + 1);
			for(int i = l; i <= r; i ++)
			{
				if(a[i] == 'a') a[i] = 'b';
				else a[i] = 'a';
			}
			// cout <<a <<endl;
			reverse(a.begin() + l, a.begin() + r + 1);
			if(a == p) return true;
			return false;
		};
		if(check(s, t1) || check(s, t2)) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}

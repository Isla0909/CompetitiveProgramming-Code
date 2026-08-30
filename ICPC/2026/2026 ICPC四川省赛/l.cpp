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
		int l = 0, r = s.size() - 1;
		string ans = "";
		while(l <= r)
		{
			if(s[l] != s[r] || l + 1 >= r)
			{
				if(s[l] < s[r])
				{
					ans.push_back(s[l]);
					l ++;
				}
				else
				{
					ans.push_back(s[r]);
					r --;
				}
				continue;
			}

			char c = s[l];
			int L = 1;
			while(l + L <= r && s[l + L] == c) L ++;

			int R = 1;
			while(r - R >= l && s[r - R] == c) R ++;

			int len = r - l + 1;
			if(L == len)
			{
				int cnt = len/ 2 +1;
				ans.append(cnt, c);
				break;
			}

			char lc = s[l + L], rc = s[r - R];
			int cnt;
			if(c < lc && c < rc)
			{
				cnt = L + R;
				l += L, r -= R;
			}
			else if(lc < c && rc < c)
			{
				cnt = min(L, R);
				l += cnt, r -= cnt;
			}
			else
			{
				if(lc < rc)
				{
					cnt = L;
					l += L;
				}
				else
				{
					cnt = R;
					r -= R;
				}
			}
			ans.append(cnt, c);
		}
		cout <<ans <<endl;
	}
	return 0;
}

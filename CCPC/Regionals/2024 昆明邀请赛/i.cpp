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
		int cnt = 0, n = s.size(); bool f = 0;
		auto check = [&](string s) -> bool
		{
			for(int i = 1; i < s.size(); i ++)
				if(s[i] != s[0]) return false;
			return true;
		};

		bool h = 0;
		int c1 = 1, c2 = 1;
		//if(s[0] == s[n - 1])
		{
			for(int i = 1; i < n; i ++)
			{
				if(s[i] == s[0]) c1 ++;
				else break;
			}
			for(int i = n - 2; i >= 0; i --)
			{
				if(s[i] == s[n - 1]) c2 ++;
				else break;
			}
			if(s[0] == s[n - 1] && (c1 + c2) % 2 == 0 && c1 & 1 && c2 & 1) h = 1;
		}

		for(int i = 0; i < n; i ++)
		{
			int j = i + 1;
			while(j < n && s[j] == s[i]) j ++;
			int len = j - i;
			//cout <<i <<" " <<j <<endl;
			if(len % 2 == 0)
			{
				if(h);
				else if(i == 0)
				{
					if(s[0] != s[n - 1]) f = 1;
					else if((c1 + c2) % 2 == 0) f = 1;
				}
				else if(j == n)
				{	
					if(s[0] != s[n - 1]) f = 1;
					else if((c1 + c2) % 2 == 0) f = 1;
				}
				else f = 1;
			}
			i = j - 1;
			cnt += len / 2;
		}
		// cout <<c1 <<" " <<c2 <<endl;
		// cout <<cnt <<" " <<h <<endl;
		if(check(s)) cout <<cnt <<endl;
		else if(h) cout <<cnt <<endl;
		else cout <<max(0, cnt - f) <<endl;
	}
	return 0;
}
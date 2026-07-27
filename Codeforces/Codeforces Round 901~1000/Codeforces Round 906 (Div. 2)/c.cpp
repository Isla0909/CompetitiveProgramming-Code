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

bool check(string s)
{
	for(int i = 0; i < s.size() / 2; i ++)
		if(s[i] == s[s.size() - 1 - i]) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s; s = ' ' + s;

		int c0 = 0, c1 = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(s[i] == '0') c0 ++;
			else c1 ++;
		}

		if(c0 != c1)
		{
			cout <<-1 <<endl;
			continue;
		}

		vector<int> ans;
		deque<char> q;
		for(int i = 1; i <= n; i ++)
			q.push_back(s[i]);

		int i = 0, j = n - 1;
		while(q.size())
		{
			auto l = q.front(), r = q.back();
			if(l != r)
			{
				q.pop_front();
				q.pop_back();
				i ++, j --;
			}
			else
			{
				if(l == '1')
				{
					q.push_front('1');
					q.pop_back();
					ans.push_back(i);
				}
				else
				{
					q.pop_front();
					q.push_back('0');
					ans.push_back(j + 1);
				}
				i ++, j ++;
			}
		}

		cout <<ans.size() <<endl;
		for(auto x : ans)
			cout <<x <<" ";
		cout <<endl;
	}
	return 0;
}
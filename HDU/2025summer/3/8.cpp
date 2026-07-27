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
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		string s; cin >>s;

		string p1 = "", p2 = "";
		for(int i = 0; i < n; i ++)
		{
			if(i & 1) p1.push_back('1'), p2.push_back('0');
			else p1.push_back('0'), p2.push_back('1');
		}

		auto calc = [&]() -> u32
		{
			vector<int> v1, v2;
			for(int i = 0; i < n; i ++)
			{
				if(s[i] != p1[i]) v1.push_back(i);
				if(s[i] != p2[i]) v2.push_back(i);
			}
			int cnt1 = 0, cnt2 = 0;
			for(int i = 1; i < v1.size(); i ++)
				if(v1[i - 1] + 1 == v1[i])
				{
					cnt1 += 2;
					i ++;
				}
			for(int i = 1; i < v2.size(); i ++)
				if(v2[i - 1] + 1 == v2[i])
				{
					cnt2 += 2;
					i ++;
				}
			int res1 = v1.size() - cnt1 + cnt1 / 2;
			int res2 = v2.size() - cnt2 + cnt2 / 2;
			return min(res1, res2);
		};

		int ans1 = calc();
		swap(s[0], s[n - 1]);
		int ans2 = 1 + calc();
		cout <<min(ans1, ans2) <<endl;
	}
	return 0;
}
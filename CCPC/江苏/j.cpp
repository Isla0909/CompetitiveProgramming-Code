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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int calc(string &a, string &b)
{
	int res = 0;
	for(int i = 0; i < a.size(); i ++)
	{
		for(int j = 0; j < b.size(); j ++)
		{
			if(b[j] == a[i])
			{
				int l = 0;
				for(int k = 0; i + k < a.size() && j + k < b.size(); k ++)
				{
					if(b[j + k] == a[i + k])
					{
						l ++;
						//cout <<i <<" " <<j <<" " <<k <<" " <<l <<endl;
						res = max(res, l);
					}
					else l = 0;
				}
				
				//cout <<j <<" " <<i <<endl;
			}
		}
	}
	return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<string> v(n);
		for(int i = 0; i < n; i ++)
			cin >>v[i];

		int ans = 0;
		for(int i = 0; i < n; i ++)
		{
			for(int j = i + 1; j < n; j ++)
			{
				string a = v[i], b = v[j];
				ans = max(ans, calc(a, b));
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
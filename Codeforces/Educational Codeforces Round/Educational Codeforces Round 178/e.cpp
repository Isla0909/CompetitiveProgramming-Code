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

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int cnt[N][26];//前i个字符字符j出现多少次
int pos[26][N];//字符i出现第j次的位置是哪里
int now[26];

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, k; cin >>n >>k;
	string s; cin >>s;
	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - 'a';

		if(!i) cnt[i][x] = 1;
		else cnt[i][x] = cnt[i - 1][x] + 1;

		now[x] ++;
		pos[x][now[x]] = i;

		if(!i) continue;
		for(int j = 0; j < k; j ++)
			if(j != x) cnt[i][j] = cnt[i - 1][j];
	}

	int m; cin >>m;
	while(m --)
	{
		string t; cin >>t;
		int len = t.size(), l_max = -1; bool f = 0;

		for(int i = 0; i < len; i ++)
		{
			int x = t[i] - 'a';

			int l = 0, r = now[x] + 1;
			while(l + 1 != r)
			{
				int mid = l + r >> 1;
				if(pos[x][mid] > l_max) r = mid;
				else l = mid;
			}		
			if(r == now[x] + 1)
			{
				f = 1;
				break;
			}
			l_max = pos[x][r];
			cout <<i <<" " <<r <<" " <<pos[x][r] <<endl;
		}

		cout <<l_max <<endl;
		if(f) cout <<0 <<endl;
		else
		{
			int ans = INF;
			
			for(int i = 0; i < k; i ++)
				ans = min(ans, cnt[n - 1][i] - cnt[l_max][i]);
			cout <<ans + 1 <<endl;
		}
	}
	return 0;
}
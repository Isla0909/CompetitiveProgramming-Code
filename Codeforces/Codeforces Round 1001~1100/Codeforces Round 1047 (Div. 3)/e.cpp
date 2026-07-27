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
		int n, k; cin >>n >>k;
		vector<int> a(n + 1), cnt(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			cnt[a[i]] ++;
		}

		int mex = 0;
		for(int i = 0; i <= n; i ++)
			if(!cnt[i])
			{
				mex = i;
				break;
			}
		sort(a.begin() + 1, a.end());
		bool f = 1; int tar = 0, c = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(cnt[a[i]] != 1 || a[i] > mex)
			{
				c ++; a[i] = mex;
				if(f)
				{
					tar = a[i];
					f = 0;
				}
			}
		}

		if(k == 1) cout <<accumulate(a.begin() + 1, a.end(), 0LL) <<endl;
		else
		{
			sort(a.begin() + 1, a.end());
			f = 0;
			for(int i = 2; i <= n; i ++)
				if(a[i] == a[i - 1])
				{
					f = 1;
					break;
				}
			if(!f) cout <<accumulate(a.begin() + 1, a.end(), 0LL) <<endl;
			else
			{
				//tell(1, a);

				int mn = *min_element(a.begin() + 1, a.end());
				if(mn != 0)
				{
					if(k & 1) cout <<n <<endl;
					else cout <<0 <<endl;
					continue;
				}

				int o, e;
				int idx = 0; int x = -1;
				for(int i = 1; i <= n; i ++)
				{
					if(idx > a[i])
					{
						e = a[i] + 1;
						o = a[i];
						x = a[i];
						break;
					}
					if(a[i] == idx)
					{
						idx ++;
						continue;
					}
					else
					{
						e = idx;
						o = idx + 1;
						x = idx;
						break;
					}
				}
				i64 sum = 0, c = 0;
				for(int i = 1; i <= n; i ++)
				{
					if(a[i] < x) sum += a[i];
					else c ++;
				}
				if(k % 2 == 0) cout <<sum + c * e <<endl;
				else cout <<sum + c * o <<endl;
			}
		}	
	}
	return 0;
}
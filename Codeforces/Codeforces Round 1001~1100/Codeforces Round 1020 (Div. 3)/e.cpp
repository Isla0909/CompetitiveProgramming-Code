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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		vector<int> p(n + 1), pos(n + 1);
		for(int i = 1; i <= n; i ++)
		{
			int x; cin >>x;
			p[i] = x;
			pos[x] = i;
		}
		while(m --)
		{
			int l, r, x; cin >>l >>r >>x;
			int k = x;
			x = pos[x]; int mid = l + r >> 1;
			
			if(x < l || x > r)
			{
			    cout <<-1 <<" ";
			    continue;
			}
			
			int sl = 0, sr = 0; int cnt1 = 0, cnt2 = 0;
			int da = 0, xiao = 0;
			while(mid != x)
			{
				if(x > mid)
				{
					l = mid + 1;
					sr ++;
					if(p[mid] > k) cnt1 ++;
				}
				else
				{
					r = mid - 1;
					sl ++;
					if(p[mid] < k) cnt2 ++;
				}
                mid = l + r >> 1;
 			}
			if(k - 1 < sr || n - k < sl) cout <<-1 <<" ";
			else cout <<max(cnt1, cnt2) * 2 <<" ";
		}
		cout <<endl;
	}
	return 0;
}
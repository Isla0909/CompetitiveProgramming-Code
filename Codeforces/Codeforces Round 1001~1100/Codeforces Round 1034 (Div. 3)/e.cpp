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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
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
		vector<int> a(n), cnt(n + 1), diff(n + 2, 0), ans(n + 1);
		for(int i = 0; i < n; i ++)
		{
			int x; cin >>x;
			a[i] = x;
			cnt[x] ++;
		}

		for(int i = 0; i <= n; i ++)
		{
			diff[cnt[i]] ++;
			diff[n - i + 1] --;
			if(!cnt[i]) break;
		}
		for(int k = 0; k <= n; k ++)
			ans[k] = (k ? ans[k - 1] : 0) + diff[k];
		for(int k = 0; k <= n; k ++)
			cout <<ans[k] <<" \n"[k == n];
	}
	return 0;
}
//如果删掉k个数想要是新数组取值为i: 
//0 ~ i - 1的cnt都大于0, 并且cnt[i] >= k
//所以如果遍历0 ~ n的话, 只要前面的cnt都存在, 那么当k取值是[cnt[i], n - i]时, MEX(a)就可以取到i
//当cnt[i]不存在时, 无论你怎么删, 是一定无法是MEX(a)取到i + 1的,所以直接break
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

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

bool cmp(const pii &a, const pii &b)
{
	return a.ff < b.ff;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n; bool f = 0;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i ++) cin >>a[i];

		vector<int> b = a;
		b[1] = -b[1];
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for(int i = 2; i <= n; i ++)
		{
			if(a[i] > a[1] && -a[i] < a[1]) cnt1 ++;
			if(a[i] < a[1] && -a[i] > a[1]) cnt3 ++;
		}
		for(int i = 2; i <= n; i ++)
		{
			if(b[i] > b[1] && -b[i] < b[1]) cnt2 ++;
			if(b[i] < b[1] && -b[i] > b[1]) cnt4 ++;
		}
		int x1 = a[1], x2 = b[1];
		sort(a.begin() + 1, a.end()), sort(b.begin() + 1, b.end());
		int idx1, idx2;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == x1)
			{
				idx1 = i;
				break;
			}
		}
		for(int i = 1; i <= n; i ++)
		{
			if(b[i] == x2)
			{
				idx2 = i;
				break;
			}
		}
		//cout <<idx1 <<" " <<idx2 <<endl;
		if(idx1 <= (n + 1) / 2 && cnt1 + idx1 >= (n + 1) / 2) f = 1;
		if(idx2 <= (n + 1) / 2 && cnt2 + idx2 >= (n + 1) / 2) f = 1;
		if(idx1 >= (n + 1) / 2 && idx1 - cnt3 <= (n + 1) / 2) f = 1;
		if(idx2 >= (n + 1) / 2 && idx2 - cnt4 <= (n + 1) / 2) f = 1;
		if(f) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	return 0;
}
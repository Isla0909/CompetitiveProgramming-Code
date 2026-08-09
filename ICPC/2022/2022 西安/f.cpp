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

	int n, a, b; cin >>n >>a >>b;
	vector<string> v(n);
	for(int i = 0; i < n; i ++) cin >>v[i];

	if(b >= 2 * a) cout <<3 * n * a <<endl;
	else
	{
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i ++)
		{
			cnt1 ++;
			char c1 = v[i][0], c2 = v[i][1], c3 = v[i][2];	
			if(c1 == c2 || c1 == c3 || c2 == c3) cnt2 ++;
			else cnt1 += 2;
		}	
		if(b <= a) cout <<(cnt1 + cnt2) * b <<endl;
		else cout <<cnt1 * a + cnt2 * b <<endl;
	}

	return 0;
}
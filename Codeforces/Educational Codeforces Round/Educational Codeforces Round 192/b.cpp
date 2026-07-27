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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
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
		int n; cin >>n;
		vector<int> a(n + 1);
		vector pre(4, vector<int>(n + 1));
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			for(int j = 1; j <= 3; j ++)
				pre[j][i] = pre[j][i - 1] + (j == a[i]);
		}

		int idx1 = -1, idx2 = -1, c = 0;
		for(int i = 1; i <= n - 2; i ++)
		{
			if(a[i] == 1) c ++;
			if((i & 1) && c >= (i + 1) / 2)
			{
				if(idx1 == -1) idx1 = i;
			}
			if(i % 2 == 0 && c >= i / 2)
			{
				if(idx2 == -1) idx2 = i;
			}
		}


		//cout <<idx1 <<" " <<idx2 <<endl;


		auto check = [&](int idx) -> bool
		{
			if(idx == -1) return false;
			for(int i = idx + 1; i <= n - 1; i ++)
			{
				int c1 = pre[1][i] - pre[1][idx], c2 = pre[2][i] - pre[2][idx];
				if(c1 + c2 >= (i - idx + 1) / 2) return true;
			}
			return false;
		};

		cout <<(check(idx1) || check(idx2) ? "YES" : "NO") <<endl;
	}
	return 0;
}

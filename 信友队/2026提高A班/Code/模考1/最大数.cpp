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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f;

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

	int m, mod; cin >>m >>mod;
	vector<int> v{0}, stk;

	int n = 0, t = 0;
	while(m --)
	{
		char op; cin >>op;
		if(op == 'A')
		{
			i64 x; cin >>x;
			x = (x + t) % mod;
			v.push_back(x);
			n ++;

			while(stk.size() && x >= v[stk.back()]) stk.pop_back();
			stk.push_back(n);

			// tell(0, stk);
			// tell(1, v);
		}
		else
		{
			int len; cin >>len;
			int r = n, l = n - len + 1;

			int lo = -1, hi = stk.size();
			//tell(0, stk);
			while(lo + 1 != hi)
			{
				int mid = lo + hi >> 1;
			//	cout <<mid <<" " <<stk[mid] <<endl;
				if(stk[mid] < l) lo = mid;
				else hi = mid;
			//	cout <<lo <<" " <<hi <<endl;
			}
			cout <<v[stk[hi]] <<endl;

			t = v[stk[hi]];
		}
	}
	
	return 0;
}

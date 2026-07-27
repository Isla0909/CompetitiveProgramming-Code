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
		deque<int> deq;

		int q; cin >>q;
		i64 sum = 0, ans = 0;
		bool rev = false;

		while(q --)
		{
			int op; cin >>op;
			if(op == 1)
			{
				if(!rev)
				{
					int x = deq.back();
					ans -= 1LL * x * deq.size();
					deq.pop_back();
					ans += sum;
					deq.push_front(x);
				}
				else
				{
					int x = deq.front();
					ans -= 1LL * x * deq.size();
					deq.pop_front();
					ans += sum;
					deq.push_back(x);
				}
			}
			else if(op == 2)
			{
				rev = 1 - rev;
				ans = 1LL * (deq.size() + 1) * sum - ans;
			}
			else
			{
				int x; cin >>x;
				if(!rev)
				{
					deq.push_back(x);
					ans += 1LL * x * deq.size();
				}
				else
				{
					deq.push_front(x);
					ans += 1LL * x * deq.size();
				}
				sum += x;
			}
			cout <<ans <<endl;
		}
	}
	return 0;
}
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

template <typename T>
struct Fenwick
{
	int n;
	vector<T> tr;

	#define lowbit(x) (x & -x)

	void initial(int n_)
	{
		n = n_;
		tr.assign(n + 1, T{});
	}

	Fenwick(int n_ = 0)
	{
		initial(n_);
	}

	void add(int x, const T &c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] += c;
	}

	T sum(int x)
	{
		T ans{};
		for(int i = x; i; i -= lowbit(i))
			ans += tr[i];
		return ans;
	}

	T rangeSum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}

	int select(const T &k)
	{
		int x = 0;
		T cur{};
		for(int i = 1 << __lg(n); i; i /= 2)
		{
			if(x + i <= n && cur + tr[x + i] <= k)
			{
				x += i;
				cur += tr[x];
			}
		}
		return x;
	}

	void max_update(int x, const T &c)
	{
		for(int i = x; i <= n; i += lowbit(i))
			tr[i] = max(tr[i], c);
	}

	T max_query(int x)
	{
		T ans{};
		for(int i = x; i; i -= lowbit(i))
			ans = max(ans, tr[i]);
		return ans;
	}

	ll calc(vector<T> &a)
	{
		tr.assign(n + 1, T{});

		vector<int> b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		auto find = [&](int x) -> int
		{
			return lower_bound(b.begin(), b.end(), x) - b.begin();
		};

		ll ans = 0;
		for(int i = 0; i < a.size(); i ++)
		{
			int x = find(a[i]) + 1;
			add(x, 1);
			ans += i + 1 - sum(x);
		}
		return ans;
	}

};

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1), odd, even;
		for(int i = 1; i <= n; i ++)
		{
			cin >>a[i];
			if(i & 1) odd.push_back(a[i]);
			else even.push_back(a[i]);
		}

		if(n & 1)
		{
			Fenwick<int> o((n + 1) / 2), e(n / 2);
			int cnt1 = o.calc(odd), cnt2 = e.calc(even);

			sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
			int cnt3 = o.calc(odd), cnt4 = e.calc(even);


			int idx1 = 0, idx2 = 0;
			for(int i = 1; i <= n - 3; i ++)
			{
				if(i & 1) cout <<odd[idx1 ++] <<" ";
				else cout <<even[idx2 ++] <<" ";
			}
			if(abs(cnt1 - cnt3) % 2 == abs(cnt2 - cnt4) % 2)
				cout <<odd[idx1] <<" " <<even[idx2] <<" " <<odd[idx1 + 1] <<endl;
			else
				cout <<odd[idx1 + 1] <<" " <<even[idx2] <<" " <<odd[idx1] <<endl;
		}
		else
		{
			Fenwick<int> o(n / 2), e(n / 2);
			int cnt1 = o.calc(odd), cnt2 = e.calc(even);

			sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
			int cnt3 = o.calc(odd), cnt4 = e.calc(even);

			int idx1 = 0, idx2 = 0;
			for(int i = 1; i <= n - 3; i ++)
			{
				if(i & 1) cout <<odd[idx1 ++] <<" ";
				else cout <<even[idx2 ++] <<" ";
			}

			if(abs(cnt1 - cnt3) % 2 == abs(cnt2 - cnt4) % 2)
				cout <<even[idx2] <<" " <<odd[idx1] <<" " <<even[idx2 + 1] <<endl;
			else
				cout <<even[idx2 + 1] <<" " <<odd[idx1] <<" " <<even[idx2] <<endl;
		} 
	}
	return 0;
}
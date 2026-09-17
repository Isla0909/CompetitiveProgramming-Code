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

	vector<int> v;
	vector<bool> nima(8000000);
	for(int i = 1; i * i <= 8000000; i ++)
	{
		v.push_back(i * i);
		nima[i * i] = true;
	}
	//tell(0, v);

	vector<int> diff;
	for(int i = 1; i < v.size(); i ++)
		diff.push_back(v[i] - v[i - 1]);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		deque<int> q;
		q.emplace_back(1);

		for(int i = 2; i <= n; i ++)
		{
			if(nima[i + q.back()]) q.emplace_front(i);
			else q.emplace_back(i);
		}
		for(auto x : q)
			cout <<x <<" ";
		cout <<endl;
		// vector<int> p, st(n + 1);
		// for(auto x : diff)
		// {
		// 	if(x <= n) 
		// 	{
		// 		p.push_back(x);
		// 		st[x] = 1;
		// 	}
		// 	else break;
		// }
		// for(int i = 1; i <= n; i ++)
		// 	if(!st[i]) p.push_back(i);

		// auto check = [&]() -> bool
		// {
		// 	for(int i = 1; i < n; i ++)
		// 	{
		// 		int x = p[i - 1] + p[i];
		// 		if(nima[x]) return false;
		// 	}
		// 	return true;
		// };

		// while(!check())
		// {
		// 	shuffle(p.begin(), p.end(), rng);
		// }
		// tell(0, p);
	}
	return 0;
}

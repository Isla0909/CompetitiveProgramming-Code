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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 19930726;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

i64 quick_pow(i64 a, i64 b)
{
	i64 res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; i64 k; cin >>n >>k;
	string t; cin >>t;
	string s = "+#";

	for(int i = 0; t[i]; i ++)
	{
		s.push_back(t[i]);
		s.push_back('#');
	}
	s.push_back('-');

	//cout <<s <<endl;

	int len = s.size();
	vector<int> r(len);
	int mr = 0, mid;
	for(int i = 1; i < len; i ++)
	{
		if(i < mr) r[i] = min(r[2 * mid - i], mr - i);
		else r[i] = 1;

		while(s[i - r[i]] == s[i + r[i]]) r[i] ++;
		if(i + r[i] > mr)
		{
			mid = i;
			mr = i + r[i];
		}
	}
	// cout <<s <<endl;
	vector<int> v;
	vector<i64> cnt(1000001);
	for(int i = 2; s[i] >= 'a' && s[i] <= 'z'; i += 2)
	{
		// cout <<i <<" " <<r[i] <<endl;
		if(r[i] & 1) continue;
		int c = r[i] - 1;
		cnt[c] ++;
	}

	i64 ans = 1, pre = 0;
	for(int i = n; i >= 1; i --)
	{
		if(i % 2 == 0) continue;
		pre += cnt[i];
		i64 take = min(pre, k);
		ans = ans * quick_pow(i, take) % mod;
		k -= take;
		if(!k) break;
	}
	if(k) cout <<-1 <<endl;
	else cout <<ans <<endl;
	return 0;
}

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

int quick_pow(int a, ll b, int p)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = 1LL * res * a % p;

		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res % p;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int n, m; cin >>n >>m;
	string s; cin >>s;
	string suf = s.substr(s.size() / 2, n - s.size() / 2);
	for(int i = 0; suf[i]; i ++)
	{
		int x = suf[i] - 'a';
		suf[i] = char((x + 1) % 26 + 'a');
	}
	string t = s.substr(0, s.size() / 2) + s + suf;


	int cnt = 1;
	while(t.size() / 2 < 1000000)
	{
		s = t;
		suf = s.substr(s.size() / 2, s.size() / 2);
		for(int i = 0; suf[i]; i ++)
		{
			int x = suf[i] - 'a';
			suf[i] = char((x + 1) % 26 + 'a');
		}
		t = s.substr(0, s.size() / 2) + s + suf;
		cnt ++;
		//cout <<t <<endl;
	}
	//cout <<quick_pow(10, 100, 26) <<endl;
	int x = (quick_pow(10, 100, 26) - cnt + 260000) % 26;
	vector<char> v; int i = t.size() - 1;
	while(m --)
	{
		char c = char((t[i] - 'a' + x) % 26 + 'a');
		v.push_back(c);
		i --;
	}
	reverse(v.begin(), v.end());
	for(auto ch : v)
		cout <<ch;
	return 0;
}
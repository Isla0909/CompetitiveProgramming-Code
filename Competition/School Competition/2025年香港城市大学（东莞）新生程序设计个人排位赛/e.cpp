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
typedef pair<string, int> psi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

string add(string a, string b)
{
    string c;
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
    int t = 0, i = 0;
    while(i < a.size() || i < b.size() || t)
    {
        if(i < a.size()) t += a[i] - '0';
        if(i < b.size()) t += b[i] - '0';
        c.push_back(t % 10 + '0');
        t /= 10, i ++;
    }
    reverse(c.begin(), c.end());
    return c;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<psi> v(n); int x = -1;
	for(int i = 0; i < n; i ++)
	{
		cin >>v[i].ff >>v[i].se;
		if(x == -1 && v[i].ff == "sensei")
		{
			x = v[i].se;
		}
	} 
	i64 ans = x;
	for(int i = 0; i < n; i ++)
		if(v[i].se < x) ans += v[i].se;
	cout <<ans <<endl;
	return 0;
}
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

int query(int a, int b)
{
	if(a > b) swap(a, b);
	cout <<"? " <<a <<" " <<b <<endl;
	int x; cin >>x;
	if(x == a * b) return 0;
	else if(x == a * (b + 1)) return 1;
	return 2;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int l = 2, r = 999;
		while(r - l > 2)
		{
			int midl = l + (r - l) / 3;
			int midr = r - (r - l) / 3;
			int x = query(midl, midr);
			if(!x) l = midr + 1;
			else if(x == 1) l = midl + 1, r = midr;
			else r = midl;
		}
		int x = query(l, l + 1);
		if(!x) cout <<"! " <<r <<endl;
		else if(x == 1) cout <<"! " <<l + 1 <<endl;
		else cout <<"! " <<l <<endl;
	}
	return 0;
}

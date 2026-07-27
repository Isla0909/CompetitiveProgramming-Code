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

i64 query1(int l, int r)
{
	cout <<1 <<" " <<l <<" " <<r <<endl;
	i64 s; cin >>s;
	return s;
}

i64 query2(int l, int r)
{
	cout <<2 <<" " <<l <<" " <<r <<endl;
	i64 s; cin >>s;
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int ansl = 1, ansr = n;
		int l = 0, r = n + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			i64 s1 = query1(1, mid), s2 = query2(1, mid);
			//cout <<s1 <<" " <<s2 <<endl;
			if(s1 < s2) r = mid;
			else l = mid;
			//cout <<l <<" " <<r <<endl;
		}
		ansl = r;
		
		i64 s1 = query1(ansl, n), s2 = query2(ansl, n);
		cout <<"! " <<ansl <<" " <<ansl + s2 - s1 - 1 <<endl;
	}
	return 0;
}
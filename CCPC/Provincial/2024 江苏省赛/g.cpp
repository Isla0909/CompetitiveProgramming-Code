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
		int B, T1, A1, T2, A2; cin >>B >>T1 >>A1 >>T2 >>A2;
		long double b = B, t1 = T1, a1 = A1, t2 = T2, a2 = A2;
		if(A1 <= 1LL * (T2 - T1) * B)
		{  
			double s1 = a1 / b, s2 = a2 / b;
			cout <<fixed <<setprecision(9) <<s1 <<" " <<s2 <<endl;
		}
		else
		{
			a1 -= (t2 - t1) * b;
			double n1 = 2.0 * a1 / b, n2 = 2.0 * a2 / b;
			if(n1 < n2)
			{
				a2 -= n1 * b / 2;
				n2 = n1;
				n1 += t2 - t1;
				n2 += a2 / b;
				cout <<fixed <<setprecision(9) <<n1 <<" " <<n2 <<endl;
			}
			else
			{
				a1 -= n2 * b / 2;
				n1 = t2 - t1 + n2;
				n1 += a1 / b;
				cout <<fixed <<setprecision(9) <<n1 <<" " <<n2 <<endl;
			}  
		}
	}
	return 0;
}
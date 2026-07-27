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

	int n, m; cin >>n >>m;
	vector<int> a(n), v1, v2;
	for(int i = 0; i < n; i ++) cin >>a[i];

	queue<int> q;
	vector<int> stk;
	while(m --)
	{
		int op; cin >>op;
		if(op & 1)
		{
			int x; cin >>x;
			q.emplace(x);
			stk.push_back(x);
		}
		else
		{
			int t = q.front(); q.pop();
			v1.push_back(t);
			int x = stk.back(); stk.pop_back();
			v2.push_back(x);
		}
	}
	bool f1 = (a == v1), f2 = (a == v2);
	if(f1 && f2) cout <<"both" <<endl;
	else if(f1) cout <<"queue" <<endl;
	else if(f2) cout <<"stack" <<endl;
	else cout <<-1 <<endl;
	return 0;
}

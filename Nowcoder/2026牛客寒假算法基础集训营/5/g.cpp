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

	//string s = "012345";
	string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
	int now = 1;

	auto change = [&](int x) -> void
	{
		if(x == 4) now = (now + 2) % 8;
		else if(x == 5) now = (now - 2 + 8) % 8;
		else if(x == 0)
		{
			if(now == 0 || now == 4) return ;
			else if(now == 1) now = 7;
			else if(now == 7) now = 1;
			else if(now == 2) now = 6;
			else if(now == 6) now = 2;
			else if(now == 3) now = 5;
			else if(now == 5) now = 3;
		}
		else if(x == 1)
		{
			if(now == 1 || now == 5) return ;
			else if(now == 0) now = 2;
			else if(now == 2) now = 0;
			else if(now == 3) now = 7;
			else if(now == 7) now = 3;
			else if(now == 4) now = 6;
			else if(now == 6) now = 4;
		}
		else if(x == 2)
		{
			if(now == 2 || now == 6) return ;
			else if(now == 1) now = 3;
			else if(now == 3) now = 1;
			else if(now == 0) now = 4;
			else if(now == 4) now = 0;
			else if(now == 5) now = 7;
			else if(now == 7) now = 5;
		}
		else
		{
			if(now == 3 || now == 7) return ;
			else if(now == 2) now = 4;
			else if(now == 4) now = 2;
			else if(now == 1) now = 5;
			else if(now == 5) now = 1;
			else if(now == 0) now = 6;
			else if(now == 6) now = 0;
		}
	};

	for(int i = 0; s[i]; i ++)
	{
		int x = s[i] - '0';
		change(x);
		if(now == 1) cout <<0;
		else if(now == 3) cout <<1;
		else if(now == 5) cout <<2;
		else if(now == 7) cout <<3;
		// cout <<i <<" " <<now <<endl;
	}
	return 0;
}

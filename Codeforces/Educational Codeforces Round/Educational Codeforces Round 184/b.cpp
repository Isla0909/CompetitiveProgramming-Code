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

bool check(string &s)
{
	for(int i = 0; i < s.size(); i ++)
		if(s[i] == '*')
		{
			if(i + 1 < s.size() && (s[i + 1] == '*' || s[i + 1] == '<')) return true;
			if(i && s[i - 1] == '>') return true;
		} 
	return false;
}
//>*<
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		int n = s.size();
		if(n == 1)
		{
			cout <<1 <<endl;
			continue;
		}

		if(check(s))
		{
			cout <<-1 <<endl;
			continue;
		}

		vector<int> v1, v2; int c = 0;
		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == '>') v1.push_back(i);
			else if(s[i] == '<') v2.push_back(i);
			else c ++;
		}
		//<<<<>>>>>>>>>>
		//><
		if(v1.size() && v2.size() && v1.front() < v2.back()) cout <<-1 <<endl;
		else cout <<max(v1.size(), v2.size()) + c <<endl;
	}
	return 0;
}

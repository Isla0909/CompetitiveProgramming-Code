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

int len(int x)
{
	int res = 0;
	while(x)
	{
		res ++;
		x /= 10;
	}
	return res;
}

map<char, string> mp = {{'0', "ling"}, {'1', "yi"}, {'2', "er"}, {'3', "san"}, {'4', "si"}, 
						{'5', "wu"}, {'6', "liu"}, {'7', "qi"}, {'8', "ba"}, {'9', "jiu"}};
vector<string> v;

void read1(string s)
{
	bool f = 0;
	for(int i = 0; s[i]; i ++)
	{
		auto t = s[i];
		if(t == '0') continue;
		else v.emplace_back(mp[t]);

		if(!i) v.emplace_back("qian");
		else if(i == 1) v.emplace_back("bai");
		else if(i == 2) v.emplace_back("shi");
	}
}



void read2(string s)
{
	if(len(stoi(s)) == 1)
	{
		v.emplace_back(mp[s.back()]);
		return ;
	}
	if(len(stoi(s)) == 2)
	{
		v.emplace_back(mp[s[2]]);
		v.emplace_back("shi");
		if(s[3] != '0') v.emplace_back(mp[s[3]]);
		return ;
	}

	int f = 0;
	for(int i = 0; s[i]; i ++)
	{
		auto t = s[i];
		if(t == '0')
		{
			if(!f) f = 1;
			else if(f == 1)
			{
				f = 2;
				v.emplace_back("ling");
			}
			continue;
		}
		else v.emplace_back(mp[t]);

		if(!i) v.emplace_back("qian");
		else if(i == 1) v.emplace_back("bai");
		else if(i == 2) v.emplace_back("shi");
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >>s;
	int x = stoi(s);
	reverse(s.begin(), s.end());
	while(s.size() != 12) s.push_back('0');

	reverse(s.begin(), s.end());
	string a = s.substr(0, 4), b = s.substr(4, 4), c = s.substr(8, 4);
	


	if(stoi(a))
	{
		read1(a);
		v.emplace_back("yi");
	}

	if(stoi(b))
	{
		if(stoi(a) && b[0] == '0') v.emplace_back("ling");
		read2(b);
		v.emplace_back("wan");
	}

	if(stoi(c))
	{
		if(c[0] == '0' && (stoi(a) || stoi(b))) v.emplace_back("ling");
		read2(c);
	}

	if(!stoi(a) && !stoi(b) && !stoi(c))
	{
		cout <<"ling ";
	}

	for(int i = 0; i < v.size(); i ++)
	{
		if(i == 0 && v[0] == "yi" && (to_string(x).size() % 4 == 2)) continue;
		if(!(i == v.size() - 1 && v[i] == "ling")) cout <<v[i] <<" ";
		if(i + 1 < v.size() && v[i] == "wan" && v[i + 1] != "ling" && b[3] == '0') cout <<"ling ";
	}

	return 0;
}

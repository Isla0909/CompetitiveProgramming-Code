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
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

void tell1(vector<int> &v)
{
	for(int i = 1; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, m; cin >>n >>m;
		string s; cin >>s;
		
		map<int, int> ba, ca, bc, cb;
		for(int i = 1; i <= m; i ++)
		{
			char a, b; cin >>a >>b;
			if(a == 'a') continue;
			if(a == 'b' && b == 'a') ba[i] = i;
			else if(a == 'c' && b == 'a') ca[i] = i;
			else if(a == 'b' && b == 'c') bc[i] = i;
			else if(a == 'c' && b == 'b') cb[i] = i;
		}

		for(int i = 0; s[i]; i ++)
		{
			if(s[i] == 'a')	continue;
			else if(s[i] == 'b')
			{
				if(ba.size())
				{
					auto it = ba.begin();
					ba.erase(it);
					s[i] = 'a';
				}
				else
				{
					if(bc.size() && ca.size())
					{
						auto it1 = bc.begin(), it2 = ca.upper_bound(it1->ff);
						if(it2 != ca.end())
						{
							s[i] = 'a';
							bc.erase(it1), ca.erase(it2);
						}
					}
				}
			}
			else
			{
				if(ca.size())
				{
					auto it = ca.begin();
					ca.erase(it);
					s[i] = 'a';
				}
				else 
				{	
					if(cb.size() && ba.size())
					{
						auto it1 = cb.begin(), it2 = ba.upper_bound(it1->ff);
						if(it2 != ba.end())
						{
							s[i] = 'a';
							cb.erase(it1), ba.erase(it2);
							continue;
						}
					}
					if(cb.size())
					{
						auto it = cb.begin();
						cb.erase(it);
						s[i] = 'b';
					}
				}
			}
		}
		cout <<s <<endl;		
	}
	return 0;
}
//abcaababcbbcabcbbcabcbabbbbabc
//aaaaaaaaaaaaaaabbbabcbabbbbabc wa
//aabaaaaaaaaaaaabbcabcbabbbbabc ac
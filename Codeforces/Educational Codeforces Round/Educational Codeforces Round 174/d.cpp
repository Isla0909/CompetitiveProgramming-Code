#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define st begin()
#define ed end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int solve(string s)
{
	int same = 0, l = s.size();
	while(s[same] == s[l - 1 - same]) same ++;

	vector <int> cnt(30, 0);
	for(int i = same; i < l - same; i ++)
	{
		int x = s[i] - 'a';
		cnt[x] ++;
	}
	vector <int> v(30, 0);
	for(int i = same; ; i ++)
	{
		int x = s[i] - 'a';
		if(v[x] + 1 > cnt[x] / 2) return l - 1 - same - i + 1;
		else v[x] ++;
	}
}

bool judge(string s)
{
	int l = s.size();
	for(int i = 0; i < l / 2; i ++)
		if(s[i] != s[l - 1 - i]) return false;
	return true;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		if(judge(s)) 
		{
			cout <<0 <<endl;
			continue;
		}

		int ans = INF;
		ans = min(ans, solve(s));
		reverse(s.begin(), s.end());
		ans = min(ans, solve(s));


		vector <int> cnt(30, 0), v(30, 0);
		for(int i = 0; s[i]; i ++)
		{
			int x = s[i] - 'a';
			cnt[x] ++;
		}
		for(int i = 0; i < s.size() / 2; i ++)
		{
			int x= s[i] - 'a';
			v[x] ++;
		}
		bool f = 1;
		for(int i = 0; i < 26; i ++)
			if(v[i] * 2 != cnt[i])
			{
				f = 0;
				break;
			} 
		if(f)
		{
			int l = s.size() + 1, r = -1;
			for(int i = 0; i < s.size() / 2; i ++)
			{
				if(s[i] != s[s.size() - 1 - i])
				{
					l = min(l, i);
					r = max(r, i);
				}
			}
			//cout <<l <<r <<endl;
			ans = min(ans, r - l + 1);
		}
		cout <<ans <<endl;
	}
	return 0;
}
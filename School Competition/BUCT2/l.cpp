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

constexpr int N = 3e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int trie[N][100], cnt[N];
int tot;

int newNode()
{
	tot++;
	fill(trie[tot], trie[tot] + 100, 0);
	cnt[tot] = 0;           
	return tot;
}

void initial()
{
	tot = 0;
	newNode();          
}

void add(const string &s, char offset = 'A')
{
	int p = 1;
	for(int i = 0; i < s.size(); i ++)
	{
		int x = s[i] - offset;
		//assert(s[i] >= 'a' && s[i] <= 'z');

		if(!trie[p][x]) trie[p][x] = newNode();
		p = trie[p][x];
	}
	cnt[p] ++;     
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	initial();

	vector<string> v;
	int n; cin >>n;

	for(int i = 0; i < n; i ++)
	{
		string s; cin >>s;
		v.push_back(s);
		for(int j = 0; j < s.size(); j ++)
			assert(s[j] >= 'a' && s[j] <= 'z');
		add(s);
	}

	vector<string> ans;

	for(int i = 0; i < n; i ++)
	{
		string &s = v[i]; int p = 1;
		vector<int> deg(100);
		vector<vector<int>> adj(100); bool f = 1;
		
		bool st[100][100] = {};
		for(int j = 0; j < s.size(); j ++)
		{
			int x = s[j] - 'A';
			for(int u = 0; u < 100; u ++)
			{
				if(u == x) continue;
				if(trie[p][u])
				{
					if(!st[x][u])
					{
						st[x][u] = 1;
						adj[x].push_back(u);
						deg[u] ++;
					}
				}
			}
			p = trie[p][x];
			if(cnt[p] && j != s.size() - 1)
			{
				f = 0;
				break;
			}
		}
		if(!f) continue;

		queue<int> q; bool h = 1;
        for(int u = 0; u < 100; u ++)
            if(!deg[u]) q.push(u);
        while(q.size())
        {
            auto u = q.front(); q.pop();
            for(auto x : adj[u])
            {
                deg[x] --;
                if(!deg[x]) q.push(x);
            }
        }
        for(int u = 0; u < 100; u ++)
            if(deg[u])
            {
                h = 0;
                break;
            }
        if(f && h) ans.push_back(s);
	}
	cout <<ans.size() <<endl;
    for(auto s : ans)
        cout <<s <<endl;
    return 0;
}

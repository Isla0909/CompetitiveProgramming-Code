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
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void solve(string s)
{
	int l = s.size();
	//cout <<l <<endl;
	vector <int> f(l, 1);
	for(int i = 0; i < l; i ++)
		for(int j = 0; j < i; j ++)
			if(s[i] > s[j]) f[i] = max(f[i], f[j] + 1);
	cout <<*max_element(f.begin(), f.end()) <<endl;;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		string s, k; cin >>s >>k;
		//cout <<s.size() <<endl;
		if(k.size() <= 2)
		{
			string t = "";
			int x = stoi(k);
			while(x --) t += s;
			solve(t);
		}
		else
		{
			int x = s.size() + 1;
			string t = "";
			while(x --) t += s;
			solve(t);
		}
	}
	return 0;
}
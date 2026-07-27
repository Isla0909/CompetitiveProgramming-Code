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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	vector <string> a = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
	vector <string> b = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

	map <string, int> mp;
	int t = 60; int i = 0, j = 0;
	for(int t = 1; t <= 60; t ++)
	{
		string s = a[i] + b[j];
		i ++, j ++;

		mp[s] = 1983 + t;

		if(i == 10) i = 0;
		if(j == 12) j = 0;
	}

	int T; cin >>T;
	while(T --)
	{
		string s; cin >>s;
		cout <<mp[s] <<endl;
	}
	return 0;
}
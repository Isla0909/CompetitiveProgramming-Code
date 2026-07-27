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
#define int long long
using namespace std;
using u32 = unsigned;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

void tell(vector<int> &v)
{
	for(auto x : v)
		cout <<x <<" ";
	cout <<endl;
}

bool check(vector <int> &a)
{
	int x = a[0] % 2;
	for(int i = 1; i < a.size(); i ++)
		if(a[i] % 2 != x) return false;
	return true;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector <int> a(n);
		for(auto &x : a) cin >>x;
		sort(a.begin(), a.end());
		if(check(a)) cout <<a[n - 1] <<endl;
		else
		{
			vector <int> v1, v2;
			for(int i = 0; i < n; i ++)
			{
				if(a[i] & 1) v1.push_back(a[i]);
				else v2.push_back(a[i]);
			}
			//cout <<a[n - 1] <<endl;
			// if(a[n - 1] & 1)
			// {
				int sum = v1.back();
				for(int i = 1; i < v2.size(); i ++)
					sum += v2[i];
				//cout <<"chi ou shu" <<sum <<endl;
				for(int i = 0; i < v1.size() - 1; i ++)
					sum += v1[i] - 1;
				//cout <<"ha?" <<sum <<endl;
				cout <<sum + v2[0] <<endl;
			// }
			// else
			// {
			// 	int sum = a[n - 1];
			// 	for(int i = 1; i < v1.size(); i ++)
			// 		sum += v1[i];
			// 	for(int i = 0; i < v2.size() - 1; i ++)
			// 		sum += v2[i] - 1;
			// 	cout <<sum + v1[0] <<endl;
			// }
		}
	}
	return 0;
}
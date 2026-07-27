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

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector <int> v(n);
		for(int i = 0; i < n; i ++) cin >>v[i];

		auto a = v;

		sort(v.begin(), v.end());
		if(v[0] == 0 && v[n - 1] == 0)//全是0
		{
			cout <<3 <<endl;
			cout <<1 <<" " <<n / 2 <<endl;
			cout <<2 <<" " <<n - n / 2 + 1 <<endl;
			cout <<1 <<" " <<2 <<endl;
		}
		else if(v[0] == 0)//有0
		{
			if(a[n - 1] != 0)
			{
				cout <<2 <<endl;
				cout <<1 <<" " <<n - 1 <<endl;
				cout <<1 <<" " <<2 <<endl;
			}
			else if(a[0] != 0)
			{
				cout <<2 <<endl;
				cout <<2 <<" " <<n <<endl;
				cout <<1 <<" " <<2 <<endl;
			}
			else
			{	
				cout <<3 <<endl;
				cout <<1 <<" " <<2 <<endl;
				cout <<2 <<" " <<n - 1 <<endl;
				cout <<1 <<" " <<2 <<endl;
			}
		}
		else
		{
			cout <<1 <<endl;
			cout <<1 <<" " <<n <<endl;
		}
	}
	return 0;
}
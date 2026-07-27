#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define st begin()
#define ed end()
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;
int a[N];

int n; 
void diff(int s)
{
	for(int i = n; i >= s; i --)
	{
		a[i] = a[i] - a[i - 1];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >>T;
	while(T --)
	{
		cin >>n;
		for(int i = 1; i <= n; i ++) cin >>a[i];

		if(n == 1)
		{
			cout <<a[1] <<endl;
			continue;
		}

		int sum = 0;
		for(int i = 1; i <= n; i ++) sum += a[i];

		for(int i = 1; i < n; i ++)
		{

			// for(int j = i; j <= n; j ++)
			// 	cout <<a[j] <<" ";
			//cout <<endl;
			int l = a[i], r = a[n];
			sum = max(sum, max(r - l, l - r));

			diff(i + 1);
		}
		cout <<sum <<endl;
		//cout <<endl;
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

bool judge(ll x)
{
	int l = -1, r = 5e5 + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(mid * mid <= x) l = mid;
		else r = mid;
	}
	if(l * l != x) return 1;
	return 0;
}
signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		int s = (n + 1) * n / 2;
		if(!judge(s))
		{
			cout <<-1 <<endl;
			continue;
		}
		else
		{
			cout <<"2 1 ";
			int sum = 3; int idx = 3;
			for(int i = 0; i < n - 2; i ++)
			{
				if(judge(sum + idx))
				{
					sum += idx;
					cout <<idx <<" ";
					idx ++;
				}
				else
				{
					cout <<idx + 1 <<" " <<idx <<" ";
					sum += idx * 2 + 1;
					idx += 2;
					i ++;
				}
			}
			cout <<endl;
		}
	}
	return 0;
}
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

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}

int calc(int n)
{
	return (1 + n) * n / 2;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n, k; cin >>n >>k;
		if(k & 1) cout <<0 <<endl;
		else
		{
			int a = n / k, b = n % k;
			int sum = 0;
			if(b > k / 2)
			{
				sum += (b - k / 2) * calc(a + 1) + k / 2 * calc(a) + (k - b) * calc(a);
			}
			else
			{
				sum += k / 2 * calc(a) + b * calc(a) + (k / 2 - b) * calc(a - 1);
			}
			cout <<sum <<endl;
		}
	}
	return 0;
}
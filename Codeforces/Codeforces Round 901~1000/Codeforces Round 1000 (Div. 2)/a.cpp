#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

signed main()
{
	int T; cin >>T;
	while(T --)
	{
		int a, b; cin >>a >>b;
		if(a == 1 && b == 1) cout <<1 <<endl;
		else cout <<b - a <<endl;
	}
	return 0;
}
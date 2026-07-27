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

bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}

void tell(int w[], int n)
{
    for(int i = 1; i <= n; i ++)
        cout << w[i] << " \n"[i == n];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n, k; cin >>n >>k;
        vector <int> a(n);
        for(auto &x : a) cin >>x;

        if(k == 1)
        {
        	int ans = a[0] + a[n - 1];
        	for(int i = 1; i < n - 1; i ++)
        		ans = max(ans, max(a[i] + a[0], a[i] + a[n - 1]));
        	cout <<ans <<endl;
        }
        else
        {
        	sort(a.begin(), a.end(), greater<int>());
        	ll ans = accumulate(a.begin(), a.begin() + k + 1, (ll)0);
        	cout <<ans <<endl;
        }
    }
    return 0;
}
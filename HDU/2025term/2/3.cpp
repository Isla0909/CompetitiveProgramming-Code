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

const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
	for(int i = 1; i <= n; i ++)
		cout <<w[i] <<" \n"[i == n];
}
void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    // 清空数组
    vector<int> l(N, 0), r(N, INF);
    vector<int> pre(N, -1);
    vector<bool> mp(N, 0), st(N, 0);
    vector<int> cnt(N, 0);

    int idx = INF;
    for (int i = 0; i < n; i ++)
    {
        int x = v[i];
        if (x && pre[x] == -1)
        {
            pre[x] = i;
            continue;
        }
        if (!x) idx = i;
        if (i > idx)
        {
            if (pre[x] != -1 && pre[x] < idx)
            {
                l[x] = 1;
                r[x] = min(r[x], i);
            }
        }
    }

    cnt[n - 1] = (v[n - 1] != 0); 
    mp[v[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i --)
    {
        int x = v[i];
        if (x && !mp[x])
        {
            mp[x] = 1;
            cnt[i] = cnt[i + 1] + 1;
        }
        else cnt[i] = cnt[i + 1];
    }

    ll sum = 0;
    for (int i = 0; i < n; i ++)
    {
        int x = v[i];
        if (x && l[x] && r[x] && !st[x])
        {
            st[x] = 1;
            sum += cnt[r[x] + 1];
        }
    }
    cout <<sum << endl;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		solve();
	}
	return 0;
}
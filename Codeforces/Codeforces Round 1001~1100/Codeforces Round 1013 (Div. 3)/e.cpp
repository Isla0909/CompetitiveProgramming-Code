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
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e7 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int primes[N], cnt;
int sum[N];
bool st[N];

void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; j < cnt && primes[j] * i < N; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);

    get_primes();
    sum[1] = 0;
    for (int i = 2; i < N; i ++)
    {
        if (!st[i])
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int upper_bound = n / i;
            ans += sum[upper_bound];
        }
        cout << ans << endl;
    }
    return 0;
}
    
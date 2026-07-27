#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;

ll a[maxn], b[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n + 1; i++)
            cin >> b[i];
        sort(a + 1, a + 1 + n, greater<ll>());
        sort(b + 1, b + 1 + n + 1, greater<ll>());

        auto check = [&](ll x)
        {
            __int128_t res = 0;
            for (int i = 1, j = 1; i <= n;)
            {
                if (x >= a[i])
                    res += __int128_t(1) * x * b[j], x = -1, j++;
                else
                    res += __int128_t(1) * a[i] * b[j], i++, j++;
                if (res >= m)
                    return true;
            }
            return false;
        };

        ll l = 0, r = 1e18;
        while (l + 1 < r)
        {
            ll mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }
        if (check(l)) cout << l << endl;
        else cout << r << endl;
    }
}

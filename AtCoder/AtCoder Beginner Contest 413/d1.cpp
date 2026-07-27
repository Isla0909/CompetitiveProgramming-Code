#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e9 + 5;
#define all(a) a.begin(), a.end()
#define pii pair<int, int>

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n <= 2)
    {
        cout << "Yes" << '\n';
        return;
    }
    auto cmp = [&](const int a, const int b)
    {
        return abs(a) < abs(b);
    };
    stable_sort(a.begin(), a.end(), cmp);
    if (abs(a[0]) == abs(a[n - 1]))
    {
        int cnt = 0;
        // int k = a[1] / a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                cnt++;
            }
        }
        if(cnt==n-cnt||cnt==n-cnt+1||cnt==n-cnt-1||cnt==0||cnt==n)
            cout << "Yes" << '\n';
        else{
            cout << "No" << '\n';
        }
            return;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] * a[0] != a[i - 1] * a[1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes" << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
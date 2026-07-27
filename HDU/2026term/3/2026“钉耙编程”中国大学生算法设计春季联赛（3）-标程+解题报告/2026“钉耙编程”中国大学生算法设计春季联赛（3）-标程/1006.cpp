#include <bits/stdc++.h>
using ld = long double;
#define int long long
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(k + 1));
    for (int j = 1; j <= k; j++) a[n][j] = n - 1;
    int l = 0, r = n;
    for (int i = 1; i < n; i++, l++, r++) {
        if (i == 1) {
            for (int j = 1; j <= (k - 1) / 2; j++) a[i][j] = l;
            for (int j = (k - 1) / 2 + 1; j <= k; j++) a[i][j] = r;
        } else {
            int cnt = 0;
            for (int j = 1; j <= k; j++) {
                cnt += a[i - 1][j] > n - 1;
            }
            int j = 1;
            for (; j <= k && cnt * j < (k * k + 1) / 2; j++) a[i][j] = l;
            for (; j <= k; j++) a[i][j] = r;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (a[i][j] > m) assert(false);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << a[i][j];
            if (i * j < n * k) {
                cout << ' ';
            }
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

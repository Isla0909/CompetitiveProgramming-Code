#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    auto pre = a, suf = a;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        pre[i][j] = suf[i][j] = a[i][j];
      }
      for (int j = 1 + 1; j <= m; j++) {
        pre[i][j] = max(pre[i][j - 1], a[i][j]);
      }
      for (int j = m - 1; j >= 1; j--) {
        suf[i][j] = max(suf[i][j + 1], a[i][j]);
      }
    }

    auto get_max = [&](int i, int j) {
      int lmax = pre[i][j - 1];
      int rmax = j == m ? 0 : suf[i][j + 1];
      return max(lmax, rmax);
    };

    const int offset = n + 5;
    i64 ans = 0;
    for (int x = 1; x <= m; x++) {
      vector<vector<i64>> f(n + 1, vector<i64>(2 * offset, -1));
      f[0][0 + offset] = 0;
      for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        for (int j = -i; j <= i; j++) {
          if (f[i - 1][j - 1 + offset] != -1) {
            f[i][j + offset] =
                max(f[i][j + offset], a[i][x] + f[i - 1][j - 1 + offset]);
          }
          if (f[i - 1][j + 1 + offset] != -1) {
            f[i][j + offset] =
                max(f[i][j + offset], get_max(i, x) + f[i - 1][j + 1 + offset]);
          }
        }
      }
      for (int j = 1; j <= n; j++) {
        ans = max(ans, f[n][offset + j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
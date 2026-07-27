#include <bits/stdc++.h>

#define Max 505

using namespace std;

const int mod = 1e9 + 7;

int T, n, m, f[Max][Max];

inline int qpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ans;
}

int main() {
  //	freopen("1004.in","r",stdin);
  //	freopen("1004.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = 0;
      }
    }
    for (int i = 1; i <= m; i++) {
      int l, r;
      cin >> l >> r;
      for (int j = l; j <= r; j++) {
        for (int k = l; k <= r; k++) {
          if (j != k) f[j][k] = 1;
        }
      }
      for (int j = 1; j <= n; j++) {
        if (j >= l && j <= r) continue;
        int now = 0;
        for (int k = l; k <= r; k++) {
          now = (now + f[j][k]) % mod;
        }
        now = 1ll * now * qpow(r - l + 1, mod - 2) % mod;
        for (int k = l; k <= r; k++) {
          f[j][k] = f[k][j] = now;
        }
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        sum = (sum + f[i][j]) % mod;
      }
    }
    cout << 1ll * sum * qpow(4, mod - 2) % mod << '\n';
  }
  return 0;
}
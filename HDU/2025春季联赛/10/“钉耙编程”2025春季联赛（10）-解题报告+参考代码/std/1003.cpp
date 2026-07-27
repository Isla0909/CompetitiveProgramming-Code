#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int cnt[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fill(cnt, cnt + n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
    }

    long long ans = 0;
    for (int d = 1; d <= n; ++d) {
      for (int m = d; m <= n; m += d) {
        if (cnt[m] && m + d <= n && cnt[m + d]) {
          ans += 1LL * cnt[m] * cnt[m + d];
        }
      }
    }

    cout << ans << "\n";
  }
  return 0;
}

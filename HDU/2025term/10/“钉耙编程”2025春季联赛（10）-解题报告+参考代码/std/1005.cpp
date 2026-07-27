#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int t, n, m;
    cin >> t >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());
    int total = accumulate(a.begin(), a.begin() + m, 0);

    if (total > t) {
      cout << "-1\n";
    } else {
      int remaining = t - total;
      cout << remaining / 40 << "\n";
    }
  }
  return 0;
}
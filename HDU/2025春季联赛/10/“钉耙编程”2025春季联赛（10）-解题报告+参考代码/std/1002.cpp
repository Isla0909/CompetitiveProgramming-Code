#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll T, n, m;

inline ll sum1(ll k) { return 1ll * k * (k + 1) / 2; }

inline ll sum2(ll k) { return 1ll * k * (k + 1) * (2 * k + 1) / 6; }

inline ll calc(ll m, ll p) {
  ll N = (m - p) / p;
  ll q = m - (N + 1) * p;
  ll ans = sum1(p + 1) - 1;
  // cout<<ans<<endl;
  if (q) {
    N++;
    ans += N * ((2 - N) * q + (N + (2 - N)) * sum1(q) + N * sum2(q));
    ans += sum1(N - 1) * (sum1(q + 1) - 1);
    // cout<<ans<<endl;
    N--;
    ans += N * ((q + 2 - N) * (p - q) + (q + 2) * (sum1(p) - sum1(q)) +
                N * (sum2(p) - sum2(q)));
    // cout<<ans<<endl;
    ans += sum1(N - 1) * (sum1(p + 1) - sum1(q + 1));
    // cout<<ans<<endl;
  } else {
    ans += N * ((2 - N) * p + (N + (2 - N)) * sum1(p) + N * sum2(p));
    ans += sum1(N - 1) * (sum1(p + 1) - 1);
  }
  return ans;
}

int main() {
  // freopen("1002.ans","w",stdout);
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    // ll ans=calc(m,n);
    ll ans = sum1(m + 1) - 1;
    for (int i = 1; i <= m; i++) {
      ans = max(ans, calc(m, i));
      // cout<<i<<" "<<calc(m,i)<<endl;
    }
    cout << ans << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int q = (n - k) / m + 1;
        int g = std::gcd(n, m);
        int L = n / g;

        long long ans = LLONG_MIN;

        for (int r = 0; r < g; ++r) {
            vector<long long> cyc(L);
            int idx = r;
            for (int i = 0; i < L; ++i) {
                cyc[i] = a[idx];
                idx += m;
                if (idx >= n) idx -= n;
            }

            long long cur = 0;
            for (int i = 0; i < q; ++i) cur += cyc[i];
            ans = max(ans, cur);
            for (int st = 1; st < L; ++st) {
                cur -= cyc[st - 1];
                cur += cyc[(st + q - 1) % L];
                ans = max(ans, cur);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

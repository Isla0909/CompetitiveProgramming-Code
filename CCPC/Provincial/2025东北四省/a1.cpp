#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> stk;
    map<int, int> f;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        while (stk.size() && a[stk.back()] >= a[i]) {
            stk.pop_back();
        }
        stk.push_back(i);

        map<int, int> nf;
        for (auto [g, c] : f) {
            nf[gcd(g, a[i])] += c;
        }
        f = move(nf);
        f[a[i]]++;

        int l = 0;
        for (auto [g, c] : f) {
            int r = l + c;
            auto it = lower_bound(stk.begin(), stk.end(), l);
            if (a[*it] == g) {
                ans += min(*it + 1, r) - l;
            }
            l = r;
        }
    }
    cout << ans << '\n';

    return 0;
}
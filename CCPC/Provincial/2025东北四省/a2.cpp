#include <bits/stdc++.h>
// #pragma GCC optimize(2)
#ifndef ONLINE_JUDGE
    #define Debug
#endif
#define multiple_test 0
#define int int64_t
const int MAXN = 1e6, N = MAXN + 10;
const int INF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;
using namespace std;

struct ST {
    vector<vector<int>> f, g;

    ST() {}
    ST(auto a, int n) {
        init(a, n);
    }

    void init(auto a, int n) {
        f.assign(n + 1, vector<int>(35));
        g.assign(n + 1, vector<int>(35));
        for(int i = 1; i <= n; i++) {
            f[i][0] = a[i];
            g[i][0] = a[i];
        }
        for(int j = 1; j <= 30; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }        
        }
    }

    int query_min(int x, int y) {
        int k = __lg(y - x + 1);
        return min(f[x][k], f[y - (1 << k) + 1][k]);
    }

    int query_gcd(int x, int y) {
        int k = __lg(y - x + 1);
        return __gcd(g[x][k], g[y - (1 << k) + 1][k]);
    }
};

inline void solve() {
    int n; cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mm = *max_element(a.begin() + 1, a.end());
    vector<int> pos(mm + 1);

    ST st(a, n);

    auto bl = [&](int x, int y, int k) {
        int l = x, r = y, res = k;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(st.query_min(mid, k) == a[k] && st.query_gcd(mid, k) == a[k]) {                
                r = mid - 1; res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    };

    auto br = [&](int x, int y, int k) {
        int l = x, r = y, res = k;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(st.query_min(k, mid) == a[k] && st.query_gcd(k, mid) == a[k]) {                
                l = mid + 1; res = mid;
            } else {
                r = mid - 1;
            }
        }
        return res;
    };

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int l = bl(pos[a[i]] + 1, i, i);
        int r = br(i, n, i);
        cerr << l << " " << r << "\n";
        pos[a[i]] = i;

        res += (i - l + 1) * (r - i + 1);
    }

    cout << res << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif 
    int t = 1; if(multiple_test) cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
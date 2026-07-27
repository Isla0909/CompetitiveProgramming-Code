// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int get(long long u) {
    if (u < 3) return u + 1;
    return get(u / 3) + (int(u % 3) + 1);
}

int get_query(long long l, long long r) {
    // cout << l << " " << r << '\n';
    if (r / 3 > l) return get_query(r / 3, r);
    if (r - l + 1 < 3) {
        int ans = 0;
        for (long long i = l; i <= r; ++i) ans = max(ans, get(i));
        return ans;
    }

    int ans = 0;
    while(r % 3 != 2) {
        ans = max(ans, get(r--));
    }
    while(l % 3 != 0) {
        ans = max(ans, get(l++));
    }

    return max(ans, get_query(l / 3, r / 3) + 3);
}

void xuly() {
    long long l, r;
    cin >> l >> r;
    cout << get_query(l, r) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.
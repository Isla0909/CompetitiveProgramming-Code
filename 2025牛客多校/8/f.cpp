#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int MASK[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
constexpr int inf = 1E9;

i64 G[1 << 7];

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    std::vector<std::string> str(n);
    for (int i = 0; i < n; i++) {
        std::cin >> str[i];
        for (int j = 0; j < m; j++) {
            a[i] |= MASK[str[i][j] - '0'] << (7 * j);
        }
    }
    
    std::vector<int> b(n), p(n);
    int ans = inf;
    
    auto dfs = [&](auto &&self, int i, int mask) {
        if (i == m - 1) {
            for (int j = 0; j < n; j++) {
                b[j] = a[j] & mask;
            }
            std::iota(p.begin(), p.end(), 0);
            std::sort(p.begin(), p.end(),
                [&](int i, int j) {
                    return b[i] < b[j];
                });
            i64 need = 0;
            bool ok = true;
            for (int l = 0, r = 0; l < n; l = r) {
                while (r < n && b[p[l]] == b[p[r]]) {
                    r++;
                }
                for (int j = l; j < r; j++) {
                    for (int k = l; k < j; k++) {
                        int x = str[p[j]][i] - '0';
                        int y = str[p[k]][i] - '0';
                        if (x == y) {
                            ok = false;
                            break;
                        }
                        if (x < y) {
                            std::swap(x, y);
                        }
                        need |= 1LL << (x * (x - 1) / 2 + y);
                    }
                    if (!ok) {
                        break;
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (!ok) {
                return;
            }
            for (int s = 0; s < (1 << 7); s++) {
                if ((G[s] & need) == need) {
                    ans = std::min(ans, __builtin_popcount(mask) + __builtin_popcount(s));
                }
            }
            return;
        }
        for (int s = 0; s < (1 << 7); s++) {
            self(self, i + 1, mask | s << (7 * i));
        }
    };
    dfs(dfs, 0, 0);
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int s = 0; s < (1 << 7); s++) {
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < i; j++) {
                if ((MASK[i] & s) != (MASK[j] & s)) {
                    G[s] |= 1LL << (i * (i - 1) / 2 + j);
                }
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

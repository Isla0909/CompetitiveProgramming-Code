#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const long long N0 = (long long)1e12;

    while (T--) {
        long long x, y, k;
        cin >> x >> y >> k;

        if (y == 1) { // 一次就删光
            cout << -1 << "\n";
            continue;
        }

        // 1. 先算每次操作后的长度
        long long n = N0;
        vector<long long> len;
        len.reserve(x + 1);
        len.push_back(n);
        for (int i = 1; i <= x; ++i) {
            if (n == 0) {
                len.push_back(0);
                continue;
            }
            long long del = n / y;
            n -= del;
            len.push_back(n);
        }

        if (k > len[x]) {
            cout << -1 << "\n";
            continue;
        }

        // 2. 从后往前倒推位置
        long long pos = k;
        for (int i = x; i >= 1; --i) {
            long long block = (pos - 1) / (y - 1);
            long long offset = (pos - 1) % (y - 1);
            pos = block * y + (offset + 1);
            // pos 一定 <= len[i-1]，不用特判
        }

        cout << pos << "\n"; // 原序列里的数就是它的下标
    }
    return 0;
}

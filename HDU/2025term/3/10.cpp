#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        long long x_min = 1e18, x_max = -1e18;
        long long y_min = 1e18, y_max = -1e18;
        // 处理客户坐标，统计极值
        for (int i = 0; i < n; ++i) {
            long long x, y;
            cin >> x >> y;
            long long nx = x + y, ny = x - y;
            x_min = min(x_min, nx);
            x_max = max(x_max, nx);
            y_min = min(y_min, ny);
            y_max = max(y_max, ny);
        }
        long long res = 1e18;
        // 处理配送站，计算最小最大距离
        for (int i = 0; i < m; ++i) {
            long long a, b;
            cin >> a >> b;
            long long na = a + b, nb = a - b;
            long long dx = max(na - x_min, x_max - na);
            long long dy = max(nb - y_min, y_max - nb);
            res = min(res, max(dx, dy));
        }
        cout << res << '\n';
    }
    return 0;
}
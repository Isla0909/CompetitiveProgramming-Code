#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// O(sqrt(i)) 求约数个数
int countDivisors(int i) {
    int cnt = 0;
    int limit = sqrt(i);
    for (int j = 1; j <= limit; ++j) {
        if (i % j == 0) {
            if (j * j == i) cnt += 1;
            else cnt += 2;
        }
    }
    return cnt;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> degrees;
    degrees.reserve(n);

    for (int i = 1; i <= n; ++i) {
        int d_i = countDivisors(i); // 这里是最大的时间开销
        int m_i = n / i;
        degrees.push_back(d_i + m_i - 2);
    }

    // 将 nth_element 改为全排序
    // O(n log n)
    sort(degrees.begin(), degrees.end(), greater<int>());

    // 排序后，第 k 大的就是索引为 k-1 的元素
    cout << degrees[k - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll sum_range(ll a, ll b) {
    // 计算 [a, b] 的和模 MOD
    if (a > b) return 0;
    ll len = (b - a + 1) % MOD;
    ll sum = (a % MOD + b % MOD) % MOD;
    sum = sum * len % MOD;
    sum = sum * ((MOD + 1) / 2) % MOD; // 除以2，使用逆元
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    ll n;
    cin >> n;
    
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 0;
    ll sqrt_n = sqrt(n);
    
    // 处理 b ≤ sqrt(n) 的情况
    for (ll b = 2; b <= sqrt_n; ++b) {
        ll k_max = (n - 1) / b;
        if (k_max < 1) continue;
        
        // 计算第一部分：k 从 1 到 k_max-1
        ll sum1 = (k_max - 1) % MOD * (b - 1) % MOD;
        
        // 计算第二部分：k = k_max
        ll r = min(n, k_max * b + b - 1);
        ll l = k_max * b + 1;
        ll sum2 = (r >= l) ? (r - l + 1) % MOD : 0;
        
        ans = (ans + sum1 + sum2) % MOD;
    }
    
    // 处理 b > sqrt(n) 的情况
    for (ll k = 1; k <= sqrt_n; ++k) {
        ll L = (n - 1) / (k + 1) + 1;
        ll R = (n - 1) / k;
        
        // 确保 L 和 R 在有效范围内
        L = max(L, sqrt_n + 1);
        R = min(R, n - 1);
        
        if (L > R) continue;
        
        // 计算这部分的贡献
        ll len = (R - L + 1) % MOD;
        ll sum_b = sum_range(L, R);
        
        // 贡献 = (k-1) * (b-1) 的和 + min((k+1)*b -1, n) - k*b 的和
        ll part1 = (k - 1) % MOD * ((sum_range(L, R) - len + MOD) % MOD) % MOD;
        
        // 计算第二部分：min((k+1)*b -1, n) - k*b = b-1 (当 (k+1)*b -1 ≤ n)
        // 否则为 n - k*b
        ll threshold = (n + 1) / (k + 1);
        if (threshold < L) {
            // 所有 b 都满足 (k+1)*b -1 > n
            ll part2 = (n % MOD * len % MOD - k % MOD * sum_b % MOD + MOD) % MOD;
            ans = (ans + part1 + part2) % MOD;
        } else if (threshold > R) {
            // 所有 b 都满足 (k+1)*b -1 ≤ n
            ll part2 = (sum_b - len + MOD) % MOD;
            ans = (ans + part1 + part2) % MOD;
        } else {
            // 需要分割计算
            ll len1 = (threshold - L + 1) % MOD;
            ll sum_b1 = sum_range(L, threshold);
            ll part2_1 = (sum_b1 - len1 + MOD) % MOD;
            
            ll len2 = (R - threshold) % MOD;
            ll sum_b2 = sum_range(threshold + 1, R);
            ll part2_2 = (n % MOD * len2 % MOD - k % MOD * sum_b2 % MOD + MOD) % MOD;
            
            ll part2 = (part2_1 + part2_2) % MOD;
            ans = (ans + part1 + part2) % MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}
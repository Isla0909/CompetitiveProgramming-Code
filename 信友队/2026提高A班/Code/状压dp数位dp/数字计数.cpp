#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto get = [&](i64 n) -> vector<i64>
    {
        vector<i64> cnt(10);
        for(i64 p = 1; p <= n; p *= 10)
        {
            i64 low = n % p;
            i64 cur = (n / p) % 10;
            i64 high = n / (p * 10);

            for(int d = 1; d <= 9; d ++)
            {
                cnt[d] += high * p;
                if(cur > d) cnt[d] += p;
                else if(cur == d) cnt[d] += low + 1;
            }

            if(high == 0) continue;
            cnt[0] += (high - 1) * p;
            if(cur > 0) cnt[0] += p;
            else if(cur == 0) cnt[0] += low + 1;
        }
        return cnt;
    };
    
    i64 l, r; cin >>l >>r;
    auto R = get(r), L = get(l - 1);
    for(int i = 0; i <= 9; i ++)
        cout <<R[i] - L[i] <<" \n"[i == 9];
    
    return 0;
}
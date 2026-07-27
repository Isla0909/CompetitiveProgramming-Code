#include "bits/stdc++.h"
using namespace std;
using i64=long long;

int main(){
  
    cin.tie(0) -> sync_with_stdio(false);
  
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> x[i];
        cin >> y[i];
    }

    map<pair<int, int>, i64> mp;
    i64 ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            int dx = x[i] - x[j], dy = y[i] - y[j];
        
            if (dx < 0) 
            {
                dx = -dx;
                dy = -dy;
            }else if (dx == 0) dy = 1;
                
            int gcd = std::__gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;

            if(mp.count({dx, dy})) {
                ans += mp[{dx, dy}];
            }
            mp[{dx, dy}]++;
        }
    }

    map<pair<i64, i64>, i64> v;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            i64 midx = (x[i] + x[j]);
            i64 midy = (y[i] + y[j]);

            if(v.count({midx, midy})) {
                ans -= v[{midx, midy}];
            }
            v[{midx, midy}]++;
        }
    }
    cout << ans << "\n";
}
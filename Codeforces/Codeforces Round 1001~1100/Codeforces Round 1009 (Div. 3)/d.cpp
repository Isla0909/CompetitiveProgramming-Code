#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main() 
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while (T --) 
    {
        int n, m; cin >>n >>m;
        vector<int> x(n), r(n);
        for(int i = 0; i < n; i ++) cin >>x[i];
        for(int i = 0; i < n; i ++) cin >>r[i];

        int max_r = 0;
        for(auto x : r) max_r = max(max_r, x);
        vector<vector<pii>> line(max_r + 1);

        for(int i = 0; i < n; i ++) 
        {
            int xi = x[i], ri = r[i];
            for(int k = 0; k <= ri; k++) 
            {
                ll val = (ll)ri * ri - (ll)k * k;

                int s = 0;
                int l = 0, h = ri;
                while(l <= h) 
                {
                    int mid = l + h >> 1;
                    ll x = (ll)mid * mid;
                    if (x <= val) 
                    {
                        s = mid;
                        l = mid + 1;
                    } 
                    else h = mid - 1;
                }

                int left = xi - s;
                int right = xi + s;
                line[k].emplace_back(left, 1);
                line[k].emplace_back(right + 1, -1);
            }
        }

        ll ans = 0;
        for(int k = 0; k <= max_r; k ++) 
        {
            auto &v = line[k];
            if(v.empty()) continue;

            sort(v.begin(), v.end());
            
            int cur = 0;
            ll cnt = 0; int start;
            for(int j = 0; j < v.size(); j ++) 
            {
                int x = v[j].ff, add = v[j].se;

                if (cur == 0 && add == 1) start = x;
                else if(cur == 1 && add == -1) 
                	cnt += (x - 1) - start + 1;

                cur += add;
            }
            if(k == 0) ans += cnt;  
            else ans += cnt * 2;
        }
        cout <<ans <<endl;
    }
    return 0;
}
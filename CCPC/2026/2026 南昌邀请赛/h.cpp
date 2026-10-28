#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, A, B; cin >>n >>m >>A >>B;
    vector<int> u(n), d(n), c(n);
    for(int i = 0; i < n; i ++)
        cin >>u[i] >>d[i] >>c[i];

    int state1 = 1 << n / 2;
    vector<i64> su1(state1), sd1(state1), sc1(state1);  
    for(int s = 0; s < (1 << n / 2); s ++)
    {
        i64 s1 = 0, s2 = 0, s3 = 0;
        for(int j = 0; j < n / 2; j ++)
            if(s >> j & 1)
            {
                s1 += u[j];
                s2 += d[j];
                s3 += c[j];
            }
        su1[s] = s1, sd1[s] = s2, sc1[s] = s3;
    }

    int state2 = 1 << (n - n / 2);
    vector<i64> su2(state2), sd2(state2), sc2(state2);  
    for(int s = 0; s < (1 << (n - n / 2)); s ++)
    {
        i64 s1 = 0, s2 = 0, s3 = 0;
        for(int j = 0; j < n - n / 2; j ++)
            if(s >> j & 1)
            {
                s1 += u[n / 2 + j];
                s2 += d[n / 2 + j];
                s3 += c[n / 2 + j];
            }
        su2[s] = s1, sd2[s] = s2, sc2[s] = s3;
    }

    i64 ans = -1;
    for(int s = 1; s < 1 << n; s ++)
    {
        int a = s >> (n / 2), b = s & ((1 << n / 2) - 1);
        i64 p = su2[a] + su1[b], q = sd2[a] + sd1[b], w = sc2[a] + sc1[b];
        if(w > m || p * B != q * A) continue;
        ans = max(ans, p);
    }
    cout <<ans <<endl;
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >>n >>q;
    string s; cin >>s;
    s = " " + s;
    vector<array<int, 26>> pre(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x = s[i] - 'a';
        for(int j = 0; j < 26; j ++)
            pre[i][j] = pre[i - 1][j] + (x == j);
    }

    while(q --)
    {
        int l, r; cin >>l >>r;
        int ans = 1;
        for(int j = 0; j < 26; j ++)
            ans = max(ans, pre[r][j] - pre[l - 1][j]);
        cout <<ans <<endl;
    }
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;;
    while(T --)
    {
        i64 n; cin >>n;
        if(n & 1) cout <<0 <<endl;
        else cout <<n / 2 * (n - 2) <<endl;
    }
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f;

int f[N][6][6][6];

typedef pair<int, int> pii;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

int calc(int x, int y)
{
    if(x == 0 || y == 0) return 0;
    return (y - x + 5) % 5;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >>n;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= 5; j ++)
            for(int s = 0; s <= 5; s ++)
                for(int e = 0; e <= 5; e ++)
                    f[i][j][s][e] = -INF;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >>a[i];

    f[1][a[1]][0][0] = f[1][0][a[1]][a[1]] = 0;
    for(int i = 2; i <= n; i ++)
    {
        for(int j = 0; j < 6; j ++)
            for(int s = 0; s < 6; s ++)
                for(int e = 0; e < 6; e ++)
                {
                    if(f[i - 1][j][s][e] == -INF) continue;
                    //1队
                    f[i][a[i]][s][e] = max(f[i][a[i]][s][e], f[i - 1][j][s][e] - calc(j, s) + calc(j, a[i]) + calc(a[i], s));
                    //2队
                    if(s == 0) f[i][j][a[i]][a[i]] = max(f[i][j][a[i]][a[i]], f[i - 1][j][0][0] + calc(j, a[i]));
                    else f[i][j][s][a[i]] = max(f[i][j][s][a[i]], f[i - 1][j][s][e] + calc(e, a[i]));
                }
    }
    int ans = 0;
    for(int j = 0; j < 6; j ++)
        for(int s = 0; s < 6; s ++)
            for(int e = 0; e < 6; e ++)
                ans = max(ans, f[n][j][s][e]);
    cout <<ans + n <<endl;
    return 0;
}
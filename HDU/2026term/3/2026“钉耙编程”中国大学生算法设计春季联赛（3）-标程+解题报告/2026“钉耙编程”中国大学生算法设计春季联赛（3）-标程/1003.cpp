#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

int dp[maxn][10][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 9; j++)
                dp[i][j][0] = dp[i][j][1] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            for (int j = 0; j <= 9; j++)
                dp[i][j][0] = dp[i - 1][j][0], dp[i][j][1] = dp[i - 1][j][1];
            for (int j = x * y; j <= 9; j++)
            {
                if (x * y == 4)
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - x * y][0] + z);
                else
                {
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - x * y][0] + z);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - x * y][1] + z);
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= 9; j++)
            ans = max({ans, dp[n][j][0], dp[n][j][1]});
        cout << ans << endl;
    }
}

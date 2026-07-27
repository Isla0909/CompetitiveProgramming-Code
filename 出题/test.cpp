#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
struct node{
    int id, x;
}a[N]; 
int n, ans;
bool cmp(node a, node b) //用于排序
{
    return a.x > b.x;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);

    cin >> n;
    int sum = n * (n + 1) / 2; //计算总和
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        sum -= a[i].id;
        ans = max(ans, sum - a[i].id);
    }
    cout << ans;
    return 0;
}

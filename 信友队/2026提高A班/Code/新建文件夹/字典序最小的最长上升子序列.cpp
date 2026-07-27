#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    /*
        f[i] = 以 a[i] 开头，往后最多能组成多长的上升子序列
    */
    vector<int> f(n + 1);
    vector<int> d;

    for(int i = n; i >= 1; i--)
    {
        int val = -a[i];

        int pos = lower_bound(d.begin(), d.end(), val) - d.begin();

        if(pos == d.size()) d.push_back(val);
        else d[pos] = val;

        f[i] = pos + 1;
    }

    int L = d.size();

    /*
        bucket[k] 存所有 f[i] == k 的下标
    */
    vector<vector<int>> bucket(L + 1);

    for(int i = 1; i <= n; i++)
    {
        bucket[f[i]].push_back(i);
    }

    /*
        小根堆：
        第一关键字：a[i] 小的优先
        第二关键字：下标 i 小的优先
    */
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;

    vector<int> ans;

    int pos = 0;
    int last = -INF;

    for(int need = L; need >= 1; need--)
    {
        /*
            加入所有 f[i] == need 的位置。

            因为 need 是从 L 到 1 递减的，
            所以堆里会一直保留 f[i] >= 当前 need 的位置。
        */
        for(int id : bucket[need])
        {
            q.push({a[id], id});
        }

        /*
            删除不合法的位置：
            1. 下标必须在上一次选择的位置之后
            2. 值必须比上一次选择的值大
        */
        while(!q.empty() && (q.top().second <= pos || q.top().first <= last))
        {
            q.pop();
        }

        auto [val, id] = q.top();

        ans.push_back(val);
        pos = id;
        last = val;
    }

    for(int i = 0; i < ans.size(); i++)
    {
        if(i) cout << ' ';
        cout << ans[i];
    }

    return 0;
}
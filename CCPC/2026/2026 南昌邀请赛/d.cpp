#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >>n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++)
        for(int j = i + 1; j <= n; j ++)
            adj[i].push_back(j);

    vector<vector<int>> ans;
    for(int i = 1; i < n; i ++)
    {
        while(adj[i].size())
        {
            int now = i;
            vector<int> p{1};
            if(now != 1) p.push_back(i);

            while(now <= n)
            {
                if(!adj[now].size())
                {
                    if(now != n) p.push_back(n);
                    ans.push_back(p);
                    break;
                }
                int to = adj[now].back(); adj[now].pop_back();
                p.push_back(to);
                now = to;
            }
        }
    }

    cout <<ans.size() <<endl;
    for(auto v : ans)
        tell(0, v);
    return 0;
}
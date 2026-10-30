#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f;

i64 query(vector<int> &v)
{
    cout <<"? " <<v.size();
    for(auto x : v)
        cout <<" " <<x;
    cout <<endl;

    i64 x; cin >>x;
    return x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >>n;
    vector<array<int, 2>> g;
    for(int i = 1; i <= n; i ++)
        g.push_back({i, i});

    i64 res = 0;
    while(g.size() != 1)
    {
        vector<int> v;
        for(int i = 0; i < g.size(); i += 2)
            for(int j = g[i][0]; j <= g[i][1]; j ++)
                v.push_back(j);

        i64 val = query(v);
        vector<array<int, 2>> ng;

        if(val > 0)
        {
            res = val;
            for(int i = 0; i < g.size(); i += 2)
                ng.push_back(g[i]);
        }
        else if(res > 0)
        {
            for(int i = 1; i < g.size(); i += 2)
                ng.push_back(g[i]);
        }
        else
        {
            for(int i = 0; i < g.size(); i += 2)
            {
                int r = g[i][1];
                if(i + 1 < g.size()) r = g[i + 1][1];

                ng.push_back({g[i][0], r});
            }
        }
        swap(g, ng);
    }
    cout <<"! " <<res + 1 <<endl;
    return 0;
}
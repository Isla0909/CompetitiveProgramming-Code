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
    
    auto check = [&](int x) -> i64
    {
        vector<int> v(x);
        iota(v.begin(), v.end(), 1);

        i64 val = query(v);
        return val;
    };
    
    int l = 0, r = n + 1;
    vector<i64> res;
    while(l + 1 != r)
    {
        int mid = l + r >> 1;
        i64 val = check(mid);
        res.push_back(val);
        if(val == 0) l = mid;
        else r = mid;
    }

    while(!res.back()) res.pop_back();

    if(r == n + 1)
    {
        assert(res.empty());
        cout <<"! " <<1 <<endl;
    }
    else cout <<"! " <<res.back() + 1 <<endl;
    return 0;
}
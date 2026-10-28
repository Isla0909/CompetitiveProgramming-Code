#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

typedef pair<int, int> pii;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; i64 k; cin >>n >>m >>k;
    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >>a[i];

    sort(a.begin() + 1, a.end());

    vector<pair<i64, i64>> seg;
    auto check = [&](i64 x) -> bool
    {
        seg.clear();
        seg.reserve(n);
        for(int i = 1; i <= n; i ++)
        {
            i64 l = max(0LL, a[i] - x), r = min(k, a[i] + x);
            seg.emplace_back(l, r);
        }

        if(seg[0].first != 0) return false;

        i64 ed = -1; int cnt = 0;
        for(int i = 0, j = -1; i < n && ed != k; i ++)
        {
            if(seg[i].first > ed + 1) break;

            while(j + 1 < n && seg[j + 1].first <= ed + 1) j ++;

            ed = seg[j].second;
            cnt ++;
            i = j;
        }
        return ed == k && cnt <= m;
    };

    i64 l = -1, r = 1e12 + 1;
    while(l + 1 != r)
    {
        i64 mid = l + r >> 1LL;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout <<r <<endl;
    return 0;
}
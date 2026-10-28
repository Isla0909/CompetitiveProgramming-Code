#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;
    while(T --)
    {
        int n, m, r, g, b; cin >>n >>m >>r >>g >>b;
        vector<pii> seg;
        for(int i = 0; i < m; i ++)
        {
            int l, r; cin >>l >>r;
            seg.emplace_back(l, r);
        }
        sort(seg.begin(), seg.end(), [&](auto &a, auto &b)
        {
            return a.second - a.first > b.second - b.first;
        });

        vector<pii> v{{r, 1}, {g, 2}, {b, 3}};

        bool f = true;
        vector<int> ans(n + 1);
        for(auto [l, r] : seg)
        {
            sort(v.begin(), v.end());
            if(r - l + 1 > v[1].first + v[2].first)
            {
                f = false;
                break;
            }

            if(v[0].first > r - l + 1)
            {
                for(int i = l; i <= r; i ++)
                    ans[i] = v[0].second;
                v[0].first -= r - l + 1;
            }
            else if(v[0].first + v[2].first >= r - l + 1)
            {
                //cout <<"enter 2" <<endl;
                auto [c0, col0] = v[0];  auto [c2, col2] = v[2];
                for(int i = l; i <= r; i ++)
                {
                    if(c0)
                    {
                        ans[i] = col0;
                        c0 --;
                    }
                    else
                    {
                        ans[i] = col2;
                        c2 --;
                    }
                }
                //cout <<c2 <<" " <<col2 <<endl;
                vector<pii> nv{v[1], {c2, col2}};
                swap(nv, v);
            }
            else
            {
                auto [cnt, col] = v.back(); v.pop_back();
                for(int i = l; i <= r; i ++)
                {
                    ans[i] = col;

                    cnt --;
                    if(!cnt)
                    {
                        cnt = v.back().first, col = v.back().second;
                        v.pop_back();
                    }
                }
                v.emplace_back(cnt, col);
            }
            
        }
        if(!f) cout <<-1 <<endl;
        else
        {
            
            for(int i = 1; i <= n; i ++)
            {
                if(!ans[i])
                {
                    auto [cnt, col] = v.back(); v.pop_back();
                    if(!cnt)
                    {
                        cnt = v.back().first;
                        col = v.back().second;
                    }
                    cnt --;
                    ans[i] = col;

                    if(cnt) v.emplace_back(cnt, col);
                }
            }

            string s = "";
            for(int i = 1; i <= n; i ++)
            {
                char c = 'R';
                if(ans[i] == 2) c = 'G';
                else if(ans[i] == 3) c = 'B';
                s.push_back(c);
            }
            cout <<s <<endl;
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#include <ctime>
#include <random>
#include <chrono>
#include <functional>
#include <cassert>
#include <iomanip>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct DSU
{
    vector<int> p, siz;

    void initial(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);

        siz.assign(n + 1, 1);
    }

    DSU(int n)
    {
        initial(n);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void merge(int a, int b)
    {
        a = find(a), b = find(b);
        if(a == b) return ;

        siz[a] += siz[b];
        p[b] = a;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};

int dis(pii a, pii b)
{
    return abs(a.ff - b.ff) + abs(a.se - b.se);
}

struct cxy
{
    int d;
    int a, b;

    bool operator>(const cxy &t) const
    {
        return d > t.d;
    }
};

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int n, m; cin >>n >>m;
    vector<pii> p;
    for(int i = 0; i < n; i ++)
    {
        int x, y; cin >>x >>y;
        p.push_back({x, y});
    } 

    DSU dsu(n + m);
    priority_queue <cxy, vector<cxy>, greater<cxy>> q;

    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n; j ++)
            q.push({dis(p[i], p[j]), i, j});

    while(m --)
    {
        int op; cin >>op;
        if(op == 1)
        {
            int x, y; cin >>x >>y;
            p.push_back({x, y});
            for(int i = 0; i < n; i ++)
                q.push({dis(p[i], p[n]), i, n});
            n ++;
        }
        else if(op == 2)
        {
            int ans = -1;
            while(q.size())
            {
                auto [d, u, v] = q.top(); q.pop();
                if(!dsu.same(u, v))
                {
                    ans = d;
                    dsu.merge(u, v);
                    while(q.size())
                    {
                        auto [dist, a, b] = q.top();
                        if(dist != ans) break;
                        q.pop();
                        dsu.merge(a, b);
                    }
                    break;
                }
            }
            cout <<ans <<endl;
        }
        else
        {
            int u, v; cin >>u >>v;
            u --, v --;
            if(dsu.same(u, v)) cout <<"Yes" <<endl;
            else cout <<"No" <<endl;
        }
    }

    return 0;
}
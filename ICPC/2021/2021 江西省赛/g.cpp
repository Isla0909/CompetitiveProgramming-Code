#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 10, INF = 0x3f3f3f3f;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

vector<int> minp, primes;
vector<int> to;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    to.assign(n + 1, 0);
    primes.clear();
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(p == minp[i]) break;
        }
    }
    for(int i = 0; i < primes.size(); i ++)
        to[primes[i]] = i + 1;
}

int cnt[N], st[N];
vector<vector<int>> fac(1000010);

void add(int x, int &res)
{
    for(auto p : fac[x])
    {
        cnt[to[p]] ++;
        res = max(res, cnt[to[p]]);
    }
}

void del(int x)
{
    for(auto p : fac[x])
        cnt[to[p]] --;
}

void solve2()
{
    int n, q; cin >>n >>q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >>a[i];

    vector<array<int, 3>> query(q + 1);
    for(int i = 1; i <= q; i ++)
    {
        int l, r; cin >>l >>r;
        query[i] = {l, r, i};
    } 
    int len = n / min(n, int(sqrt(q)));
    vector<int> bel(n + 1);
    for(int i = 1; i <= n; i ++)
        bel[i] = (i - 1) / len + 1;


    sort(query.begin() + 1, query.end(), [&](auto a, auto b)
    {
        if(bel[a[0]] != bel[b[0]]) return bel[a[0]] < bel[b[0]];
        return a[1] < b[1];
    });

    vector<int> ans(q + 1);
    for(int x = 1; x <= q;)
    {
        int y = x;
        while(y <= q && bel[query[y][0]] == bel[query[x][0]]) y ++;

        int R = min(bel[query[x][0]] * len, n);
        //块内
        while(x < y && query[x][1] <= R)
        {
            int res = 0;
            auto [l, r, id] = query[x];
            for(int k = l; k <= r; k ++) add(a[k], res);
            ans[id] = res;
            for(int k = l; k <= r; k ++) del(a[k]);
            x ++;
        }
        //块外
        int res = 0;
        int i = R, j = R + 1;
        while(x < y)
        {
            auto [l, r, id] = query[x];
            while(i < r) add(a[++ i], res);
            int backup = res;
            while(j > l) add(a[-- j], res);
            ans[id] = res;

            while(j <= R) del(a[j ++]);
            res = backup;
            x ++;
        }
        memset(cnt, 0, sizeof cnt);
    }

    for(int i = 1; i <= q; i ++)
        cout <<ans[i] <<endl;
}

void solve1()
{
    int n, q; cin >>n >>q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >>a[i];

    vector<array<int, 3>> query(q + 1);
    for(int i = 1; i <= q; i ++)
    {
        int l, r; cin >>l >>r;
        query[i] = {l, r, i};
    }

    int len = n / min(n, int(sqrt(q)));
    vector<int> bel(n + 1);
    for(int i = 1; i <= n; i ++)
        bel[i] = (i - 1) / len + 1;

    sort(query.begin() + 1, query.end(), [&](auto a, auto b)
    {
        if(bel[a[0]] != bel[b[0]]) return bel[a[0]] < bel[b[0]];
        if(bel[a[0]] & 1) return a[1] < b[1];
        return a[1] > b[1];
    });

    vector<int> ans(q + 1);
    multiset<int> S; S.insert(0);
    int l = 1, r = 0, val = 0;
    auto add = [&](int x) -> void
    {
        while(x != 1)
        {
            int p = minp[x];
            S.extract(st[p]);
            st[p] ++; S.insert(st[p]);
            while(x % p == 0) x /= p;
        }
    };

    auto del = [&](int x) -> void
    {
        while(x != 1)
        {
            int p = minp[x];
            S.extract(st[p]);
            st[p] --; S.insert(st[p]);
            while(x % p == 0) x /= p;
        }
    };

    for(int i = 1; i <= q; i ++)
    {
        auto [ql, qr, id] = query[i];
        while(l > ql) add(a[-- l]);
        while(r < qr) add(a[++ r]);
        while(l < ql) del(a[l ++]);
        while(r > qr) del(a[r --]);
        ans[id] = *S.rbegin();
    }
    for(int i = 1; i <= q; i ++)
        cout <<ans[i] <<endl;

    for(int i = 1; i <= n; i ++)
    {
        int x = a[i];
        while(x != 1)
        {
            int p = minp[x];
            st[p] = 0;
            while(x % p == 0) x /= p;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1e6);

    for(int i = 2; i <= 1000000; i ++)
    {
        int x = i;
        while(x != 1)
        {
            int p = minp[x];
            fac[i].push_back(p);
            while(x % p == 0) x /= p;
        }
    }

    int T; cin >>T;
    if(T <= 233)
    {
        while(T --) {
            solve2();
        }
    }
    else
    {
        while(T --) {
            solve1();
        }
    }
    return 0;
}
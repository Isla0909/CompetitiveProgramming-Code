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
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int p[N], d[N];

void tell(int w[], int n)
{
    for(int i = 1; i <= n; i ++)
        cout <<w[i] <<" \n"[i == n];
}

int find(int x)
{
    if(x != p[x])
    {
        int u = p[x];
        p[x] = find(p[x]);
        d[x] ^= d[u];
    }
    return p[x];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int n, m; cin >>n >>m;
    for(int i = 1; i <= n; i ++)
    {
        p[i] = i;
        d[i] = 0;
    }

    bool f = 1;
    for(int i = 0; i < m; i ++)
    {
        int a, b, c; cin >>a >>b >>c;

        int pa = find(a), pb = find(b);
        if(pa == pb)
        {
            if((d[a] ^ d[b]) != c) f = 0;
        }
        else
        {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ c;
        }
    }
    if(!f) cout <<-1 <<endl;
    else
    {
        for(int i = 1; i <= n; i ++)
            find(i);

        for(int i = 1; i <= n; i ++)
            cout <<d[i] <<" ";
    }
    return 0;
}
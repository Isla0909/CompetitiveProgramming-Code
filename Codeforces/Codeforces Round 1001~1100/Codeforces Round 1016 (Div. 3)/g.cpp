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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, M = 31 * N, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int trie[M][2], cnt[M];
int idx;

int new_node()
{
    int x = ++ idx;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void initial()
{
    idx = 0;
    new_node();
}

void insert(int x, int c)
{
    int p = 1;
    for(int i = 30; i >= 0; i --)
    {
        int &s = trie[p][x >> i & 1];
        if(!s) s = new_node();

        p = s;
        cnt[p] += c;
    }
}

int query(int x)
{
    int p = 1, res = 0;
    for(int i = 30; i >= 0; i --)
    {
        int c = x >> i & 1;
        if(cnt[trie[p][c ^ 1]])//尽可能往大去走
        {
            c ^= 1;
            res |= 1 << i;
        }
        p = trie[p][c];
    }
    return res;
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        initial();

        int n, k; cin >>n >>k;
        vector<int> a(n);
        for(auto &x : a) cin >>x;

        int ans = n + 1;
        for(int i = 0, j = 0; i < n; i ++)
        {
            insert(a[i], 1);
            while(j <= i && query(a[i]) >= k)
            {
                ans = min(ans, i - j + 1);
                insert(a[j], -1);
                j ++;
            }
        }
        if(ans > n) cout <<-1 <<endl;
        else cout <<ans <<endl;
    }
    return 0;
}
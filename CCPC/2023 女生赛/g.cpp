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
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct cxy
{
    int h, a, b, c, d, e, w;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >>n >>m >>k;
    queue<cxy> q1, q2;
    for(int i = 0; i < n; i ++)
    {
        int h, a, b, c, d, e, w; cin >>h >>a >>b >>c >>d >>e >>w;
        q1.push({h, a, b, c, d, e, w});
    }
    for(int i = 0; i < m; i ++)
    {
        int h, a, b, c, d, e, w; cin >>h >>a >>b >>c >>d >>e >>w;
        q2.push({h, a, b, c, d, e, w});
    }

    int s = 1; k >>= 1; int f = -1;
    int cnt1 = 0, cnt2 = 0;
    while(k --)
    {
        auto &[h1, a1, b1, c1, d1, e1, w1] = q1.front();
        auto &[h2, a2, b2, c2, d2, e2, w2] = q2.front();
        if(s & 1)
        {
            int x = max(max(0, a1 - c2), max(0, b1 - d2));
            if(cnt1 >= e1 && w1 > x)//大招
            {
                cnt1 = 0;
                h2 -= w1;
            }
            else
            {
                cnt1 ++;
                h2 -= x;
            }
            if(h2 <= 0)
            {
                q2.pop();
                cnt2 = 0;
            }
        }
        else
        {
            int x = max(max(0, a2 - c1), max(0, b2 - d1));
            if(cnt2 >= e2 && w2 > x)//大招
            {
                cnt2 = 0;
                h1 -= w2;
            }
            else
            {
                cnt2 ++;
                h1 -= x;
            }
            if(h1 <= 0)
            {
                cnt1 = 0;
                q1.pop();
            }
        }

        if(!q1.size())
        {
            f = 2;
            break;
        }
        if(!q1.size())
        {
            f = 1;
            break;
        }
        s ^= 1;
    }
    if(f == -1) cout <<"Draw" <<endl;
    else cout <<(f == 1 ? "Alice" : "Bob") <<endl;
    return 0;
}
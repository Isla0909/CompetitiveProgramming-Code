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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

//mex(S) = k
//S = {0, 1, 2, 3, ..., k - 1}

//排列
//1.n个数两两不相同
//2.存在唯一的映射关系
//3 1 2
//1 2 3

//k = (len + 1) / 2
//第 k 小 

//你想要mex > med 就一定有 mex > med的最小值
//med 最小是 k - 1
//mex > k - 1   ->   mex >= k
//{0, 1, 2, 3, ... k - 1}  -> med = k - 1
//mex包含了0 - k - 1, 那么 mex >= k, 就有 mex > med (因为med = k - 1)

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector<int> p(n + 1), pos(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            cin >>p[i];
            pos[p[i]] = i;
        }

        auto calc = [&](int L, int R, int len) -> i64
        {
            if(len > n) return 0;

            int l = max(1, R - len + 1);
            int r = min(L, n - len + 1);

            if(l > r) return 0;

            return r - l + 1;
        };

        i64 ans = 0;

        int L = INF, R = -INF;

        for(int k = 1; k <= (n + 1) / 2; k ++)
        {
            int x = k - 1;

            L = min(L, pos[x]);
            R = max(R, pos[x]);

            ans += calc(L, R, 2 * k - 1);
            ans += calc(L, R, 2 * k);
        }
        cout <<ans <<endl;
    }

    return 0;
}
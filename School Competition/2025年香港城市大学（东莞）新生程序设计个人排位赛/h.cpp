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

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector g(3, vector<char> (n + 1));
        for(int i = 0; i < 3; i ++)
            for(int j = 1; j <= n; j ++)
                cin >>g[i][j];

        auto count = [&](int x) -> i32
        {
            int c = 0;
            for(int i = 0; i < 3; i ++)
                c += (g[i][x] == '1');
            return c;
        };

        vector f(n + 1, vector<int>(1 << 3));
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 0; j < (1 << 3); j ++)
            {
                
                bool h = 1;
                for(int k = 0; k < 3; k ++)
                {
                    if((j >> k & 1) && g[k][i] == '0')
                    {
                        h = 0;
                        break;
                    }
                }
                
                //无法补课
                if(__builtin_popcount(j) < 2 || count(i) < 2 || !h)
                {
                    f[i][0] = *max_element(f[i - 1].begin(), f[i - 1].end());
                    continue;
                }

                //补课
                if(__builtin_popcount(j) == 2)
                {
                    for(int u = 0; u < (1 << 3); u ++)
                        if(j != u) f[i][j] = max(f[i][j], f[i - 1][u] + 1);
                }
                else
                {
                    for(int u = 0; u < (1 << 3); u ++)
                        f[i][j] = max(f[i][j], f[i - 1][u] + 1);
                }
            }
        }
        cout <<*max_element(f[n].begin(), f[n].end()) <<endl;
    }

	return 0;
}
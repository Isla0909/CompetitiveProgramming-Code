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
        vector<vector<pii>> v(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            int x, y; cin >>x >>y;
            v[x].emplace_back(y, i);
        }
        vector<int> ans;
        for(int i = n; i >= 1; i --)
        {
            sort(v[i].begin(), v[i].end(), greater<>());

            int cnt = ans.size();

            int cur = 0, tt = cnt;
            int add = 0;
            for(auto [b, id] : v[i])
            {
                cur ++;

                if(cur + min(cnt, b) > tt)
                {
                    tt = cur + min(cnt, b);
                    add = cur;
                }
            }
            for(int j = 0; j < cnt + add - tt; j ++) 
                ans.pop_back();

            for(auto [b, id] : v[i])
            {
                if(!add) break;
                add --;
                ans.push_back(id);
            }
        }
        cout <<ans.size() <<endl;
        tell(0, ans);

    }
    return 0;
}
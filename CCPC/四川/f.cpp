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

void tell(vector<int> &v)
{
    for(auto x : v)
        cout <<x <<" ";
    cout <<endl;
}

void tell1(vector<int> &v)
{
    for(int i = 1; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
    return a.se < b.se;
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n; string s; cin >>n >>s;
        s = ' ' + s;

        vector<int> suf(n + 2, 0);
        for(int i = n; i >= 1; i --)
            suf[i] = suf[i + 1] + (s[i] != '1');

        ll ans = 0;
        int cnt1 = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(s[i] == '1') cnt1 ++;
            else ans += cnt1;
        }
        cnt1 = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(s[i] == '1') cnt1 ++;
            else if(s[i] == '?')
            {
                ll delta = suf[i + 1] - cnt1;
                if(delta >= 0)
                {
                    ans += delta;
                    cnt1 ++;
                }
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}
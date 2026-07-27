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

bool check(vector<int> &a)
{
    int x = a[0]; int c = 0;
    for(int i = 1; i < a.size(); i ++)
    {
        if(abs(a[i]) != abs(x)) return false;
        if(a[i] < 0) c ++;
    }
    return (c == a.size() / 2 || c == (a.size() + 1) / 2); 
}

bool cmp(const int &a, const int &b)
{
    return abs(a) < abs(b);
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector<int> a(n);
        for(auto &x : a) cin >>x;

        sort(a.begin(), a.end(), cmp);

        if(abs(a[0]) == abs(a[n - 1]))
        {
            int cnt = 0;
            for(auto x : a)
                cnt += (x < 0);
            if(cnt == n - cnt || abs(cnt - (n - cnt)) == 1 || cnt == 0 || cnt == n)
                cout <<"Yes" <<endl;
            else 
                cout <<"No" <<endl;

            continue;
        }
        bool f = 1;
        for(int i = 1; i < n; i ++)
            if(1LL * a[i] * a[0] != 1LL * a[i - 1] * a[1])
            {
                f = 0;
                break;
            }
        cout <<(f ? "Yes" : "No") <<endl;
    }
    return 0;
}
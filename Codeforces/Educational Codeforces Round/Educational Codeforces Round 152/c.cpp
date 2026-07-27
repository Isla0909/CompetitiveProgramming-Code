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

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7, P = 131;

vector<u64> sum(N, 0);
void init() 
{
    u64 pow = 1; 
    for (int k = 1; k < N; k ++) 
    {
        sum[k] = sum[k - 1] + pow;
        pow = pow * P;                  
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int T; cin >>T;
    while(T --)
    {
        int n, m; cin >>n >>m;
        string s; cin >>s; s = ' ' + s;

        vector<u64> p(n + 1), hash(n + 1); p[0] = 1;
        vector<int> pre(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            hash[i] = hash[i - 1] * P + s[i] - '0';
            p[i] = P * p[i - 1];
            pre[i] = pre[i - 1] + (s[i] == '1');
        }

        auto f = [&](int l, int r) -> u64
        {
            return hash[r] - hash[l - 1] * p[r - l + 1]; 
        };

        map<u64, int> mp;
        while(m --)
        {
            int l, r; cin >>l >>r;
            u64 lst = f(l, r) * p[n - r]; 
            int len = r - l + 1;
            int c1 = pre[r] - pre[l - 1], c0 = len - c1; 

            u64 new_sub = sum[c1];  
            u64 now = new_sub * p[n - r]; 

            mp[hash[n] - lst + now] ++;
        }
        cout <<mp.size() <<endl;
    }
    return 0;
}
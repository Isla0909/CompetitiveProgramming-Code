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
#define int long long
using namespace std;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 6e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
vector<int> minp, primes;
vector<ll> pre;
int cnt;

void sieve(int n)
{
    minp.assign(n + 1, 0);
    primes.clear(); cnt = 0;

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
    
    cnt = primes.size();
    pre.assign(cnt + 1, 0);
    for(int i = 1; i <= cnt; i ++)
        pre[i] = pre[i - 1] + primes[i - 1];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    sieve(1e7);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector<int> a(n);
        for(auto &x : a) cin >>x;

        sort(a.begin(), a.end()); int idx = 0;

        int s = 0;
        for(int i = 0; i < n; i ++)
            s += a[i];

        int ans = 0; int j = n;
        while(pre[j] > s)
        {
            ans ++;
            //cout <<a[idx] <<123 <<endl;
            s -= a[idx]; idx ++;
            j --;
        }
        cout <<ans <<endl;
    }
    return 0;
}
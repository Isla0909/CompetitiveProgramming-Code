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

int quick_pow(int a, ll b, int p)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = 1LL * res * a % p;

        a = 1LL * a * a % p;
        b >>= 1;
    }
    return res % p;
}

int inv(int x, int p)
{
    return quick_pow(x, p - 2, p);
}

int C(int a, int b, int p)
{
    if(a < 0 || b < 0 || a < b) return 0;

    int res = 1;
    for(int i = 1, j = a; i <= b; i ++, j --)
    {
        res = 1LL * res * j % p;
        res = 1LL * res * inv(i, p) % p;
    }
    return res;
}

int Lucas(ll a, ll b, int p)
{
    if(a < p && b < p) return C(a, b, p);
    return 1LL * C(a % p, b % p, p) * Lucas(a / p, b / p, p) % p;
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int a, b, k; cin >>a >>b >>k;
        int n = (1LL * k * (a - 1) + 1) % mod;
        ll m = 1LL * k * Lucas(n, a, mod) % mod * (b - 1) + 1; m %= mod;
        cout <<n <<" " <<m <<endl;
    }
    return 0;
}
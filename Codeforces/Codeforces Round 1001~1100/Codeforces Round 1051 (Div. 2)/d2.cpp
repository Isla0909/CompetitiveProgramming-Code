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

template <class T>
constexpr T power(T a, i64 b)
{
    assert(b >= 0);
    T res = 1;
    while(b)
    {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p)
{
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;

    if(res < 0) res += p;
    return res;
}

template <i64 P>
struct MLong
{
    i64 x; //x ≡ value (mod Mod)
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x_) : x{norm(x_ % getMod())} {}

    static i64 Mod;
    constexpr static i64 getMod()
    {
        //P > 0为静态档, P <= 0为动态档, 模数是Mod
        return P > 0 ? P : Mod;
    }
    //动态修改Mod -> Z::setMod(p)
    constexpr static void setMod(i64 Mod_)
    {
        Mod = Mod_;
    }
    //归一化处理
    constexpr i64 norm(i64 x) const//const保证限制成员变量不被修改 
    {
        if(x < 0) x += getMod();
        if(x >= getMod()) x -= getMod();
        return x;
    }
    constexpr i64 val() const
    {
        return x;
    }
    explicit constexpr operator i64() const
    {
        return x;
    }
    constexpr MLong operator-() const
    {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) &//right-hand side右操作数
    {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) &
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) &
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) &
    {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs)//虽然不是私有成员,加上friend便于以后的维护
    {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs)
    {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr istream &operator>>(istream &is, MLong &a)
    {
        i64 v;
        is >>v;
        a = MLong(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MLong &a)
    {
        return os<< a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs)
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs)
    {
        return lhs.val() != rhs.val();
    }
};

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x_) : x{norm(x_ % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        return P > 0 ? P : Mod;
    }
    constexpr static void setMod(int Mod_) 
    {
        Mod = Mod_;
    }
    constexpr int norm(int x) const 
    {
        if (x < 0) x += getMod();
        if (x >= getMod()) x -= getMod();
        return x;
    }
    constexpr int val() const 
    {
        return x;
    }
    explicit constexpr operator int() const 
    {
        return x;
    }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr istream &operator>>(istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) 
    {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) 
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) 
    {
        return lhs.val() != rhs.val();
    }
};

constexpr int M1 = 998244353, M2 = 1e9 + 7;
constexpr i64 M3 = i64(1e18) + 9;
using Z = MInt<M2>;

template <typename T> struct Fenwick
{
    int n;
    vector<T> tr;

    #define lowbit(x) (x & -x)

    void initial(int n_)
    {
        n = n_;
        tr.assign(n + 1, T{});
    }

    Fenwick(int n_ = 0)
    {
        initial(n_);
    }

    void add(int x, const T &c)
    {
        for(int i = x; i <= n; i += lowbit(i))
            tr[i] += c;
    }

    T sum(int x)
    {
        T ans{};
        for(int i = x; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    }

    T rangeSum(int l, int r)//闭区间[l, r]之和
    {
        return sum(r) - sum(l - 1);
    }

    int select(const T &k)
    {
        int x = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i /= 2)
        {
            if(x + i <= n && cur + tr[x + i] <= k)
            {
                x += i;
                cur += tr[x];
            }
        }
        return x;
    }

    void max_update(int x, const T &c)
    {
        for(int i = x; i <= n; i += lowbit(i))
            tr[i] = max(tr[i], c);
    }

    T max_query(int x)
    {
        T ans{};
        for(int i = x; i; i -= lowbit(i))
            ans = max(ans, tr[i]);
        return ans;
    }

    i64 calc(vector<T> &a)
    {
        tr.assign(n + 1, T{});
        
        vector<T> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        auto find = [&](T x) -> int
        {
            return lower_bound(b.begin(), b.end(), x) - b.begin();
        };

        i64 ans = 0;
        for(int i = 0; i < a.size(); i ++)
        {
            int x = find(a[i]) + 1;
            add(x, 1);
            ans += i + 1 - sum(x);
        }
        return ans;
    }
};
//开的时候不需要再Fenwick<int> bit(n + 1)了

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++) cin >>a[i];

        //row[x]对应f[x][y]的y维度，col[y]对应f[x][y]的x维度
        //此处+1是为了避免索引为0死循环加上的偏移量
        vector row(n + 1, Fenwick<Z>(n + 1)), col(n + 1, Fenwick<Z>(n + 1));
        row[0].add(1, 1), col[0].add(1, 1);

        vector f(n + 1, vector<Z>(n + 1));
        f[0][0] = 1;

        Z ans = 1;
        for(int i = 1; i <= n; i ++)
        {
            for(int y = 0; y <= a[i]; y ++)
            {
                Z sum = col[y].rangeSum(y + 1, a[i] + 1);

                f[a[i]][y] += sum;
                row[a[i]].add(y + 1, sum);
                col[y].add(a[i] + 1, sum);

                ans += sum;
            }
            for(int x = a[i] + 1; x <= n; x ++)
            {
                Z sum = row[x].rangeSum(1, a[i] + 1);

                f[x][a[i]] += sum;
                row[x].add(a[i] + 1, sum);

                col[a[i]].add(x + 1, sum);

                ans += sum;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}
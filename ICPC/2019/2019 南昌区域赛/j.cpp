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

constexpr int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

template <class T> constexpr T power(T a, i64 b)
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

template<int P> struct MInt 
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
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) 
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
using Z = MInt<M1>;
//注:使用前记得修改模数!!

int calc(int a, int b, int c, int d)
{
	return 64 * a + 16 * b + 4 * c + d;
}

Z f[N][4][4][4];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	vector<bool> bad(256);
	for(int i = 0; i < m; i ++)
	{
		int a, b, c, d; cin >>a >>b >>c >>d;
		bad[calc(a, b, c, d)] = true;
	}

	Z ans = 0;
	auto solve = [&]() -> void
	{
		for(int i = 4; i <= n; i ++)
			for(int a = 0; a < 4; a ++)
				for(int b = 0; b < 4; b ++)
					for(int c = 0; c < 4; c ++)
					{
						if(f[i - 1][a][b][c] == 0) continue;

						for(int d = 0; d < 4; d ++)
						{
							if(bad[calc(a, b, c, d)]) continue;
							f[i][b][c][d] += f[i - 1][a][b][c];
						}
					}
		for(int a = 0; a < 4; a ++)
			for(int b = 0; b < 4; b ++)
				for(int c = 0; c < 4; c ++)
					ans += f[n][a][b][c];
	};

	auto del = [&](int a, int b, int c) -> void
	{
		for(int x = 0; x < 4; x ++)
		{
			for(int y = 0; y < 4; y ++)
			{
				for(int z = 0; z < 4; z ++)
				{
					if(bad[calc(z, a, b, c)]) ans -= f[n][x][y][z];
					else if(bad[calc(y, z, a, b)]) ans -= f[n][x][y][z];
					else if(bad[calc(x, y, z, a)]) ans -= f[n][x][y][z];
				}
			}	
		}	
	};

	auto clear = [&] -> void
	{
		for(int i = 3; i <= n; i ++)
			for(int a = 0; a < 4; a ++)
				for(int b = 0; b < 4; b ++)
					for(int c = 0; c < 4; c ++)
						f[i][a][b][c] = 0;
	};

	for(int a = 0; a < 4; a ++)
		for(int b = 0; b < 4; b ++)
			for(int c = 0; c < 4; c ++)
			{
				f[3][a][b][c] = 1;
				solve();
				del(a, b, c);
				clear();
			}
	cout <<ans / n + (n / 2) * m <<endl;
	return 0;
}

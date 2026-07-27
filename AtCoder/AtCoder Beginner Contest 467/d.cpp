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

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

bool cmp(const pii &a, const pii &b)
{
	return a.se < b.se;
}

template<class T> struct Point
{
	T x, y;

	Point(T x_, T y_) : x(x_), y(y_) {}

	template<class U> operator Point<U>() const
	{
		return Point<U>(U(x), U(y));
	}

	constexpr Point &operator+=(Point rhs) &
	{
		x += rhs.x, y += rhs.y;
		return *this;
	}
	constexpr Point &operator+=(T rhs) &
	{
		x += rhs, y += rhs;
		return *this;
	}
	constexpr Point &operator-=(Point rhs) &
	{
		x -= rhs.x, y -= rhs.y;
		return *this;
	}
	constexpr Point &operator-=(T rhs) &
	{
		x -= rhs, y -= rhs;
		return *this;
	}
	constexpr Point &operator*=(T rhs) &
	{
		x *= rhs, y *= rhs;
		return *this;
	}
	constexpr Point &operator/=(T rhs) &
	{
		x /= rhs, y /= rhs;
		return *this;
	}
	constexpr Point operator-() const
	{
		return Point(-x, -y);
	}
	friend constexpr Point operator+(Point lhs, Point rhs)
	{
		Point res = lhs;
		res += rhs;
		return res;
	}
	friend constexpr Point operator-(Point lhs, Point rhs)
	{
		Point res = lhs;
		res -= rhs;
		return res;
	}
	friend constexpr Point operator+(Point lhs, T rhs)
	{
		Point res = lhs;
		res += rhs;
		return res;
	}
	friend constexpr Point operator-(Point lhs, T rhs)
	{
		Point res = lhs;
		res -= rhs;
		return res;
	}
	friend istream &operator>>(istream &is, Point &p)
	{
		return is >> p.x >> p.y;
	}
	friend ostream &operator<<(ostream &os, const Point &p)
	{
		return os << p.x << " " << p.y;
	}
};

template<class T> T cross(Point<T> a, Point<T> b)
{
	return a.x * b.y - a.y * b.x;
}

template<class T> T dot(Point<T> a, Point<T> b)
{
	return a.x * b.x + a.y * b.y;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		Point<i64> p1(0, 0), q1(0, 0), p2(0, 0), q2(0, 0);
		cin >>p1 >>q1 >>p2 >>q2;

		Point<i64> v1 = q1 - p1, v2 = q2 - p2;
		if(cross(v1, v2)) cout <<"Yes" <<endl;
		else
		{
			Point<i64> v3 = p1 + q1 - p2 - q2;
			if(dot(v1, v3)) cout <<"No" <<endl;
			else cout <<"Yes" <<endl;
		}
	}
	return 0;
}

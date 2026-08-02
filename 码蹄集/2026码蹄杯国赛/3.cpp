#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void tell(int l, vector<int> &v)
{
	for(int i = l; i < v.size(); i ++)
		cout <<v[i] <<" \n"[i == v.size() - 1];
}

struct line
{
	int xx1, yy1, xx2, yy2;
	int f;
	line(int xx1, int yy1, int xx2, int yy2, int f) : xx1(xx1), yy1(yy1), xx2(xx2), yy2(yy2), f(f) {}
};

bool jiao(line l1, line l2)
{
	if(l1.f == l2.f)
	{
		if(l1.f == 0)
		{
			if(l1.yy1 != l2.yy1) return false;
			if(l1.xx2 < l2.xx1 || l2.xx2 < l1.xx1) return false;
			return true;
		}
		else
		{
			if(l1.xx1 != l2.xx1) return false;
			if(l1.yy2 < l2.yy1 || l2.yy2 < l1.yy1) return false;
			return true;
		}
	}
	else
	{
		if(l1.f != 0) swap(l1, l2);
		if(l2.xx1 > l1.xx2 || l2.xx1 < l1.xx1) return false;
		if(l1.yy1 > l2.yy2 || l1.yy1 < l2.yy1) return false;
		return true;
	}
}

void cc(line &l)
{
	cout <<l.xx1 <<" " <<l.yy1 <<" " <<l.xx2 <<" " <<l.yy2 <<" " <<l.f <<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >>n;
	vector<array<int, 4>> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >>a[i][0] >>a[i][1] >>a[i][2] >>a[i][3];
	// line l1(1, 1, 1, 4, 1), l2(2, 2, 2, 3, 1);
	// if(jiao(l1, l2)) cout <<"shabi" <<endl;

	auto nima = [&](int x, int y, int l1, int r1, int l2, int r2)
	{
		return x >= l1 && x <= r1 && y >= l2 && y <= r2;
	};

	auto check1 = [&](int i, int j)
	{
		int xl = a[i][0], xr = a[i][2], yl = a[i][1], yr = a[i][3];
		int xx1 = a[j][0], x3 = a[j][0], xx2 = a[j][2], x4 = a[j][2];
		int yy1 = a[j][3], y3 = a[j][1], yy2 = a[j][3], y4 = a[j][1];
		if(nima(xx1, yy1, xl, xr, yl, yr) || nima(xx2, yy2, xl, xr, yl, yr) || nima(x3, y3, xl, xr, yl, yr) || nima(x4, y4, xl, xr, yl, yr)) return true;
		return false;
	};

	vector<int> dd(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i + 1; j <= n; j ++)
		{
			if(j == i) continue;
			if(check1(i, j) || check1(j, i))
			{
				dd[i] ++, dd[j] ++;
				continue;
			}
			auto [xx1, yy1, xx2, yy2] = a[i];
			auto [x3, y3, x4, y4] = a[j];
			line a(x3, y3, x4, y3, 0), b(x3, y4, x4, y4, 0), c(x3, y3, x3, y4, 1), d(x4, y3, x4, y4, 1);
			line l1(xx1, yy1, xx2, yy1, 0);
			if(jiao(l1, a) || jiao(l1, b) || jiao(l1, c) || jiao(l1, d))
			{
				dd[i] ++, dd[j] ++;
				//cout <<1111 <<endl;
				continue;
			}
			line l2(xx1, yy2, xx2, yy2, 0);
			if(jiao(l2, a) || jiao(l2, b) || jiao(l2, c) || jiao(l2, d))
			{
				dd[i] ++, dd[j] ++;
				//cout <<2222 <<endl;
				continue;
			}
			line l3(xx1, yy1, xx1, yy2, 1);
			if(jiao(l3, a) || jiao(l3, b) || jiao(l3, c) || jiao(l3, d))
			{
				dd[i] ++, dd[j] ++;
				// if(jiao(l3, a)) cout <<1333 <<endl;
				// if(jiao(l3, b)) cout <<2333 <<endl;
				// if(jiao(l3, c)) cout <<3333 <<endl;
				// if(jiao(l3, d)) cout <<4333 <<endl;
				// cc(l3), cc(c);
				continue;
			}
			line l4(xx2, yy1, xx2, yy2, 1);
			if(jiao(l4, a) || jiao(l4, b) || jiao(l4, c) || jiao(l4, d))
			{
				dd[i] ++, dd[j] ++;
				continue;
			}
		}
		// cout <<i <<endl;
		// tell(1, dd);
	}
	tell(1, dd);
	return 0;
}
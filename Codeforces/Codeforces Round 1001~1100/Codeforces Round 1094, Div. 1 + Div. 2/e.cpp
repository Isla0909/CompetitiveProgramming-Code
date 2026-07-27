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

int query1(i64 x)
{
	cout <<"I " <<x <<endl;
	int c; cin >>c;
	return c;
}

int query2(i64 x)
{
	cout <<"Q " <<x <<endl;
	int c; cin >>c;
	return c;
}

bool prefect(i64 x)
{
	int h = __lg(x) + 1;
	return (1LL << h) == x + 1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >>T;
	while(T --)
	{
		cout <<0 <<endl;
		int n; cin >>n;
		int v = query1(0);
		if(v == 1)//k = 1
		{
			vector<int> st(n);
			for(int i = 0; i < n; i ++)
			{
				i64 x = 1LL << i;
				int nv = query1(x);
				if(nv == v + 1)
				{
					st[i] = 1;
					v = nv;
				}
			}
			i64 c = 0;
			for(int i = 0; i < n; i ++)
				if(st[i]) c += (1LL << i);
			cout <<"A 1" <<" " <<c <<endl;
		}
		else
		{

			i64 l = 0, r = (1LL << n);
			while(l + 1 != r)
			{
				i64 mid = l + r >> 1LL;
				if(query2(mid) == 1) l = mid;
				else r = mid;
			}
			i64 c = l;
			int idx = 0;
			for(int i = 60; i >= 0; i --)
			{
				if(c >> i & 1LL)
				{
					idx = i;
					break;
				}
			}
			int pc = __builtin_popcountll(c);
			if(pc != 1)
			{
				i64 shabi = (1LL << idx);
				int nv = query1(shabi);
				int k;
				if(nv == v) k = 2;
				else
				{
					assert(nv == v + 1);
					k = 3;
				}
				cout <<"A " <<k <<" " <<c <<endl;
			}
			else
			{
			    int k;
			    if(c == 1)
			    {
			        query1(3);
			        if(query2(3) == 1) k = 2;
			        else k = 3;
			    }
			    else
			    {
			        i64 x = c | (c >> 1);
			        query1(x);
			        if(query2(c + 1) == 1) k = 2;
			        else k = 3;
			    }
			    cout <<"A " <<k <<" " <<c <<endl;
			}
		}
	}
	return 0;
}

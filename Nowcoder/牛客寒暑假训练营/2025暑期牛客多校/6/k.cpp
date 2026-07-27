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
using i32 = unsigned;
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

void tell(int l, vector<int> &v)
{
    for(int i = l; i < v.size(); i ++)
        cout <<v[i] <<" \n"[i == v.size() - 1];
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
		vector<int> a(n + 1); 
		for(int i = 1; i <= n; i ++) cin >>a[i];

		int s = *max_element(a.begin() + 1, a.end());
		auto check = [&]() -> bool
		{
			int min = *min_element(a.begin() + 1, a.end());
			return s == min;
		};

		if(check())
		{
			cout <<0 <<endl;
			continue;
		}
        
		if(n == 2)
		{
			cout <<s <<endl;
			continue;
		}

        vector<int> b;
        b.push_back(0), b.push_back(a[1]);
        int idx = 1;
        for(int i = 2; i <= n; i ++)
        {
            if(a[i] != b[idx])
            {
                b.push_back(a[i]);
                idx ++;
            }
        }

        n = b.size() - 1;

        if(n == 2)
        {
        	cout <<max(b[1], b[2]) <<endl;
        	continue;
        }

        if(n <= 100000)
        {
        	vector<int> d;
        	for(int i = 1; i <= n; i ++)
        	{
        		int x = b[i];
        		for(int j = 1; j * j <= x; j ++)
        		{
        			if(x % j == 0)
        			{
        				d.push_back(j);
        				if(j * j != x) d.push_back(x / j);
        			}
        		}
        	}
        	for(int i = 2; i <= n; i ++)
        	{
        		int diff = abs(b[i] - b[i - 1]);
        		for(int j = 1; j * j <= diff; j ++)
        		{
        			if(diff % j == 0)
        			{
        				d.push_back(j);
        				if(j * j != diff) d.push_back(diff / j);
        			}
        		}
        	}
        	sort(d.begin(), d.end(), greater<int>());
    		d.erase(unique(d.begin(), d.end()), d.end());

    		for(int k = 0; k < d.size(); k ++)
    		{
    			int x = d[k]; bool f = 1, ok = 1;
    			for(int i = 1; i <= n; i ++)
				{
					int c = b[i] % x;
					if(c)
					{
						if(!f)
						{
							ok = 0;
							break;
						}
						f = 0;
						int j = i + 1;
						while(j <= n && b[j] % x == c) j ++;
						i = j - 1;
					}
				}
				if(ok)
				{
					cout <<x <<endl;
					break;
				}
    		}
    		continue;
        }

		for(int d = s; d >= 1; d --)
		{
			bool f = 1; bool ok = 1;
			for(int i = 1; i <= n; i ++)
			{
				int c = b[i] % d;
				if(c)
				{
					if(!f)
					{
						ok = 0;
						break;
					}
					f = 0;
					int j = i + 1;
					while(j <= n && b[j] % d == c) j ++;
					i = j - 1;
				}
			}
			if(ok)
			{
				cout <<d <<endl;
				break;
			}
		}
	}	
	return 0;
}
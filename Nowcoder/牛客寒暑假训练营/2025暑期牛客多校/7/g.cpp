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
typedef pair<int, string> pis;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

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

bool check(int x)
{
    int c = sqrt(x);
    return c * c == x;
}

int divide(int x)
{
    int res = 0;
    assert(x >= 1);
    while(x != 1)
    {
        int p = minp[x];
        int cnt = 0;
        while(x % p == 0)
        {
            x /= p;
            cnt ++;
        }
        if(cnt & 1) res ++;
    }
    return res;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

    sieve(1e6);

	int T; cin >>T;
	while(T --)
	{
		int n; cin >>n;
// 		vector<int> st(n + 1);
// 		for(int i = 1; i * i <= n; i ++)
// 		{
// 		    int c = i * i;
// 		    st[c] = 1;
// 		    if(c == 1) continue;
		    
// 		    for(int j = 1; j * c <= n; j ++)
// 		    {
// 		        if(j % i != 0)
// 		        {
// 		            st[j * c] = 1;
// 		        }
// 		    }
// 		}
		vector<int> ans;
		for(int i = n; ans.size() < n / 2; i --)
		{
		    if(divide(i) & 1)
		    {
		        //cout <<i <<" " <<divide(i) <<endl;
		        ans.push_back(i);
		    }
		    
		}
		//cout <<ans.size() <<endl;
		for(auto x : ans)
		    cout <<x <<" ";
		cout <<endl;
		
// 		for(int i = 0; i < ans.size(); i ++)
// 		    for(int j = 0; j < ans.size(); j ++)
// 		        for(int k = 0; k < ans.size(); k ++)
// 		            if(check(ans[i] * ans[j] * ans[k]))
// 		            {
// 		                cout <<ans[i] <<" " <<ans[j] <<" " <<ans[k] <<endl;
// 		                return 0;
// 		            }
		
	}
	return 0;
}
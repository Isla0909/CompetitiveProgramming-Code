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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >>n >>m;
	
	int len = sqrt(n);
	vector<int> a(n + 1), id(n + 1);
	for(int i = 1; i <= n; i ++)
	    id[i] = (i - 1) / len + 1;
	    
	int cnt = id[n];
	vector<int> add(cnt + 1), sum(cnt + 1);
	
	auto query = [&](int l, int r) -> i32
	{
	    int res = 0;
	    if(id[l] == id[r])
	    {
	        int c = id[l];
	        for(int i = l; i <= r; i ++)
	            res += (a[i] ^ add[c]);
	    }
	    else
	    {
	        int i = l, j = r;
	        while(id[i] == id[l]) res += (a[i] ^ add[id[l]]), i ++;
	        while(id[j] == id[r]) res += (a[j] ^ add[id[r]]), j --;
	        
	        for(int k = id[i]; k <= id[j]; k ++)
	            res += sum[k];
	    }
	    return res;
	};
	
	   auto change = [&](int l, int r) -> void
	   {
	        if(id[l] == id[r])
    	    {
    	        int c = id[l];
    	        for(int i = l; i <= r; i ++)
    	        {
    	            int s = a[i] ^ add[c];
    	            a[i] ^= 1;
    	            sum[c] += (s ? -1 : 1);
    	        }
    	    }
    	    else
    	    {
    	        int i = l, j = r;
    	        while(id[i] == id[l])
    	        {
    	            int c = id[l];
    	            int s = a[i] ^ add[c];
    	            a[i] ^= 1;
    	            sum[c] += (s ? -1 : 1);
    	            i ++;
    	        }
    	        while(id[j] == id[r])
    	        {
    	            int c = id[r];
    	            int s = a[j] ^ add[c];
    	            a[j] ^= 1;
    	            sum[c] += (s ? -1 : 1);
    	            j --;
    	        }
    	        
    	        for(int k = id[i]; k <= id[j]; k ++)
    	        {
    	            add[k] ^= 1;
    	            sum[k] = len - sum[k];
    	        }
    	    }
	   };
	
	while(m --)
	{
	    int op; cin >>op;
	    if(op & 1)
	    {
	        int l, r; cin >>l >>r;
	        cout <<query(l, r) <<endl;
	    }
	    else
	    {
	        int l, r; cin >>l >>r;
	        change(l, r);
	    }
	}
	
	return 0;
}
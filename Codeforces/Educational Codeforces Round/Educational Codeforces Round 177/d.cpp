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
#define ff first
#define se second
#define endl '\n'
#define int long long
using namespace std;
using u32 = unsigned;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 5e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

int quick_pow(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;

		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int fact[N], inv_fact[N];


void initial()
{
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv_fact[i] = quick_pow(fact[i], mod - 2);
    }
}

int C(int a, int b)
{
    if (b > a) return 0;
    if (!b) return 1;
    return fact[a] * inv_fact[b] % mod * inv_fact[a - b] % mod;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);

    initial();

	int T; cin >>T;
	while(T --)
	{
		vector<int> cnt(27), s(27, 0);
		int n = 0;
		for(int i = 1; i <= 26; i ++)
		{
			cin >>cnt[i];
			s[i] = s[i - 1] + cnt[i];
			n += cnt[i];
		}
		//cout <<n <<endl;
		vector f(27, vector<int>((n + 1) / 2 + 1, 0));
		f[0][0] = 1;
		for(int i = 1; i <= 26; i ++)
		{
		    if(!cnt[i])
		    {
		        for(int j = 0; j <= (n + 1) / 2; j ++)
		            f[i][j] = f[i - 1][j];
		        continue;
		    }
			for(int j = 0; j <= (n + 1) / 2; j ++)
	        {
                
                
				if((n + 1) / 2 - j >= cnt[i])
				{
				     f[i][j + cnt[i]] = (f[i][j + cnt[i]] + f[i - 1][j] * C((n + 1) / 2 - j, cnt[i]) % mod) % mod;
				     //cout <<1 <<i <<" "<<f[i][j + cnt[i]] <<endl;
				}
				//if(s[i - 1] - j >= 0) cout <<n / 2 - (s[i - 1] - j) <<endl;
				//if(i == 3) cout <<f[3][2] <<endl;
				if(s[i - 1] - j >= 0 && n / 2 - (s[i - 1] - j) >= cnt[i])
				{
				     //if(i == 3) cout <<f[3][2] <<endl;
				     f[i][j] = (f[i][j] + f[i - 1][j] * C(n / 2 - (s[i - 1] - j), cnt[i]) % mod) % mod;
				     //if(i == 3) cout <<f[3][2] <<endl;
				}
			}
		}
// 		cout <<f[1][2] <<" " <<f[1][0] <<endl;
// 		cout <<f[2][2] <<" " <<f[2][1] <<endl;
// 		cout <<f[3][2] <<" " <<f[3][1] <<endl;
		cout <<f[26][(n + 1) / 2] <<endl;
	}
	return 0;
}
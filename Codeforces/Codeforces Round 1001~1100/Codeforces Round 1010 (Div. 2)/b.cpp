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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int w[], int n)
{
    for(int i = 1; i <= n; i ++)
        cout <<w[i] <<" \n"[i == n];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int x, a, b; cin >>x >>a >>b;
        int n = min(31, a), m = min(31, b);
        int t = x;
        for(int i = 0; ; i ++)
        {
            if(!t) break;
            if(!n && !m) break;
            if(m)
            {
                t += 1;
                t >>= 1;
                m --;
            }
            else if(n)
            {
                t >>= 1;
                n --;
            }
        }
        n = min(31, a), m = min(31, b);
        for(int i = 0; ; i ++)
        {
            if(!x) break;
            if(!n && !m) break;
            if(n)
            {
                x >>= 1;
                n --;
            }
            else if(m)
            {
                x += 1;
                x >>= 1;
                m --;
            }
        }
        cout <<t <<" " <<x <<endl;
    }
    return 0;
}
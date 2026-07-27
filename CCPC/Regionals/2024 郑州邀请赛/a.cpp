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
using namespace std;
using i64 = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


bool check(i64 x, int d)
{
    vector<int> cnt(10);
    while(x)
    {
        int r = x % 10;
        cnt[r] ++;
        x /= 10;
    }
    bool f = 1;
    for(int i = 1; i <= 9; i ++)
    {
        if(!cnt[i]) return false;
    }
    return cnt[d] >= 2;
}

i64 rand(i64 l, i64 r)//[l, r]
{
    return rng() % (r - l + 1) + l;
}

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
void wr(i64 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)wr(x/10);
    putchar('0'+x%10);
    //putchar('\n');
}

i64 p10[11], p11[11];

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    p10[0] = p11[0] = 1;
    for(int i = 1; i <= 10; i ++)
    {
        p10[i] = p10[i - 1] * 10;
        p11[i] = p10[i] + p10[i - 1];
    }

    int T; T = read();
    while(T --)
    {
        int n = read(), d = read();
        i64 k; bool f = 0;
        for(int i = 1; i <= 10; i ++)
        {
            k = p11[i];
            if(check(n * k, d))
            {
                wr(k);
                putchar('\n');
                f = 1;
                break;
            }
        }
        if(f) continue;
        k = p10[10] + 1;
        while(!check(n * k, d))
        {
            k = rand(1, 20000000000);
        }
        wr(k);
        putchar('\n');
    }

    return 0;
}
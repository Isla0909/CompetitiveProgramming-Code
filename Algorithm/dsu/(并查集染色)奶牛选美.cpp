#include <iostream>
#define endl '\n'
using namespace std;

const int N = 3e5 + 10;
int p[N];
int ans[N];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    int n, m; cin >>n >>m;
    for(int i = 1; i <= n + 1; i ++) p[i] = i;
    while(m --)
    {
        int l, r, x; cin >>l >>r >>x;
        for(int i = l; i <= x - 1; )
        {
            i = find(i);
            if(i < x)
            {
                p[i] = i + 1;
                ans[i] = x;
            }
        }
        for(int i = x + 1; i <= r; )
        {
            i = find(i);
            if(i <= r)
            {
                p[i] = i + 1;
                ans[i] = x;
            }
        }
    }
    for(int i = 1; i <= n; i ++)
        cout <<ans[i] <<" ";
    return 0;
}
//https://www.acwing.com/problem/content/6103/
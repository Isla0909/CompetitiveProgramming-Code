#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int g[N][N];
int d[N]; bool st[N];

int n; int ans;

void prim()
{
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    
    for(int i = 0; i <= n; i ++)
    {
        int t = -1;
        
        for(int j = 0; j <= n; j ++)
            if(!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
    
        st[t] = 1;
        
        ans += d[t];
        
        for(int j = 0; j <= n; j ++)
            d[j] = min(d[j], g[t][j]);
    }
}

int main()
{
    cin >>n;
    
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >>x;
        g[0][i] = g[i][0] = x;
    }
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >>g[i][j];
            
    prim();
    
    cout <<ans <<endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5 + 10, M = 2e6 + 10;
int n, m, mod;
int h[N], hs[N], nex[M], val[M]; int idx = 0;
int dfn[N], low[N]; int time_stamp = 0;
int id[N], siz[N]; int scc_cnt = 0;
bool st[N];
int dp[N], g[N];

void add(int h[], int a, int b)
{
    nex[idx] = h[a], val[idx] = b, h[a] = idx ++;
}

stack <int> s;

void tarjan(int u)
{
    dfn[u] = low[u] = ++ time_stamp;
    s.push(u); st[u] = 1;
    for(int i = h[u]; ~ i; i = nex[i])
    {
        int j = val[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(st[j]) low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u] == low[u])
    {
        scc_cnt ++;
        int y;
        do
        {
            y = s.top(); s.pop();
            st[y] = 0;
            siz[scc_cnt] ++;
            id[y] = scc_cnt;
        }while(y != u);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    memset(h, -1, sizeof h), memset(hs, -1, sizeof hs);
    
    cin >>n >>m >>mod;
    while(m --)
    {
        int a, b; cin >>a >>b;
        add(h, a, b);
    }
    
    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i);
            
    map <pii, bool> mp;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = h[i]; ~ j; j = nex[j])
        {
            int k = val[j];
            int a = id[i], b = id[k];
            pii t = {a, b};
            if(a != b && !mp[t])
            {
                add(hs, a, b);
                mp[t] = 1;
            }
        }
    }
    
    for(int i = scc_cnt; i >= 1; i --)
    {
        if(!dp[i]) dp[i] = siz[i], g[i] = 1;
        for(int j = hs[i]; ~ j; j = nex[j])
        {
            int k = val[j];
            if(dp[i] + siz[k] > dp[k])
            {
                dp[k] = dp[i] + siz[k];
                g[k] = g[i];
            }
            else if(dp[i] + siz[k] == dp[k]) g[k] = (g[k] + g[i]) % mod;
        }
    }
    
    int max_len = -1;
    for(int i = 1; i <= scc_cnt; i ++)
        max_len = max(max_len, dp[i]);
        
    int ans = 0;
    for(int i = 1; i <= scc_cnt; i ++)
    {
        if(dp[i] == max_len)
        {
            ans += g[i];
            ans %= mod;
        }
    }
    cout <<max_len <<endl;
    cout <<ans <<endl;
    return 0;
}
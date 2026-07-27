#include<bits/stdc++.h> 
using namespace std ;
using ll = long long ;
using pii = pair<int,int> ;
const int inf = 1e9 ;
const int N = 1e3+5 ;




// void dfs1(int u,int fa)
// {
//     flag1[u]=1;
//     if(u == n) return ;
//     for(auto v:a[u]){
//         if(v==fa)continue;
//         dfs1(v,u);
//     }
// };
// void dfs2(int u,int fa){
//     flag2[u]=1;
//     if(u == 1) return ;
//     for(auto v:b[u]){
//         if(v==fa)continue;
//         dfs2(v,u);
//     }
// }


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n + 1), b(n + 1);
    vector<pii> ed;
    vector<vector<pii>> e(n + 1);
    vector<bool> flag1(n + 1), flag2(n + 1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        ed.push_back({u,v});
        a[u].push_back(v);
        b[v].push_back(u);
    }

    auto dfs1 = [&](this auto &&self, int u, int fa) -> void
    {
        flag1[u]=1;
        if(u == n) return ;
        for(auto v:a[u]){
            if(v==fa)continue;
            self(v,u);
        }
    };
    auto dfs2 = [&](this auto &&self, int u, int fa) -> void
    {
        flag2[u]=1;
        if(u == 1) return ;
        for(auto v: b[u]){
            if(v==fa)continue;
            self(v,u);
        }
    };

    dfs1(1,0);
    dfs2(n,0);
    vector<int> cnt(n+1),dis(n+1,inf);
    vector<bool> vis(n+1), flag(n + 1);
    for(int i = 1; i <= n; i ++)
        flag[i] = flag1[i] & flag2[i];

    for(auto [u,v] : ed)
    {
        if(flag[u] && flag[v]){
            e[u].push_back({v,2});
            e[v].push_back({u,-1});
        }
    }

    dis[1]=0;
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(q.size()){
        auto u=q.front();q.pop();
        vis[u]=0;
        for(auto [v,w]:e[u]){
            //if(!flag[v])continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]++;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
                if(cnt[v]>n){
                    cout<<"No\n";
                    return ;
                }
            }
        }
    }
    cout<<"Yes\n";
    for(auto [u,v]:ed)
    {
        if(flag[u]&&flag[v]) cout<<abs(dis[v]-dis[u])<<'\n';
        else cout<<1<<'\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
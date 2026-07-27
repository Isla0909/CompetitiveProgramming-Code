#include <iostream>
#include <vector>
using i64 = long long;
constexpr int ms1 = 2e3 + 5;
struct node {
    int to,val;
};
std::vector<node> tree[ms1];
int n,m,u,v,val,sz[ms1];
i64 dp[ms1][ms1];

void dfs(int fa,int now) {
    sz[now] = 1;
    dp[now][0] = 0;
    dp[now][1] = 0;
    for (auto v : tree[now]) {
        if (v.to == fa) continue;
        dfs(now,v.to);
        sz[now] += sz[v.to];
        for (int j = std::min(sz[now],m);j >= 0;j--) {
            for (int k = 0;k <= std::min(j,sz[v.to]);k++) {
                if (dp[u][j-k] == -1e18 || dp[v.to][k] == -1e18) continue;
                const i64 tot = k*(m-k)+(sz[v.to]-k)*(n-m-sz[v.to]+k);
                dp[u][j] = std::max(dp[u][j],dp[u][j-k]+dp[v.to][k]+1ll*tot*v.val);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1;i <= n-1;i++) {
        std::cin >> u >> v >> val;
        tree[u].push_back({v,val});
        tree[v].push_back({u,val});
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            dp[i][j] = -1e18;
        }
    }
    dfs(0,1);
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 0;j <= m;j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    // for (int i = 1;i <= n;i++) {
    //     std::cout << sz[i] << " ";
    // }
    std::cout << dp[1][m];
    return 0;
}
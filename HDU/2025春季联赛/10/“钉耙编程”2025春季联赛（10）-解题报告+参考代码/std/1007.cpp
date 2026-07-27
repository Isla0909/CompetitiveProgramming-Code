#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 5 , MOD = 1e9 + 7;

inline int inc(const int &x) {
  return x >= MOD ? x - MOD : x;
}
inline void add(int &x, const int &y) {
  x = inc(x + y);
}

int cnt = 0;
int dfn[N], idx[N], R[N], a[N], f[N][N];

vector<int> g[N];

void dfs(int u, int fa) {
  dfn[u] = R[u] = ++cnt;
  idx[cnt] = u;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    R[u] = max(R[u], R[v]);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;

  while (T--) {
    int n , m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
      cin >> a[i];
    }
    for (int i = 1 ; i < n ; i++) {
      int u , v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    dfs(1, 0);
    f[1][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
      for (int j = 0 ; j <= m ; j++) {
        if (j + a[idx[i]] <= m) {
          add(f[i + 1][j + a[idx[i]]], f[i][j]);
        }
        if (i != 1) add(f[R[idx[i]] + 1][j], f[i][j]);
      }
    }

    int ans = 0;
    for (int i = 0 ; i <= m ; i++) {
      add(ans, f[n + 1][i]);
    }
    cout << ans << '\n';
    
    cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
      g[i].clear();
    }
    for (int i = 0 ; i <= n + 1 ; i++) {
      for (int j = 0 ; j <= m ; j++) {
        f[i][j] = 0;
      }
    }
  }
  return 0;
}
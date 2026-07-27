#include <bits/stdc++.h>

using namespace std;
// using i64 = long long;
using i128 = __int128;

const int LOGN = 17;

string to_string(i128 x) {
  string res;
  while (x) {
    res += char('0' + x % 10);
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

struct Node {
  int cnt[2][LOGN];
  int cnt_pair[LOGN][LOGN][4];
  i128 sum = 0;

  Node() {
    memset(cnt, 0, sizeof cnt);
    memset(cnt_pair, 0, sizeof cnt_pair);
    sum = 0;
  }

  void append(int x) {
    for (int i = 0; i < LOGN; i++) {
      int d = (x >> i) & 1;
      sum += 1ll * cnt[d ^ 1][i] * (1ll << (2 * i));
      cnt[d][i]++;
    }
    for (int i = 0; i < LOGN; i++) {
      for (int j = i + 1; j < LOGN; j++) {
        int a = (x >> i) & 1;
        int b = (x >> j) & 1;
        sum += 2ll * cnt_pair[i][j][3 ^ ((a << 1) | b)] * (1ll << (i + j));
        cnt_pair[i][j][(a << 1) | b]++;
      }
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    string S;
    cin >> S;

    auto getfail = [](const string &S) {
      int n = S.size(), j = 0;
      vector<int> f(n + 1);
      for (int i = 1; i < n; i++) {
        j = f[i];
        while (j && S[i] != S[j]) j = f[j];
        f[i + 1] = S[i] == S[j] ? j + 1 : 0;
      }
      return f;
    };

    auto fa = getfail(S);
    vector<int> sz(n + 1), top(n + 1), son(n + 1), dep(n + 1);
    vector<Node> tree(n + 1);
    for (int i = n; i >= 1; i--) {
      sz[i]++;
      if (fa[i]) {
        sz[fa[i]] += sz[i];
        if (sz[i] > sz[son[fa[i]]]) {
          son[fa[i]] = i;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      dep[i] = dep[fa[i]] + 1;
      tree[i] = tree[fa[i]];
      tree[i].append(i);
      if (son[fa[i]] != i) {
        top[i] = i;
      } else {
        top[i] = top[fa[i]];
      }
    }

    auto get_lca = [&](int x, int y) {
      while (top[x] ^ top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
      }
      return dep[x] < dep[y] ? x : y;
    };

    while (m--) {
      int x , y;
      cin >> x >> y;
      int lca = get_lca(fa[x], fa[y]);
      // cout << "lca = " << lca << '\n';
      cout << to_string(2ll * tree[lca].sum) << '\n';
    }
  }
  return 0;
}
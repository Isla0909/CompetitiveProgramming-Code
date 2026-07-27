#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) in >> v[i];
  return in;
}

typedef long long ll;
const int mod = 998244353;
void add(int& x, int y) {
  if ((x += y) >= mod) x -= mod;
}
void del(int& x, int y) {
  if ((x -= y) < 0) x += mod;
}

template <typename T>
int gmax(T& x, T y) {
  if (y > x) {
    x = y;
    return 1;
  }
  return 0;
}

template <typename T>
int gmin(T& x, T y) {
  if (y < x) {
    x = y;
    return 1;
  }
  return 0;
}

typedef unsigned long long ull;
const int maxn = 1e6 + 10;
int vis[maxn];
ull H[maxn];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull rnd() { return (unsigned long long)rng(); }
void solve() {
  int n;
  cin >> n;
  vector<ull> sum(n + 1);
  unordered_map<ull, int> ma;
  ma[0] = 0;
  int ansl = -1, ansr = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum[i] = sum[i - 1] ^ H[x];
    if (ma.find(sum[i]) != ma.end()) {
      int l = ma[sum[i]];
      if (i - (l + 1) > ansr - ansl || ansl == -1) {
        ansr = i;
        ansl = l + 1;
      }
    } else
      ma[sum[i]] = i;
  }
  cout << ansl << " " << ansr << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < maxn; i++)
    if (!vis[i]) {
      ull h = rnd();
      H[i] = h;
      for (int j = i * 2; j < maxn; j += i) {
        int t = j;
        vis[j] = 1;
        while (t % i == 0) {
          H[j] ^= h;
          t /= i;
        }
      }
    }
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

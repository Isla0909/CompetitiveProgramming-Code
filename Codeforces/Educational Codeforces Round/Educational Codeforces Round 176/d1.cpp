#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "helper.h"
#else
#define dbg(...) ;
#define local_go_m(x) int c;cin>>c;while(c--)x()
#endif

using u64 = unsigned long long;

template<typename T>
bool cmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template<typename T>
bool cmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

i64 inf = 0x3f3f3f3f3f3f3f3fll;
vector f(61, vector(61, vector(30, i64(inf))));
vector g(61, vector(61, i64(inf)));
bool first = true;

void init() {
    if (first) first = false;
    else return;
    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < f[0].size(); j++) {
            for (int k = 0; k < f[0][0].size(); k++) {
                if (i + j == 0) f[i][j][k] = 0;
                else if (k) {
                    cmin(f[i][j][k], f[i][j][k - 1]);
                    if (i >= k) cmin(f[i][j][k], f[i - k][j][k - 1] + (1ll << k));
                    if (j >= k) cmin(f[i][j][k], f[i][j - k][k - 1] + (1ll << k));
                }
            }
        }
    }
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            for (int k = 0; k < f[0][0].size(); k++) {
                cmin(g[i][j], f[i][j][k]);
            }
        }
    }
    //cout <<g[1][1] <<endl;
    dbg(g);
}

void go() {
    init();
    i64 x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    int l1 = 0, l2 = 0;
    if (x == 0 || y == 0) {
        l2 = bit_width(u64(x + y));
        cout << g[0][l2] << endl;
        return;
    }
    vector<int> a, b;
    while (x) {
        a.push_back(x % 2);
        x /= 2;
    }
    while (y) {
        b.push_back(y % 2);
        y /= 2;
    }
    int si = -1;
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[a.size() - 1 - i] == b[b.size() - 1 - i]) si = i;
        else break;
    }
    si++;
    l1 = a.size() - si;
    l2 = b.size() - si;
    cout <<l1 <<" " <<l2 <<endl;
    dbg(a);
    dbg(b);
    dbg(si, l1, l2);
    i64 res = inf;
    for (int i = 0; i < si; i++) {
        cmin(res, g[l1 + i][l2 + i]);
    }
    for (int i = a.size(); i < g.size(); i++) {
        for (int j = b.size(); j < g.size(); j++) {
            cmin(res, g[i][j]);
        }
    }
    cout <<g[1][2] <<endl;
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    local_go_m(go);
    return 0;
}
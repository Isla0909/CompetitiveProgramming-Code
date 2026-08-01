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
#include <array>
#define ff first
#define se second
#define endl '\n'
using namespace std;

using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void tell(int l, vector<int> &v)
{
    for(int i = l; i < (int)v.size(); i++)
        cout << v[i] << " \n"[i == (int)v.size() - 1];
}

bool cmp(const pair<i64, i64> &a, const pair<i64, i64> &b)
{
    return a.first * a.second < b.first * b.second;
}


string mul(string a, string b)
{
    vector<int> A(a.size()), B(b.size());
    vector<int> C(a.size() + b.size() + 1);

    // 倒序存储每一位
    for(int i = 0; i < (int)a.size(); i++)
        A[i] = a[a.size() - i - 1] - '0';

    for(int i = 0; i < (int)b.size(); i++)
        B[i] = b[b.size() - i - 1] - '0';

    // 模拟竖式乘法
    for(int i = 0; i < (int)a.size(); i++)
        for(int j = 0; j < (int)b.size(); j++)
            C[i + j] += A[i] * B[j];

    // 处理进位
    for(int i = 0; i < (int)C.size() - 1; i++)
    {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }

    // 去掉高位多余的 0
    while(C.size() > 1 && C.back() == 0)
        C.pop_back();

    string res;

    // 转回正常顺序
    for(int i = (int)C.size() - 1; i >= 0; i--)
        res += char(C[i] + '0');

    return res;
}

// 高精度除以普通整数
string divide(string a, i64 b)
{
    string res;
    i64 now = 0;

    for(char ch : a)
    {
        now = now * 10 + ch - '0';

        if(!res.empty() || now >= b)
            res += char(now / b + '0');
        now %= b;
    }

    if(res.empty()) return "0";
    return res;
}

// 判断高精度整数 a 是否大于 b
bool bigger(const string &a, const string &b)
{
    if(a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    i64 king_a, king_b;
    cin >>king_a >>king_b;

    vector<pair<i64, i64>> v(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin() + 1, v.end(), cmp);

    string sum = to_string(king_a);

    string ans = "0";

    for(int i = 1; i <= n; i++)
    {
        string now = divide(sum, v[i].second);

        if(bigger(now, ans)) ans = now;
        // 当前大臣加入前缀
        sum = mul(sum, to_string(v[i].first));
    }

    cout <<ans <<endl;
    return 0;
}

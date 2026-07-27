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
#define ff first
#define se second
#define endl '\n'
using namespace std;
using i32 = signed;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
constexpr long long inf = 1e18;

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct AhoCorasick
{
	static constexpr int ALPHABET = 26;
	struct Node
	{
		int len;
		int fail;//失配指针
		int link;//后缀链接
		array<int, ALPHABET> next;
		int cnt;
		int siz;

		Node() : fail{}, link{}, next{}, cnt{}, siz{} {}
	};

	vector<Node> t;

	void initial()
	{
		t.assign(2, Node());
		t[0].next.fill(1);//0作为哨兵,保证指向根节点1
		t[0].len = -1, t[0].link = 1;
		t[1].len = 0;	
	}

	AhoCorasick()
	{
		initial();
	}

	int newNode()
	{
		t.emplace_back();
		return t.size() - 1;
	}

	int add(const vector<int> &a)
	{
		int p = 1;
		for(auto x : a)
		{
			if(t[p].next[x] == 0)
			{
				t[p].next[x] = newNode();
				t[t[p].next[x]].len = t[p].len + 1;
			}
			p = t[p].next[x];
		}
		t[p].cnt ++;
		return p;
	}
	int add(const string &s, char offset = 'a')
	{
		vector<int> a(s.size());
		for(int i = 0; s[i]; i ++)
			a[i] = s[i] - offset;
		return add(a);
	}

	void work()
	{
		queue<int> q;
		q.push(1);

		while(q.size())
		{
			auto x = q.front(); q.pop();

			for(int i = 0; i < ALPHABET; i ++)
			{
				if(t[x].next[i] == 0)//son不存在,看fail的son
					t[x].next[i] = t[t[x].fail].next[i];
				else//son存在
				{
					//son的fail指向fail的son
					t[t[x].next[i]].fail = t[t[x].fail].next[i];
					//son的fail有意义吗? 有 -> fail : 无 -> fail的link
					t[t[x].next[i]].link = t[t[t[x].next[i]].fail].cnt > 0 ? t[t[x].next[i]].fail : t[t[t[x].next[i]].fail].link;
					q.push(t[x].next[i]);
				}
			}
		}
	}

	int next(int p, int x)
	{
		return t[p].next[x];
	}
	int next(int p, char c, char offset = 'a')
	{
		return next(p, c - offset);
	}
	int fail(int p)
	{
		return t[p].fail;
	}
	int link(int p)
	{
		return t[p].link;
	}
	int len(int p)
	{
		return t[p].len;
	}
	int size()
	{
		return t.size();
	}
	
	void calc(const string &s, char offset = 'a')
	{
	    int p = 1;
	    for(auto c : s)
	    {
	        p = next(p, c);
	        t[p].siz ++;
	    }
	}
	
	void FailTree()
	{
	    vector<int> node;
	    for(int i = 2; i < t.size(); i ++)
	        node.push_back(i);
	    sort(node.begin(), node.end(), [&](int a, int b){ return t[a].len > t[b].len; });
	    for(auto u : node)
	    {
	        int f = t[u].link;
	        if(f > 1) t[f].siz += t[u].siz;
	    }
	}
};

template <class T>
constexpr T power(T a, i64 b)
{
    assert(b >= 0);
    T ans = 1;
    while(b)
    {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

constexpr i64 mul(i64 a, i64 b, i64 p)
{
    i64 ans = a * b - i64(1.L * a * b / p) * p;
    ans %= p;

    if(ans < 0) ans += p;
    return ans;
}

template <i64 P>
struct MLong
{
    i64 x; //x ≡ value (mod Mod)
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x_) : x{norm(x_ % getMod())} {}

    static i64 Mod;
    constexpr static i64 getMod()
    {
        //P > 0为静态档, P <= 0为动态档, 模数是Mod
        return P > 0 ? P : Mod;
    }
    //动态修改Mod -> Z::setMod(p)
    constexpr static void setMod(i64 Mod_)
    {
        Mod = Mod_;
    }
    //归一化处理
    constexpr i64 norm(i64 x) const//const保证限制成员变量不被修改 
    {
        if(x < 0) x += getMod();
        if(x >= getMod()) x -= getMod();
        return x;
    }
    constexpr i64 val() const
    {
        return x;
    }
    explicit constexpr operator i64() const
    {
        return x;
    }
    constexpr MLong operator-() const
    {
        MLong ans;
        ans.x = norm(getMod() - x);
        return ans;
    }
    constexpr MLong inv() const
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong &operator*=(MLong rhs) &//right-hand side右操作数
    {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) &
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) &
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) &
    {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs)//虽然不是私有成员,加上friend便于以后的维护
    {
        MLong ans = lhs;
        ans *= rhs;
        return ans;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs)
    {
        MLong ans = lhs;
        ans += rhs;
        return ans;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs)
    {
        MLong ans = lhs;
        ans -= rhs;
        return ans;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs)
    {
        MLong ans = lhs;
        ans /= rhs;
        return ans;
    }
    friend constexpr istream &operator>>(istream &is, MLong &a)
    {
        i64 v;
        is >>v;
        a = MLong(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MLong &a)
    {
        return os<< a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs)
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs)
    {
        return lhs.val() != rhs.val();
    }
};

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x_) : x{norm(x_ % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        return P > 0 ? P : Mod;
    }
    constexpr static void setMod(int Mod_) 
    {
        Mod = Mod_;
    }
    constexpr int norm(int x) const 
    {
        if (x < 0) x += getMod();
        if (x >= getMod()) x -= getMod();
        return x;
    }
    constexpr int val() const 
    {
        return x;
    }
    explicit constexpr operator int() const 
    {
        return x;
    }
    constexpr MInt operator-() const 
    {
        MInt ans;
        ans.x = norm(getMod() - x);
        return ans;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt ans = lhs;
        ans *= rhs;
        return ans;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt ans = lhs;
        ans += rhs;
        return ans;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt ans = lhs;
        ans -= rhs;
        return ans;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt ans = lhs;
        ans /= rhs;
        return ans;
    }
    friend constexpr istream &operator>>(istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) 
    {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) 
    {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) 
    {
        return lhs.val() != rhs.val();
    }
};

constexpr int M1 = 998244353, M2 = 1e9 + 7;
constexpr i64 M3 = i64(1e18) + 9;
using Z = MInt<M2>;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	AhoCorasick ac;
	int n, m; cin >>n >>m;
	vector<int> end(n);
    for (int i = 0; i < n; i ++) 
    {
        string s; cin >> s;
        end[i] = ac.add(s);
    }

    ac.work();

    while(m --) 
    {
        string s; cin >> s;
        int len = s.size();
        Z ans = 0;
        int p = 1;
        for(int i = 0; i < s.size(); i ++) 
        {
            p = ac.next(p, s[i]);

            for(int u = p; u > 1; u = ac.link(u)) 
            {
                if(ac.t[u].cnt > 0) 
                {
                    int L = ac.t[u].len;
                    int l = i - L + 2; 
                    int r = i + 1; 
                    if(l >= 1) 
                    {
                        Z res = Z(l) * Z(len - r + 1);
                        ans += res * Z(ac.t[u].cnt);
                    }
                }
            }
        }
        cout <<ans <<endl;
    }
	return 0;
}
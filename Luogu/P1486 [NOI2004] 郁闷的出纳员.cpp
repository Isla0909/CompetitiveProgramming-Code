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

struct FHQ_Treap
{
	struct node
	{
		int l, r;
		i64 val;
		int rng;
		int siz;
	}tr[N << 2];

	int root = 0, tot = 0;

    void initial()
    {
        root = 0;
        tot = 0;
    }
    
	int newNode(i64 v)
	{
		++ tot;
		tr[tot].l = tr[tot].r = 0;
		tr[tot].val = v;
		tr[tot].rng = rng();
		tr[tot].siz = 1;
		return tot;
	}

	void pushup(int p)
	{
		tr[p].siz = tr[tr[p].l].siz + tr[tr[p].r].siz + 1;
	}

	//按值 v 进行分裂, 左子树 <=v, 右子树 > v
    //x, y 是分裂后的两颗子树的根, 执行完成后 x.val <= v < y.val

    void split(int p, i64 v, int &x, int &y)
    {
    	if(!p)
    	{
    		x = y = 0;
    		return ;
    	}

    	if(tr[p].val <= v)
    	{
    		//递归分裂 p 的右子树
            //左子树的根 x 已确定, y 需要继续向下带
            //同时, p 的右节点需要指向下一层指向的左子树的根 x
    		x = p;
    		split(tr[p].r, v, tr[p].r, y);	
    	}
    	else
    	{
    		y = p;
    		split(tr[p].l, v, x, tr[p].l);
    	}
    	pushup(p);
    }

    //按堆的随机值合并两颗子树, 返回合并后的根
    //要求 x 树所有节点的 val 要 <= y 树所有节点的 val 值!!!
    int merge(int x, int y)
    {
    	if(!x || !y) return x + y;

    	if(tr[x].rng < tr[y].rng)
    	{
    		tr[x].r = merge(tr[x].r, y);
    		pushup(x);
    		return x;
    	}
    	else
    	{
    		tr[y].l = merge(x, tr[y].l);
    		pushup(y);
    		return y;
    	}
    }

    int siz()
    {
    	return tr[root].siz;
    }

    void insert(i64 v)
    {
    	int x, y;
    	split(root, v, x, y);
    	int p = newNode(v);
    	root = merge(merge(x, p), y);
    }

    void del(int v)
    {
    	int x, y, z;
    	//x <= v < z
    	split(root, v, x, z);
    	//x <= v - 1 < y <= v
    	split(x, v - 1, x, y);

    	y = merge(tr[y].l, tr[y].r);
    	root = merge(merge(x, y), z);
    }

    //此处排名的定义是 < v 的个数 + 1
    int rank(int v)
    {
    	int x, y;
    	split(root, v - 1, x, y);
    	int ans = tr[x].siz + 1;
    	root = merge(x, y);
    	return ans;
    }

    //从子树 p 找第 k 小
    i64 topk(int p, int k)
    {
    	int l_siz = tr[tr[p].l].siz;
    	if(l_siz == k - 1) return tr[p].val;
    	if(k <= l_siz) return topk(tr[p].l, k);
    	return topk(tr[p].r, k - l_siz - 1);
    }

    //前驱, 严格 < v 的值, 不存在返回 -1
    int get_pre(int v)
    {
    	int x, y, ans = -1;
    	split(root, v - 1, x, y);
    	if(x) ans = topk(x, tr[x].siz);
    	root = merge(x, y);
    	return ans;
    }
    //后继, 严格 > v 的值, 不存在返回 -1
    int get_suf(int v)
    {
    	int x, y, ans = -1;
    	split(root, v, x, y);
    	if(y) ans = topk(y, 1);
    	root = merge(x, y);
    	return ans;
    }

    int erase(i64 lim)
    {
    	int x, y;

    	split(root, lim - 1, x, y);
    	int res = tr[x].siz;

    	root = y;
    	return res;
    }
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; i64 lim; cin >>n >>lim;
	FHQ_Treap fhq;
	i64 add = 0, leave = 0;
	for(int i = 0; i < n; i ++)
	{
		char op; cin >>op;
		if(op == 'I')
		{
			i64 x; cin >>x;
			if(x >= lim) fhq.insert(x - add);
		}
		else if(op == 'A')
		{
			int delta; cin >>delta;
			add += delta;
		}
		else if(op == 'S')
		{
			int delta; cin >>delta;
			add -= delta;

			leave += fhq.erase(lim - add);
		}
		else
		{
			int k; cin >>k;
			int siz = fhq.siz();
			if(k > siz) cout <<-1 <<endl;
			else
			{
				int idx = siz - k + 1;
				cout <<fhq.topk(fhq.root, idx) + add <<endl;
			}
		}
	}
	cout <<leave <<endl;
	return 0;
}

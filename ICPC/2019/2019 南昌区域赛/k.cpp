#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f64 = long double;
using i128 = __int128;
using f128 = __float128;

#define int long long
const i64 inf = 1e18;


namespace pb = __gnu_pbds;
template <class T, class Cmp = std::less_equal<T>>
// Cmp传std::less<T>就是Set 传std::less_equal<T>就是multiset
struct RedBlackTree
{
    const T inf = std::numeric_limits<T>::max() / 2;
    using Tree = pb::tree<T, pb::null_type, Cmp, pb::rb_tree_tag, pb::tree_order_statistics_node_update>;
    Tree tree;
    RedBlackTree() {}
    void insert(T x)
    {
        tree.insert(x);
    }
    void eraseOne(T x)
    {
        auto it = tree.find_by_order(tree.order_of_key(x));
        if (it != tree.end() and *it == x)
        {
            tree.erase(it);
        }
    }
    // 3 2 2 1 1
    int getRank(T x) // 默认最大的为rank1 相同元素我最大
    {
        return tree.size() - tree.order_of_key(x + 1) + 1;
    }
    T getVal(int rank)
    {
        return *tree.find_by_order(tree.size() - rank);
    }
    int getAntiRank(T x)
    {
        return tree.order_of_key(x) + 1;
    }
    T getAntiVal(int rank)
    {
        return *tree.find_by_order(rank - 1);
    }
};
int k;
template <class T>
struct DSUOnTree{
    int n;
    vector<vector<pair<int, int>>> g;
    vector<int> siz, son, dep, v;
    vector<T> ans;
    int root;
    int heavyNode = 0; 
    int res = 0;
    vector<RedBlackTree<int>> pos; 
    DSUOnTree(vector<vector<pair<int, int>>> &g, vector<int> &v, int root) 
        : n(g.size() - 1), g(g),v(v), siz(n + 1), dep(n + 1), son(n + 1), ans(n + 1), 
            root(root), pos(n+1) {}
    void preProcess(int u, int f){
        siz[u] = 1;dep[u] = dep[f]+1;
        for (auto [v, w] : g[u]){
            if (v != f){
                preProcess(v, u);
                siz[u] += siz[v];
                if (siz[son[u]] < siz[v]){
                    son[u] = v;
                }
            }
        }
    }

    void update(int u, int f, int val,int rt){
        if (val == 1)
        {
            int ndv = v[rt]*2-v[u];
            if(ndv>n || ndv<0) return ;
            int ndd = k+dep[rt]*2-dep[u];
            res += pos[ndv].getAntiRank(ndd+1)-1;
            // cout<<v[u]<<" "<<ndv<<" "<<ndd<<"=--=\n";
            // for(int i = 0;i<5;i++){
            //     cout<<pos[ndv].getVal(i)<<" ";
            // }
            // cout<<"=======\n";
        }else if (val == 2)
        {
            pos[v[u]].insert(dep[u]);
        }
        else
        {
            pos[v[u]].eraseOne(dep[u]);
        }
    }
    // 遍历子树统计/清除信息
    void traverse(int u, int f, int val,int rt){
        update(u, f, val,rt);
        for (auto [v, w] : g[u]){
            if (v != f && v != heavyNode){
                traverse(v, u, val,rt);
            }
        }
    }
    void solve(int u, int f, bool keep){
        // 1. 先处理轻儿子（不保留信息）
        for (auto [v, w] : g[u]){
            if (v != f && v != son[u]){
                solve(v, u, false);
            }
        }
        // 2. 处理重儿子（保留信息）
        if (son[u]){
            solve(son[u], u, true);
            heavyNode = son[u];
        }
        // 3. 再次遍历轻儿子并合并信息
        for (auto [v, w] : g[u]){
            if (v != f && v != son[u]) {
                traverse(v, u, 1,u);
                traverse(v, u, 2,u);
            }
        }
        update(u, f, 2,u); 
        ans[u] = res;
        heavyNode = 0;
        if (!keep){
            traverse(u, f, -1,u);
            res = 0;
        }
    }
    // 对外接口
    void compute()
    {
        preProcess(root, 0); // 假设根节点是1
        solve(root, 0, true);
    }
};

void init(){}
#define MultiTest   0
void solve(){
    int n;cin>>n>>k;
    vector<int> v(n+1);
    for(int i = 1;i<=n;i++){
        cin>>v[i];
    }
    vector<vector<pair<int,int>>> e(n+1);
    for(int i = 2;i<=n;i++){
        int x;cin>>x;
        e[i].emplace_back(x,1);
        e[x].emplace_back(i,1);
    }
    DSUOnTree<int> slv(e,v,1);

    slv.compute();
    auto& ans = slv.ans;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        sum += ans[i];
    }
    cout<< sum*2<<"\n";
}

signed main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    init();
     
    solve();
    return 0;
}
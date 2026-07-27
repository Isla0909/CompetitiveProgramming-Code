#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

// 线段树节点：存储区间最大值和最大值的最左位置
struct Node {
    int max_val;
    int pos;
} tree[4 * MAXN];

// 构建线段树
void build(int node, int l, int r, const vector<int>& a) {
    if (l == r) {
        tree[node].max_val = a[l];
        tree[node].pos = l;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid, a);
    build(node * 2 + 1, mid + 1, r, a);
    // 取最大值，若相等则取位置更左的
    if (tree[node * 2].max_val > tree[node * 2 + 1].max_val) {
        tree[node].max_val = tree[node * 2].max_val;
        tree[node].pos = tree[node * 2].pos;
    } else if (tree[node * 2].max_val < tree[node * 2 + 1].max_val) {
        tree[node].max_val = tree[node * 2 + 1].max_val;
        tree[node].pos = tree[node * 2 + 1].pos;
    } else {
        // 最大值相等时，取位置更左的
        tree[node].max_val = tree[node * 2].max_val;
        tree[node].pos = min(tree[node * 2].pos, tree[node * 2 + 1].pos);
    }
}

// 查询区间[ql, qr]的最大值及其最左位置
pair<int, int> query_max(int node, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) {
        return {INT_MIN, -1}; // 超出范围，返回无效值
    }
    if (ql <= l && r <= qr) {
        return {tree[node].max_val, tree[node].pos};
    }
    int mid = (l + r) / 2;
    auto left = query_max(node * 2, l, mid, ql, qr);
    auto right = query_max(node * 2 + 1, mid + 1, r, ql, qr);
    
    // 比较左右区间的最大值，选择更大的；若相等则选择位置更左的
    if (left.first > right.first) {
        return left;
    } else if (left.first < right.first) {
        return right;
    } else {
        // 最大值相等时，返回位置更左的
        if (left.first == INT_MIN) return right;
        return (left.second < right.second) ? left : right;
    }
}

// 更新指定位置的值
void update(int node, int l, int r, int pos, int new_val) {
    if (l == r) {
        tree[node].max_val = new_val;
        tree[node].pos = pos;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(node * 2, l, mid, pos, new_val);
    } else {
        update(node * 2 + 1, mid + 1, r, pos, new_val);
    }
    // 更新当前节点的最大值和位置
    if (tree[node * 2].max_val > tree[node * 2 + 1].max_val) {
        tree[node].max_val = tree[node * 2].max_val;
        tree[node].pos = tree[node * 2].pos;
    } else if (tree[node * 2].max_val < tree[node * 2 + 1].max_val) {
        tree[node].max_val = tree[node * 2 + 1].max_val;
        tree[node].pos = tree[node * 2 + 1].pos;
    } else {
        // 最大值相等时，取位置更左的
        tree[node].max_val = tree[node * 2].max_val;
        tree[node].pos = min(tree[node * 2].pos, tree[node * 2 + 1].pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1); // 使用1-based索引
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n, a);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        vector<pair<int, int>> changes; // 记录修改记录，用于回滚

        int current_k = 0;
        while (current_k < k) {
            auto [max_val, pos] = query_max(1, 1, n, l, r);
            if (max_val == 0) break; // 最大值为0，后续操作无意义
            int new_val = max_val / 2; // 向下取整
            changes.emplace_back(pos, max_val); // 记录原始值，用于回滚
            update(1, 1, n, pos, new_val);
            current_k++;
        }

        // 输出操作后的区间最大值
        cout << query_max(1, 1, n, l, r).first << '\n';

        // 回滚本次查询的所有修改，不影响其他查询
        for (auto [pos, old_val] : changes) {
            update(1, 1, n, pos, old_val);
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 定义边的结构体
struct Edge {
    int to;
    long long weight;
};

// 全局变量
int N, M;
vector<vector<Edge>> graph;
long long minXor = LLONG_MAX;

// 深度优先搜索函数
void dfs(int current, int target, long long currentXor, vector<bool>& visited) {
    // 如果当前顶点是目标顶点（顶点 N）
    if (current == target) {
        // 更新最小异或值
        minXor = min(minXor, currentXor);
        return;
    }
    // 标记当前顶点为已访问
    visited[current] = true;
    // 遍历当前顶点的所有邻接顶点
    for (const Edge& edge : graph[current]) {
        int next = edge.to;
        // 如果邻接顶点未被访问
        if (!visited[next]) {
            // 递归调用 dfs 函数，更新异或值
            dfs(next, target, currentXor ^ edge.weight, visited);
        }
    }
    // 回溯，将当前顶点标记为未访问
    visited[current] = false;
}

int main() {
    // 读取顶点数 N 和边数 M
    cin >> N >> M;
    // 初始化图的邻接表
    graph.resize(N + 1);
    // 读取每条边的信息
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // 无向图，添加两条边
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    // 初始化访问标记数组
    vector<bool> visited(N + 1, false);
    // 从顶点 1 开始进行深度优先搜索，初始异或值为 0
    dfs(1, N, 0, visited);
    // 输出最小异或值
    cout << minXor << endl;

    return 0;
}
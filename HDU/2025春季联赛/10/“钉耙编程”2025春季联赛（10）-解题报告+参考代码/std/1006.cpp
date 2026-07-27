#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define M 1000005
#define N 100005
using namespace std;
struct E {
  int to, nx, d;
} edge[M * 4];
int tot, head[6 * N];
void Addedge(int a, int b, int d) {
  edge[++tot].to = b;
  edge[tot].d = d;
  edge[tot].nx = head[a];
  head[a] = tot;
}
#define INF 1000000000000000000
void check_min(int &x, int y) {
  if (x > y) x = y;
}
void check_min(long long &x, long long y) {
  if (x > y) x = y;
}
int n, m, x;
int A[N];
struct node {
  int id;
  long long d;
  bool operator<(const node &_) const { return d > _.d; }
};
bool done[N * 6];
long long dis[N * 6];
void Solve() {
  for (int i = 1; i <= 6 * n; i++) {
    dis[i] = INF;
    done[i] = false;
  }
  dis[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      Addedge(i + j * n, A[i] + 3 * n + ((j + 1) % 3) * n, x);
      Addedge(A[i] + 3 * n + ((j + 1) % 3) * n, i + ((j + 1) % 3) * n, 0);
    }
  }
  long long ans = -1;
  //	for(int i=0;i<3;i++)printf("%d
  //(%lld)",ST[i].tree[1].mn_id,ST[i].tree[1].d);puts(""); 	return ;
  priority_queue<node> Q;
  Q.push((node){1, 0});
  while (!Q.empty()) {
    int now = Q.top().id;
    Q.pop();
    if (done[now]) continue;
    done[now] = true;
    for (int i = head[now]; i; i = edge[i].nx) {
      int nxt = edge[i].to;
      if (dis[nxt] > dis[now] + edge[i].d) {
        dis[nxt] = dis[now] + edge[i].d;
        Q.push((node){nxt, dis[nxt]});
      }
    }
  }
  //	printf("cnt=%d\n",cnt);
  // printf("%lld\n",ans);
  if (dis[n] < INF)
    printf("%lld\n", dis[n]);
  else
    puts("-1");
}
int main() {
  //	freopen("data.in","r",stdin);
  //	freopen("data.out","w",stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    tot = 0;
    for (int i = 1; i <= 6 * n; i++) head[i] = 0;
    while (m--) {
      int a, b, d;
      scanf("%d%d%d", &a, &b, &d);
      for (int i = 0; i < 3; i++) {
        Addedge(a + i * n, b + ((i + 1) % 3) * n, d);
      }
    }
    Solve();
  }
  return 0;
}
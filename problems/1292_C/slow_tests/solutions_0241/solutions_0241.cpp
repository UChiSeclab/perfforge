#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int _w;
int dis[N][N], n, head[N], siz[N], fa[N], eidx;
long long f[N][N], ans;
struct Edge {
  int nxt, to;
} edge[N << 1];
void addedge(int u, int v) {
  edge[++eidx] = (Edge){head[u], v};
  head[u] = eidx;
  edge[++eidx] = (Edge){head[v], u};
  head[v] = eidx;
}
void dfs(int u, int* dis) {
  siz[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt)
    if (edge[i].to != fa[u]) {
      fa[edge[i].to] = u;
      dis[edge[i].to] = dis[u] + 1;
      dfs(edge[i].to, dis);
      siz[u] += siz[edge[i].to];
    }
}
long long dp(int x, int y) {
  if (~f[x][y]) return f[x][y];
  long long& res = f[x][y];
  res = 0;
  int d = dis[x][y];
  for (int i = head[x]; i; i = edge[i].nxt)
    if (dis[edge[i].to][y] < d) res = max(res, dp(edge[i].to, y));
  for (int i = head[y]; i; i = edge[i].nxt)
    if (dis[edge[i].to][x] < d) res = max(res, dp(x, edge[i].to));
  int fx = fa[x], fy = fa[y], a = 0, b = 0;
  if (dis[fx][y] < d)
    a = siz[x];
  else {
    for (int i = head[x]; i; i = edge[i].nxt)
      if (dis[edge[i].to][y] < d && edge[i].to != fx) a = n - siz[edge[i].to];
  }
  if (dis[fy][x] < d)
    b = siz[y];
  else {
    for (int i = head[y]; i; i = edge[i].nxt)
      if (dis[edge[i].to][x] < d && edge[i].to != fy) b = n - siz[edge[i].to];
  }
  res += a * b;
  return res;
}
int main(void) {
  _w = scanf("%d", &n);
  for (int i = 1, u, v; i < n; ++i) {
    _w = scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  memset(f, -1, sizeof f);
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= n; ++i) {
    f[i][i] = 0;
    fa[i] = 0;
    dis[i][i] = 0;
    dfs(i, dis[i]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) ans = max(ans, dp(i, j));
  cout << ans;
  return 0;
}

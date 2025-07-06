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

void check_dfs_invariant(int depth, int branchingFactor) {
    if (depth > 50 && branchingFactor > 10) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void dfs(int u, int* dis) {
  siz[u] = 1;
  int branchingFactor = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    branchingFactor++;
    if (edge[i].to != fa[u]) {
      fa[edge[i].to] = u;
      dis[edge[i].to] = dis[u] + 1;
      check_dfs_invariant(dis[edge[i].to], branchingFactor); // Check for high depth and branching
      dfs(edge[i].to, dis);
      siz[u] += siz[edge[i].to];
    }
  }
}

void check_dp_invariant(int calculationCount) {
    if (calculationCount > 100000) {
        cerr << "Warning: dp_invariant triggered - extensive DP recursion" << endl;
        abort();
    }
}

long long dp(int x, int y) {
  if (~f[x][y]) return f[x][y];
  long long& res = f[x][y];
  res = 0;
  int d = dis[x][y];
  int calculations = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    if (dis[edge[i].to][y] < d) {
      res = max(res, dp(edge[i].to, y));
      calculations++;
    }
  }
  for (int i = head[y]; i; i = edge[i].nxt) {
    if (dis[edge[i].to][x] < d) {
      res = max(res, dp(x, edge[i].to));
      calculations++;
    }
  }
  check_dp_invariant(calculations); // Check for extensive DP recursion

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

void check_pair_computation_invariant(int n) {
    if (n * n > 1000000) {
        cerr << "Warning: pair_computation_invariant triggered - excessive pairwise processing" << endl;
        abort();
    }
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
  
  check_pair_computation_invariant(n); // Check pairwise computations before heavy loop
  
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) ans = max(ans, dp(i, j));
  
  cout << ans;
  return 0;
}
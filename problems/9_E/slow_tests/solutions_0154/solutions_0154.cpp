#include <bits/stdc++.h>
using namespace std;
int g[51][51];
bool vis[51];
int deg[51];
int n, m;
bool has_cir;
void dfs(int u, int f) {
  vis[u] = true;
  for (int i = 1; i <= n; i++) {
    if (g[u][i] && i != f || g[u][i] >= 2) {
      if (vis[i])
        has_cir = true;
      else
        dfs(i, u);
    }
  }
}
bool check() {
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 2) return false;
  }
  int comp = 0;
  memset(vis, false, sizeof(vis));
  has_cir = false;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      comp++;
      dfs(i, -1);
    }
  }
  if (comp > 1 && has_cir) return false;
  return true;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 2 && m == 0) {
      printf("YES\n2\n");
      printf("1 2\n1 2\n");
      continue;
    }
    memset(g, 0, sizeof(g));
    memset(deg, 0, sizeof(deg));
    int a, b;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      g[a][b]++;
      g[b][a]++;
      deg[a]++;
      deg[b]++;
    }
    if (!check()) {
      printf("NO\n");
    } else {
      vector<int> a, b;
      printf("YES\n");
      printf("%d\n", n - m);
      for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
          g[i][j]++;
          g[j][i]++;
          deg[i]++;
          deg[j]++;
          if (check()) {
            a.push_back(i);
            b.push_back(j);
          } else {
            deg[i]--;
            deg[j]--;
            g[i][j]--;
            g[j][i]--;
          }
        }
      }
      for (int i = 0; i < a.size(); i++) printf("%d %d\n", a[i], b[i]);
    }
  }
  return 0;
}

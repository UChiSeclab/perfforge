#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 55;
struct edge {
  int from, val;
};
vector<edge> G[N];
int r[N];
char c[N];
bool vis[N][2505];
int f[N][2505];
int n, s, k;
int ans = 2e9;
int ABS(int x) {
  if (x > 0) return x;
  return -x;
}
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2500; j++) {
      f[i][j] = 2e9;
    }
    f[i][r[i]] = ABS(i - s);
  }
  f[s][0] = 0;
}
int dfs(int x, int y) {
  if (y >= k) ans = min(ans, f[x][y]);
  if (f[x][y] != 2e9 || vis[x][y]) {
    vis[x][y] = true;
    return f[x][y];
  }
  for (int i = 0; i < int(G[x].size()); i++) {
    int from = G[x][i].from;
    if (y - r[x] < 0) continue;
    f[x][y] = min(f[x][y], dfs(from, y - r[x]) + G[x][i].val);
  }
  if (y >= k) ans = min(ans, f[x][y]);
  vis[x][y] = true;
  return f[x][y];
}
int main() {
  n = read(), s = read(), k = read();
  for (int i = 1; i <= n; i++) r[i] = read();
  init();
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i] == c[j] || r[i] >= r[j]) continue;
      G[j].push_back((edge){i, ABS(i - j)});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = k; j <= 2500; j++) {
      dfs(i, j);
    }
  }
  printf("%d\n", ans == 2e9 ? -1 : ans);
  return 0;
}

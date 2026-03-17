#include <bits/stdc++.h>
const int N = 55;
using namespace std;
int n, s, k;
vector<int> g[N];
char c[N];
int r[N], b, cnt[N];
int f[N][N * N];
int p(int x) {
  if (x < n)
    return x;
  else
    return s;
}
void dfs(int x, int y) {
  if (x == n && y == 0) {
    f[x][y] = 0;
    return;
  } else if (x == n) {
    f[x][y] = 100000;
    return;
  }
  if (f[x][y] != -1) return;
  int i, mint = 100000;
  for (i = 0; i < g[x].size(); i++) {
    dfs(g[x][i], y - r[x]);
    mint = min(mint, f[g[x][i]][y - r[x]] + abs(p(x) - p(g[x][i])));
  }
  f[x][y] = mint;
}
int main() {
  int i, j, sum = 0;
  scanf("%d%d%d", &n, &s, &k);
  s--;
  for (i = 0; i < n; i++) {
    scanf("%d", &r[i]);
    sum += r[i];
  }
  scanf("%s", c);
  c[n] = 'A';
  r[n] = 0;
  for (i = 0; i <= n; i++)
    for (j = 0; j < n; j++)
      if (r[i] < r[j] && c[i] != c[j]) {
        g[j].push_back(i);
        cnt[i]++;
      }
  memset(f, -1, sizeof(f));
  int ans = 100000;
  for (i = 0; i <= n; i++)
    if (cnt[i] == 0) {
      for (j = k; j <= sum; j++) {
        dfs(i, j);
        if (f[i][j] < ans) ans = f[i][j];
      }
    }
  if (ans < 100000)
    printf("%d\n", ans);
  else
    printf("-1\n");
  return 0;
}

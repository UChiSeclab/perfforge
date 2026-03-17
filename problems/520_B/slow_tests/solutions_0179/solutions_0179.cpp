#include <bits/stdc++.h>
using namespace std;
int n, m, f[30010];
void dfs(int w, int t) {
  if (w <= 0 || w >= m * 2) return;
  if (f[w] <= t) return;
  f[w] = t;
  dfs(w * 2, t + 1);
  dfs(w - 1, t + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  memset(f, 60, sizeof(f));
  if (n >= m)
    printf("%d\n", n - m);
  else {
    dfs(n, 0);
    printf("%d\n", f[m]);
  }
  return 0;
}

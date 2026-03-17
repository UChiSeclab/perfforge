#include <bits/stdc++.h>
struct node {
  int x, y;
};
long long fac[200005], inv[200005], ans[2005];
int n, m, k;
node f[2005];
long long fp(long long x, int y) {
  return (y % 2 ? x : 1ll) * (y / 2 ? fp(x * x % 1000000007, y / 2) : 1ll) %
         1000000007;
}
void pre(int n) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 1000000007;
  for (int i = 1; i <= n; i++) inv[i] = fp(fac[i], 1000000007 - 2);
}
long long c(int x, int y) {
  return fac[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}
int cmp(node x, node y) { return x.x != y.x ? x.x < y.x : x.y < y.y; }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  pre(n + m);
  for (int i = 1; i <= k; i++) scanf("%d%d", &f[i].x, &f[i].y);
  f[++k] = node{n, m};
  std::sort(f + 1, f + k + 1, cmp);
  for (int i = 1; i <= k; i++) {
    long long s = c(f[i].x + f[i].y - 2, f[i].x - 1);
    for (int j = 1; j <= i - 1; j++)
      if (f[j].x <= f[i].x && f[j].y <= f[i].y)
        s = (s -
             ans[j] * c(f[i].x + f[i].y - f[j].x - f[j].y, f[i].x - f[j].x) %
                 1000000007 +
             1000000007) %
            1000000007;
    ans[i] = s;
  }
  printf("%lld\n", ans[k]);
  return 0;
}

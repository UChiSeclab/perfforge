#include <bits/stdc++.h>
const int MAXN = 11000;
long long f[MAXN], g[MAXN];
int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  memset(f, 0, sizeof(f));
  for (int i = 0; i <= b && i <= n; i++) {
    f[i] = 1;
  }
  memset(g, 0, sizeof(g));
  for (int i = 0; i <= b && i <= n; i++) {
    for (int j = 0; j <= c && i + j * 2 <= n; j++) {
      g[i + j * 2] += f[i];
    }
  }
  long long res = 0LL;
  for (int i = 0; i <= n; i++) {
    if ((n - i) * 2 <= a) {
      res += g[i];
    }
  }
  printf("%lld\n", res);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, M = 1e5;
int n, x[N], y[N], fac[N], vis[N], last[N];
int main() {
  int n, mx = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int k = 1; k <= n; k++) {
    int a = x[k], pn = 0;
    for (int i = 1; i * i <= a; i++) {
      if (a % i == 0) {
        fac[++pn] = i;
        if (i * i != a) fac[++pn] = a / i;
      }
    }
    for (int i = 1; i <= pn; i++) vis[i] = 0;
    for (int i = 1; i <= pn; i++) {
      if (i == 1) {
        if (y[k]) vis[i] = 1;
        continue;
      }
      int b = fac[i];
      for (int j = b; j <= mx; j += b) {
        if (last[j] >= k - y[k]) {
          vis[i] = 1;
          break;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= pn; i++) {
      if (!vis[i]) ans++;
      last[fac[i]] = k;
    }
    printf("%d\n", ans);
    last[a] = k, mx = max(mx, a);
  }
  return 0;
}

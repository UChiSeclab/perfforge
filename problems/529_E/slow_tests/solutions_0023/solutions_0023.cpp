#include <bits/stdc++.h>
using namespace std;
const int INF = 2100000000;
int n, k, q, x, ans, i, t, L, a[100005];
map<int, int> M;
int main() {
  scanf("%d%d", &n, &L);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    ans = INF;
    M.clear();
    for (i = 1; i <= n; i++) {
      for (k = 1; k <= L; k++) {
        if (k * a[i] > x) continue;
        if (k * a[i] == x) {
          ans = k;
          continue;
        }
        t = M[x - k * a[i]];
        if (t && t + k <= L) ans = min(ans, M[x - k * a[i]] + k);
      }
      for (k = 1; k <= L; k++) {
        t = M[k * a[i]];
        if (!t || t > k) M[k * a[i]] = k;
      }
    }
    if (ans == INF)
      puts("-1");
    else
      printf("%d\n", ans);
  }
}

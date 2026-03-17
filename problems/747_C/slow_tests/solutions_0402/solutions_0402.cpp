#include <bits/stdc++.h>
using namespace std;
const int z = (int)1e5 + 111;
int t[z], k[z], d[z], dp[111], n, q, j;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) scanf("%d%d%d", &t[i], &k[i], &d[i]);
  for (int i = 1; i <= (int)1e6; i++) {
    int p = 0, ans = 0;
    while (t[j] < i) j++;
    if (j >= q) break;
    for (int i = 1; i <= n; i++) {
      if (dp[i]) dp[i]--;
      if (!dp[i]) p++;
    }
    if (t[j] > i) continue;
    if (k[j] <= p) {
      for (int i = 1; i <= n; i++)
        if (!dp[i] && k[j]) {
          ans += i;
          dp[i] = d[j];
          k[j]--;
        }
      cout << ans << '\n';
    } else
      cout << -1 << '\n';
  }
  return 0;
}

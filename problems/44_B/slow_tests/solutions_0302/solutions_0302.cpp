#include <bits/stdc++.h>
int dp[20005];
int n;
int cnt[3];
int main() {
  int i, j, a, b, c, v, k;
  scanf("%d%d%d%d", &n, &cnt[0], &cnt[1], &cnt[2]);
  n = n * 2;
  for (i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  for (i = 0; i < 3; i++) {
    if (i == 0)
      v = 1;
    else if (i == 1)
      v = 2;
    else
      v = 4;
    for (j = n; j >= 0; j--) {
      if (dp[j] != 0) {
        for (k = 1; k <= cnt[i]; k++) {
          if (j + k * v > n) break;
          dp[j + k * v] = dp[j + k * v] + dp[j];
        }
      }
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}

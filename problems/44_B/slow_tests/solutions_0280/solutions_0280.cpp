#include <bits/stdc++.h>
int dp[20001][4];
int a[3];
int main() {
  int N, sum;
  scanf("%d %d %d %d", &sum, &a[0], &a[1], &a[2]);
  sum <<= 1;
  N = 3;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int n = 0; n < N; ++n) {
    for (int s = 0; s < sum + 1; ++s) {
      for (int i = 0; i < a[n] + 1; ++i) {
        if (s < (1 << n) * i) break;
        dp[s][n + 1] += dp[s - (1 << n) * i][n];
      }
    }
  }
  printf("%d\n", dp[sum][N]);
  return 0;
}

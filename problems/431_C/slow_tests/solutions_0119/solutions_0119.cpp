#include <bits/stdc++.h>
using namespace std;
int ans;
int dp[2][202][202];
int n, k, d;
int main() {
  scanf("%d%d%d", &n, &k, &d);
  if (n >= d and n <= k) ans++;
  for (int i = 1; i <= k; i++) dp[0][i][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 1; l <= n; l++)
        for (int h = 1; h <= k; h++) {
          dp[1][l + j][max(h, j)] += dp[0][l][h];
          dp[1][l + j][max(h, j)] %= 1000000007;
        }
    }
    for (int j = d; j <= k; j++) ans = (ans + dp[1][n][j]) % 1000000007;
    memcpy(dp[0], dp[1], sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
  }
  printf("%d\n", ans);
}

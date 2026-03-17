#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, dp[12][1005][1005];
int f(int i, int a, int b) {
  if (a < 1 || b > n) return 0;
  if (i == m + 1) return 1;
  if (dp[i][a][b] != -1) return dp[i][a][b];
  int ans = (f(i, a + 1, b) + f(i, a, b - 1)) % MOD;
  ans = (ans - f(i, a + 1, b - 1) + MOD) % MOD;
  if (a <= b) ans = (ans + f(i + 1, a, b)) % MOD;
  return dp[i][a][b] = ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) dp[i][j][k] = -1;
  printf("%d\n", f(1, 1, n));
  return 0;
}

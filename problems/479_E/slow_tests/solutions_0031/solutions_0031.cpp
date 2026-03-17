#include <bits/stdc++.h>
using namespace std;
int n, a, b, k, dp[5010][5010], sum[5010][5010];
void mod_(int &x) {
  while (x > 1000000007) x -= 1000000007;
}
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  if (a > b) a = n - a + 1, b = n - b + 1;
  dp[a][0] = 1;
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i < b; i++)
      mod_(sum[i][j - 1] = sum[i - 1][j - 1] + dp[i][j - 1]);
    for (int i = 1; i < b; i++) {
      mod_(dp[i][j] += sum[i - 1][j - 1]);
      mod_(dp[i][j] +=
           (sum[(i + b - 1) / 2][j - 1] - sum[i][j - 1] + 1000000007) %
           1000000007);
    }
  }
  for (int i = 1; i <= b; i++) mod_(sum[i][k] = sum[i - 1][k] + dp[i][k]);
  printf("%d\n", sum[b][k]);
  return 0;
}

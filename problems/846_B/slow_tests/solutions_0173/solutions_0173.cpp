#include <bits/stdc++.h>
using namespace std;
int n, k;
long long m;
int t[50];
long long dp[50][2505];
int main(void) {
  scanf("%d%d%lld", &n, &k, &m);
  for (int i = 0; i < k; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n * (k + 1); j++) {
      dp[i][j] = 1000000000007;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i * (k + 1); j++) {
      if (dp[i][j] < 1000000000007) {
        long long cost = 0;
        for (int a = 0; a <= k; a++) {
          dp[i + 1][j + a + (a == k ? 1 : 0)] =
              min(dp[i + 1][j + a + (a == k ? 1 : 0)], dp[i][j] + cost);
          cost += (long long)t[a];
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= (k + 1) * n; i++) {
    if (m >= dp[n][i]) {
      res = max(res, i);
    }
  }
  printf("%d\n", res);
  return 0;
}

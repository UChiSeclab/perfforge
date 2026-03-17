#include <bits/stdc++.h>
using namespace std;
int n, k, m, x[50], ta;
long long dp[50 * 50 + 1];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) scanf("%d", x + i);
  sort(x + 1, x + k + 1);
  for (int i = 1; i <= k; i++) x[i] += x[i - 1];
  m++;
  dp[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 2500; j >= 0; j--)
      if (dp[j])
        for (int kk = 1; kk <= k; kk++) {
          ta = kk;
          if (kk == k) ta++;
          if (!dp[j + ta] || dp[j + ta] > dp[j] + x[kk])
            dp[j + ta] = dp[j] + x[kk];
        }
  for (int i = 2500; i >= 0; i--)
    if (dp[i] && dp[i] <= m) {
      printf("%d\n", i);
      return 0;
    }
  return 0;
}

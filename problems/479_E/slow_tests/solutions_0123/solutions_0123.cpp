#include <bits/stdc++.h>
using namespace std;
int constexpr mod = 1e9 + 7, max_n = 5e3 + 10;
int dp[max_n][max_n], ps[max_n][max_n];
int32_t main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (a > b) {
    a = n - a + 1;
    b = n - b + 1;
  }
  dp[a][0] = 1;
  for (int i = 1; i < b; i++) {
    ps[i][0] = ps[i - 1][0] + dp[i][0];
    ps[i][0] %= mod;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < b; j++) {
      int aa = min(j + (b - j - 1) / 2, b - 1);
      dp[j][i] += ps[aa][i - 1];
      if (aa >= j) dp[j][i] -= dp[j][i - 1];
      dp[j][i] += mod;
      dp[j][i] %= mod;
    }
    for (int j = 1; j < b; j++) {
      ps[j][i] = ps[j - 1][i] + dp[j][i];
      ps[j][i] %= mod;
    }
  }
  int ans = 0;
  for (int i = 1; i < b; i++) {
    ans += dp[i][k];
    ans %= mod;
  }
  cout << ans;
}

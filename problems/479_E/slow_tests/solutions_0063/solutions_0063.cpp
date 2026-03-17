#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int dp[2][5005];
int gao(int a, int n, int k) {
  for (int i = 1; i < n; i++) dp[0][i] = 0;
  dp[0][a] = 1;
  for (int i = 1; i <= k; i++) {
    int c = i & 1;
    for (int i = 1; i <= n; i++) dp[c][i] = 0;
    for (int i = 1; i <= n; i++) {
      dp[c][1] = (dp[c][1] + dp[c ^ 1][i]) % MOD;
      dp[c][i] = (dp[c][i] + MOD - dp[c ^ 1][i]) % MOD;
      dp[c][i + 1] = (dp[c][i + 1] + dp[c ^ 1][i]) % MOD;
      int p = min(n + 1, i + i);
      dp[c][p] = (dp[c][p] + MOD - dp[c ^ 1][i]) % MOD;
    }
    for (int i = 2; i <= n; i++) {
      dp[c][i] = (dp[c][i] + dp[c][i - 1]) % MOD;
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) ret = (ret + dp[k & 1][i]) % MOD;
  return ret;
}
int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (a < b)
    cout << gao(b - a, b - 1, k) << endl;
  else
    cout << gao(a - b, n - b, k) << endl;
  return 0;
}

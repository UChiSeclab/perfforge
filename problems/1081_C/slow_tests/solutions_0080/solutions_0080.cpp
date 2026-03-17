#include <bits/stdc++.h>
const int maxn = 2005;
const long long mod = 998244353;
using namespace std;
long long dp[maxn][maxn];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  dp[1][0] = m;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1) % mod) % mod;
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}

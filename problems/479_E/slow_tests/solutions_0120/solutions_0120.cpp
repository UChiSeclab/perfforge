#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
long long dp[5005][5005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, k, ans = 0;
  cin >> n >> a >> b >> k;
  if (b < a) {
    a = a - b;
    n = n - b;
  } else {
    a = b - a;
    n = b - 1;
  }
  dp[0][a] = 1;
  for (long long i = 1; i <= k; i++) {
    long long s = 0;
    for (long long j = 2; j <= n; j++) {
      long long q = 2 * j;
      q = min(n + 1, q);
      dp[i][1] += dp[i - 1][j];
      dp[i][j] -= dp[i - 1][j];
      dp[i][j + 1] += dp[i - 1][j];
      dp[i][q] -= dp[i - 1][j];
    }
    for (long long j = 1; j <= n; j++) {
      s += dp[i][j];
      dp[i][j] = s;
      dp[i][j] %= p;
      dp[i][j] = (p + dp[i][j]) % p;
    }
  }
  for (long long i = 1; i <= n; i++) ans += dp[k][i];
  ans = (p + ans % p) % p;
  cout << ans;
}

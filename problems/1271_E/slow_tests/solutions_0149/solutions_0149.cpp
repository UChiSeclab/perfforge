#include <bits/stdc++.h>
using namespace std;
long long N, n, k, ans;
map<long long, long long> dp;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> k;
  n = N;
  while (n) {
    if (n % 2) {
      dp[n] = dp[n * 2] + 1;
      dp[n - 1] = dp[n] + dp[n * 2 - 2] + 1;
      dp[n - 2] = dp[n * 2 - 2] + 1;
      dp[n - 3] = dp[n - 2] + dp[n * 2 - 2] + 1;
    } else {
      dp[n] = dp[n * 2] + dp[n * 2 - 1] + 1;
      dp[n - 1] = dp[n * 2 - 2] + 1;
      dp[n - 2] = dp[n - 1] + dp[n * 2 - 2] + 1;
      dp[n - 3] = dp[n * 2 - 2] + 1;
    }
    if (dp[n] >= k && n >= ans) ans = n;
    if (dp[n - 1] >= k && n - 1 >= ans) ans = n - 1;
    if (dp[n - 2] >= k && n - 2 >= ans) ans = n - 2;
    if (dp[n - 3] >= k && n - 3 >= ans) ans = n - 3;
    n /= 2;
  }
  cout << ans << '\n';
  return 0;
}

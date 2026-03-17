#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const long long MAXN = 1e2 + 10, MXN = 1e4 + 10;
long long n, m, szz, prs[MAXN], mx[MAXN][MAXN], dp[2][MXN];
int32_t main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> szz;
    for (long long j = 1; j <= szz; j++) cin >> prs[j], prs[j] += prs[j - 1];
    for (long long j = 0; j <= szz; j++)
      for (long long k = j; k <= szz; k++)
        mx[i][j + szz - k] =
            max(mx[i][j + szz - k], prs[j] + prs[szz] - prs[k]);
  }
  for (long long i = 0; i < MAXN; i++) dp[0][i] = mx[0][i];
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < MAXN; j++) {
      if (!mx[i][j]) continue;
      for (long long k = 0; k <= MXN - 10; k++) {
        if (!dp[0][k] and k) continue;
        dp[1][j + k] =
            max(dp[1][j + k], max(dp[0][j + k], mx[i][j] + dp[0][k]));
      }
    }
    for (long long j = 0; j <= MXN - 10; j++)
      dp[0][j] = max(dp[0][j], dp[1][j]);
  }
  return cout << dp[0][m] << '\n', 0;
}

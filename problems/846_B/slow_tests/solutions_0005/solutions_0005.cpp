#include <bits/stdc++.h>
using namespace std;
const int maxN = 50;
const long long INF = (long long)1e18;
long long dp[maxN][maxN * maxN], a[maxN], sum[maxN];
void upd(long long& a, long long b) { a = min(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, M;
  cin >> n >> k >> M;
  for (int i = 1; i <= k; ++i) cin >> a[i];
  sort(a + 1, a + k + 1);
  sum[0] = 0;
  for (int i = 1; i <= k; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n * (k + 1); ++j) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= (k + 1) * n; ++j) {
      if (dp[i][j] == INF) continue;
      for (int ne = 0; ne <= k; ++ne) {
        upd(dp[i + 1][j + ne + (ne == k)], dp[i][j] + sum[ne]);
      }
    }
  }
  int ans = -1;
  for (int i = 0; i <= (k + 1) * n; ++i) {
    if (dp[n][i] <= M) ans = max(ans, i);
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 2e7;
const int N = 72;
int n, m, k, a[N][N], rowDP[N][N], dp[N][N][N], allDP[N][N], ans;
void countRowDP(int row) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int t = 0; t < N; t++) dp[i][j][t] = -inf;
  for (int i = 0; i < N; i++) dp[i][0][0] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= min(i, m / 2); j++)
      for (int r = 0; r < k; r++) {
        dp[i][j][(r + a[row][i]) % k] =
            max(dp[i][j][(r + a[row][i]) % k], dp[i - 1][j - 1][r] + a[row][i]);
        dp[i][j][r] = max(dp[i][j][r], dp[i - 1][j][r]);
      }
  for (int r = 0; r < k; r++) {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= min(i, m / 2); j++)
        rowDP[row][r] = max(rowDP[row][r], dp[i][j][r]);
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) rowDP[i][j] = -inf;
  for (int i = 1; i <= n; i++) countRowDP(i);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) allDP[i][j] = -inf;
  allDP[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int r = 0; r < k; r++)
      for (int t = 0; t < k; t++) {
        allDP[i][(r + t) % k] =
            max(allDP[i][(r + t) % k], allDP[i - 1][r] + rowDP[i][t]);
        allDP[i][r] = max(allDP[i][r], allDP[i - 1][r]);
      }
  cout << max(0, allDP[n][0]);
}

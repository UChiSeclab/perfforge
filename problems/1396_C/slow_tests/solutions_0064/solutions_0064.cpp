#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 40;
const long long INFLL = 1e18;
long long dp[N][3][2][2];
signed main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<long long> a(n);
  for (int(i) = 0; (i) != (n); (i)++) cin >> a[i];
  for (int(i) = 0; (i) != (n); (i)++) {
    for (int(j) = 0; (j) != (3); (j)++) {
      for (int(k) = 0; (k) != (2); (k)++) {
        dp[i][j][k][0] = dp[i][j][k][1] = INFLL;
      }
    }
  }
  dp[0][2][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][0] + 2 * d + r1);
      dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][1] + 2 * d + r1);
      dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][0] + 2 * d + r1);
      dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][1] + 2 * d + r1);
      dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][0] + 2 * d + r1);
      dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][1] + 2 * d + r1);
      dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][2][0][0] + a[i] * r1 + r3);
      dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][2][1][0] + a[i] * r1 + r3);
      dp[i][1][0][1] =
          min(dp[i][1][0][1], dp[i][2][0][0] + min(r2, a[i] * r1 + r1));
      dp[i][1][1][1] =
          min(dp[i][1][1][1], dp[i][2][1][0] + min(r2, a[i] * r1 + r1));
      dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][1][0][0] + r1);
      dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][1][1][0] + r1);
      dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][0] + d);
      dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][1] + d);
      dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][0] + d);
      dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][1] + d);
    }
  }
  cout << min(dp[n - 1][0][0][0], dp[n - 1][0][1][0] + d + r1);
}

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int mxK = 45 * 45 + 100;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  long long m;
  cin >> m;
  vector<long long> A(k);
  for (int i = 0; i < k; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<vector<long long>> dp(n + 1, vector<long long>(mxK, 1e18));
  dp[0][0] = 0;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < mxK; ++j) {
      long long cur = 0;
      for (int l = 1, en = min(k, j); l <= en; ++l) {
        cur += A[l - 1];
        dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + cur);
        if (l == k && (j - l - 1 >= 0)) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - l - 1] + cur);
        }
      }
      if (dp[i][j] <= m) {
        ans = max(ans, j + 0LL);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

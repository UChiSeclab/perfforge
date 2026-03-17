#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<ll> > dp(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    dp[i][i] = a[0];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l < n; l++) {
      int r = l + len - 1;
      if (r >= n) break;
      bool ok = 1;
      for (int i = l + 1; i <= r; i++) {
        if (s[i] != s[l]) {
          ok = 0;
          break;
        }
      }
      if (ok) dp[l][r] = max(dp[l][r], a[len - 1]);
      for (int i = l + 1; i <= r; i++) {
        dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i][r]);
      }
      vector<vector<ll> > dp1(len, vector<ll>(len, -INF));
      dp1[0][0] = 0;
      for (int i = 0; i < len - 1; i++) {
        for (int len1 = 0; len1 < len - 1; len1++) {
          if (dp[i][len1] == -INF) continue;
          for (int j = i + 1; j < len; j++) {
            if (s[l + i] == s[l + j]) {
              dp1[j][len1 + 1] = max(dp1[j][len1 + 1],
                                     dp1[i][len1] + dp[l + i + 1][l + j - 1]);
            }
          }
        }
      }
      for (int len1 = 0; len1 < len; len1++) {
        dp[l][r] = max(dp[l][r], dp1[len - 1][len1] + a[len1]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}

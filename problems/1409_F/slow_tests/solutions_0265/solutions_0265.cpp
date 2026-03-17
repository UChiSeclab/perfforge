#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
long long dp[205][205][205];
void solve() {
  long long n, k, ans = 0;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  memset(dp, -0x3f3f3f3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int ck = 0; ck <= n; ck++) {
        if (dp[i][j][k] == -0x3f3f3f3f) continue;
        int e0 = s[i] == t[0];
        int e1 = s[i] == t[1];
        int e01 = t[1] == t[0];
        dp[i + 1][j][ck + e0] =
            max(dp[i + 1][j][ck + e0], dp[i][j][ck] + (e1 ? ck : 0));
        if (j < k) {
          dp[i + 1][j + 1][ck + 1] =
              max(dp[i + 1][j + 1][ck + 1], dp[i][j][ck] + (e01 ? ck : 0));
          dp[i + 1][j + 1][ck + e01] =
              max(dp[i + 1][j + 1][ck + e01], dp[i][j][ck] + ck);
        }
      }
    }
  }
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= n; j++) ans = max(ans, dp[n][i][j]);
  cout << ans << '\n';
}
int main(int argc, char* argv[]) {
  solve();
  return 0;
}

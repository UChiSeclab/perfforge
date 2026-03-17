#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long dp[11][1001][1001];
long long sdp[1001][1001];
long long ssdp[1001][1001];
long long ssdp2[1001];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[0][i][j] = 1;
    }
  }
  for (int u = 1; u <= m; ++u) {
    for (int l = 1; l <= n; ++l) {
      for (int r = 1; r <= n; ++r) {
        sdp[l][r] = (sdp[l][r - 1] + dp[u - 1][l][r]) % MOD;
      }
    }
    for (int r = 1; r <= n; ++r) {
      for (int l = 1; l <= n; ++l) {
        ssdp[r][l] = (ssdp[r][l - 1] + sdp[l][r]) % MOD;
      }
      ssdp2[r] = (sdp[r][r - 1] + ssdp2[r - 1]) % MOD;
    }
    for (int l = 1; l <= n; ++l) {
      for (int r = 1; r <= n; ++r) {
        if (l <= r) {
          dp[u][l][r] += ssdp[n][l] - ssdp[r - 1][l];
        } else {
          dp[u][l][r] += ssdp[n][l] - ssdp[r - 1][r];
          dp[u][l][r] -= ssdp2[l] - ssdp2[r];
        }
        dp[u][l][r] %= MOD;
      }
    }
  }
  cout << (dp[m][n][1] + MOD) % MOD;
}

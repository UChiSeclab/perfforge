#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MOD = 998244353;
int N, M, K;
long long dp[MAXN][MAXN];
long long ways(int n, int k) {
  if (n == 1) {
    if (k == 0) return M;
    return 0;
  }
  if (dp[n][k] != -1) return dp[n][k];
  return dp[n][k] = (ways(n - 1, k) + ways(n - 1, k - 1) * (M - 1) % MOD) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> N >> M >> K;
  cout << ways(N, K) << "\n";
}

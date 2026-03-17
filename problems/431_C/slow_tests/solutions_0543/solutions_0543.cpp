#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k, d;
int dp[105][105][2];
int go(int cur = 0, int sum = 0, bool has = 0) {
  if (sum > n) {
    return 0;
  } else if (has && sum == n) {
    return 1;
  }
  if (dp[cur][sum][has] != -1) {
    return dp[cur][sum][has];
  }
  dp[cur][sum][has] = 0;
  for (int i = 1; i <= k; i++) {
    dp[cur][sum][has] =
        (0LL + dp[cur][sum][has] + go(cur + 1, sum + i, (i >= d) | has)) % mod;
  }
  return dp[cur][sum][has];
}
int main() {
  cin >> n >> k >> d;
  for (int i = 0; i <= 101; i++) {
    for (int j = 0; j <= 101; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << go() << "\n";
  return 0;
}

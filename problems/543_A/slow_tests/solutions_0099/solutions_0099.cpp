#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mx = 500 + 9;
ll MOD = 1;
int a[mx];
ll dp[mx][mx], then[mx][mx];
int main() {
  int n, m, b;
  scanf("%d %d %d %lld", &n, &m, &b, &MOD);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= b; k++) {
      then[i][k] = 1;
    }
  }
  for (int j = m - 1; j >= 0; j--) {
    for (int k = 0; k <= b; k++) {
      for (int i = n; i >= 1; i--) {
        dp[i][k] = dp[i + 1][k];
        if (k + a[i] <= b) dp[i][k] += then[i][k + a[i]];
        if (dp[i][k] >= MOD) dp[i][k] %= MOD;
      }
    }
    for (int k = 0; k <= b; k++) {
      for (int i = n; i >= 1; i--) {
        then[i][k] = dp[i][k];
        dp[i][k] = 0;
      }
    }
  }
  ll ans = then[1][0];
  printf("%lld\n", ans);
}

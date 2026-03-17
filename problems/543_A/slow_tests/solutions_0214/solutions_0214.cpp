#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 100 + 5;
const long long inf = 9223372036854775807;
long long dp[2][maxn][maxn], n, m, b, mod, a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0][0] = 1;
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i <= m; i++) {
      for (int k = 0; k <= b; k++) {
        dp[j % 2][i][k] = 0;
      }
    }
    for (int i = 0; i <= m; i++) {
      for (int k = 0; k <= b; k++) {
        dp[j % 2][i][k] += dp[1 - (j % 2)][i][k] % mod;
        if (k >= a[j] && i > 0) {
          dp[j % 2][i][k] += dp[j % 2][i - 1][k - a[j]] % mod;
        }
        dp[j % 2][i][k] = dp[j % 2][i][k] % mod;
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i <= b; i++) {
    sum += dp[n % 2][m][i];
  }
  cout << sum % mod;
}

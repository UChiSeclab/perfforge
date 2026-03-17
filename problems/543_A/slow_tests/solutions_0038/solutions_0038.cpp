#include <bits/stdc++.h>
using namespace std;
int n;
long long m, b, MOD, a[555], dp[555][555], temp[555][555];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> b >> MOD;
  for (int(i) = (1); (i) <= (n); i++) cin >> a[i];
  dp[0][0] = 1LL;
  for (int(i) = (1); (i) <= (m); i++) {
    memset(temp, 0, sizeof(temp));
    for (int(j) = (0); (j) <= (b); j++) {
      long long res = 0LL;
      int l = i == 1 ? 0 : 1;
      for (int(k) = (l); (k) <= (n); k++) {
        res += dp[k][j];
        if (j + a[k] <= b) temp[k][j + a[k]] += res % MOD;
      }
    }
    memcpy(dp, temp, sizeof(temp));
  }
  long long ans = 0LL;
  for (int(i) = (1); (i) <= (n); i++)
    for (int(j) = (0); (j) <= (b); j++) ans = (ans + dp[i][j]) % MOD;
  cout << ans % MOD << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = (1 << 29);
long long dp[2][maxn];
long long a[maxn];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  a[0] = a[n + 1] = 1;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[0][i] = min(dp[0][i - 1] + 1, a[i]);
  }
  for (int i = n; i >= 0; i--) {
    dp[1][i] = min(dp[1][i + 1] + 1, a[i]);
  }
  long long ans = -INF;
  for (int i = 1; i <= n; i++) ans = max(ans, min(dp[0][i], dp[1][i]));
  cout << ans << endl;
  return 0;
}

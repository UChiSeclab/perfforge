#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
const int maxm = 1e6 + 2;
int a[maxn];
int dp[maxn][maxn * maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(dp, 0, sizeof(dp));
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i <= 2 * k * n; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 2 * k * n; j++) {
        if (!dp[i][j - 1] && !dp[i - 1][j - 1]) continue;
        int dh = j % (2 * k);
        if (dh > k) dh = 2 * k - dh;
        if (a[i] + dh <= l) dp[i][j] = 1;
      }
    }
    bool flag = 0;
    for (int i = 1; i <= 2 * k * n; i++) {
      if (dp[n][i]) {
        flag = 1;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

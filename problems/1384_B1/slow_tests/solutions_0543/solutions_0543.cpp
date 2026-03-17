#include <bits/stdc++.h>
using namespace std;
int inf = 0x3f3f3f3f;
const int N = 2e5 + 7;
int n, k, l, h;
int dp[107][N], a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= 2 * k * n; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 2 * k * n; j++) {
        if (dp[i - 1][j - 1] == -1 && dp[i][j - 1] == -1) continue;
        if (j % (2 * k) < k)
          h = a[i] + j % k;
        else
          h = a[i] + k - (j % k);
        if (h <= l) dp[i][j] = 0;
      }
    }
    int fl = 0;
    for (int i = 0; i <= 10000; i++) {
      if (dp[n][i] == 0) fl = 1;
    }
    if (fl == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

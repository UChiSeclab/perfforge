#include <bits/stdc++.h>
using namespace std;
int a[2000000];
int dp[2000000];
int main() {
  int n, i, j, num, ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = 1;
  }
  for (i = 0; i < n; i++) {
    num = a[i];
    for (j = 2 * num; j <= 1000000; j += num) dp[j] = max(dp[j], 1 + dp[num]);
    ans = max(ans, dp[num]);
  }
  printf("%d", ans);
  return 0;
}

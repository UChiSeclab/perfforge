#include <bits/stdc++.h>
using namespace std;
int a[1000002], dp[1000002];
int main() {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  ;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ;
    dp[a[i]] = 1;
  }
  for (i = 0; i < n; i++) {
    int x = a[i];
    for (j = 2; x * j < 1000001; j++) dp[j * x] = max(dp[x] + 1, dp[j * x]);
  }
  for (i = 0; i < n; i++) ans = max(ans, dp[a[i]]);
  cout << ans << endl;
  return 0;
}

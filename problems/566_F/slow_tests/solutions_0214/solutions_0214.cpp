#include <bits/stdc++.h>
using namespace std;
int a[1111111];
int dp[1111111], ans = 0;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int k = a[i] * 2; k <= 1000000; k += a[i]) {
      dp[k] = max(dp[k], dp[a[i]] + 1);
    }
    ans = max(ans, dp[a[i]]);
  }
  cout << ans;
  return 0;
}

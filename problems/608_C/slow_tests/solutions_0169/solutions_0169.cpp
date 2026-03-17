#include <bits/stdc++.h>
using namespace std;
int n, arr[1000069] = {}, dp[1000069] = {}, f[1000069] = {};
int main() {
  cin >> n;
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    arr[x] = y;
    f[x] = 1;
    maxi = max(maxi, x);
  }
  for (int i = 1; i < maxi + 1; i++) f[i] = f[i - 1] + f[i];
  for (int i = 1; i < maxi + 1; i++) {
    if (i - arr[i] - 1 >= 0)
      dp[i] = dp[i - arr[i] - 1] + (f[i - 1] - f[i - arr[i] - 1]);
    else
      dp[i] = f[i - 1];
  }
  int ans = maxi + 2;
  for (int i = 0; i < maxi + 1; i++) {
    ans = min(ans, dp[i] + (f[maxi] - f[i]));
  }
  cout << ans;
  return 0;
}

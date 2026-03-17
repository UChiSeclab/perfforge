#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 1000 * 1000 + 10;
int dp[MAX_A], t[MAX_A];
int main() {
  int n, ans = 0, maxi = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    t[a] = b;
    maxi = max(maxi, a);
  }
  if (t[0] > 0) {
    dp[0] = 1;
    ans = 1;
  }
  for (int i = 1; i <= maxi; i++) {
    if (t[i] == 0)
      dp[i] = dp[i - 1];
    else {
      int x = i - t[i] - 1;
      if (x >= 0) dp[i] = dp[x];
      dp[i]++;
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << endl;
  return 0;
}

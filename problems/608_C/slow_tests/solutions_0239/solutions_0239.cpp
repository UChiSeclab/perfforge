#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, ans = INT_MIN;
  cin >> n;
  int a[n];
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> a[i] >> x;
    m[a[i]] = x;
  }
  sort(a, a + n);
  int dp[a[n - 1] + 1];
  for (int i = 0; i < a[n - 1] + 1; i++) {
    if (m[i] != 0) {
      if (i - m[i] - 1 >= 0)
        dp[i] = dp[i - m[i] - 1] + 1;
      else
        dp[i] = 1;
    } else
      dp[i] = i - 1 >= 0 ? dp[i - 1] : 0;
    ans = max(ans, dp[i]);
  }
  cout << n - ans << "\n";
}

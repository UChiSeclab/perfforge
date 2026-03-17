#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
const long long inf = 1e13 + 10;
long long dp[2][maxn];
int n, a[maxn], b[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    long long w = inf;
    for (int j = 1; j <= n; j++) {
      w = min(dp[0][j], w);
      dp[1][j] = w + abs(b[j] - a[i]);
    }
    swap(dp[1], dp[0]);
  }
  long long ans = inf;
  for (int j = 1; j <= n; j++) {
    ans = min(ans, dp[0][j]);
  }
  cout << ans;
  return 0;
}

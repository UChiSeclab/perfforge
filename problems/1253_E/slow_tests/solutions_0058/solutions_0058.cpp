#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > seg[100002];
int n, m, dp[100002], x, y, l;
int solve(int x) {
  if (x > m) return 0;
  if (dp[x] != -1) return dp[x];
  dp[x] = 1 + solve(x + 1);
  for (auto it : seg[x]) dp[x] = min(dp[x], it.second + solve(it.first + 1));
  return dp[x];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    for (int j = 1; j <= x - y; j++) {
      seg[j].push_back({2 * x - j, max(0, x - j - y)});
    }
    for (int j = max(1, x - y); j <= min(m, x + y); j++)
      seg[j].push_back({x + y, 0});
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1);
  return 0;
}

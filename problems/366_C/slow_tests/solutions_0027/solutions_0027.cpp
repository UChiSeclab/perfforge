#include <bits/stdc++.h>
using namespace std;
const int offset = (int)10000;
const int N = 3e4;
map<int, int> dp[105];
int ara[105], a[105], b[105];
int n, k;
const int inf = 1 << 30;
int solve(int pos, int bal) {
  if (pos > n) {
    if (bal == 0) {
      return 0;
    } else
      return -inf;
  }
  if (dp[pos].find(bal) != dp[pos].end()) {
    return dp[pos][bal];
  }
  int ret = -inf;
  ret = max(ret, solve(pos + 1, bal));
  ret = max(ret, a[pos] + solve(pos + 1, bal + a[pos] - (k * b[pos])));
  return dp[pos][bal] = ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int ans = solve(1, 0);
  if (ans <= 0) {
    cout << -1 << "\n";
    return 0;
  }
  cout << ans << "\n";
  return 0;
}

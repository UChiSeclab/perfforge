#include <bits/stdc++.h>
using namespace std;
int a[10];
int dp[1000100][2];
void path(int v, int l) {
  if (v <= 0 || l == 0) return;
  cout << dp[v][1];
  path(v - a[dp[v][1]], l - 1);
}
int f(int v) {
  if (v < 0) return -1;
  if (dp[v][0] != -1) return dp[v][0];
  int res = -10;
  int r, d = 0;
  for (int i = 9; i >= 1; i--) {
    r = f(v - a[i]);
    if (r > res) {
      res = r;
      d = i;
    }
  }
  dp[v][1] = d;
  return dp[v][0] = res + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int v;
  cin >> v;
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  int ans = f(v);
  if (ans == 0) {
    cout << -1;
  } else {
    path(v, ans);
  }
  return 0;
}

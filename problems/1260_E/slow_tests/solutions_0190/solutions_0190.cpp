#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1 << 19;
const ll oo = 1e18;
int n, a[N];
int used[N];
ll dp[N][19];
ll dn[N][19];
ll fn(int i, int j, int k) {
  if (j == 0) return dp[i][k];
  if (~dn[i][j]) return dn[i][j];
  return dn[i][j] = min(fn(i, j - 1, k), fn(i + (1 << (j - 1)), j - 1, k));
}
int lg(int x) { return 31 - __builtin_clz(x); }
ll getmn(int l, int r, int k) {
  l = max(l, 0);
  if (l > r) return oo;
  int lz = lg(r - l + 1);
  return min(fn(l, lz, k), fn(r - (1 << lz) + 1, lz, k));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int id = 0;
  while (a[id] != -1) id++;
  for (int i = 0; i <= id; i++) a[i] = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) dp[i][0] = oo;
  dp[1][0] = a[1];
  for (int i = 1; i < n; i++) dp[i][0] = a[i];
  ans = a[n - 1];
  for (int lvl = 1; (1 << lvl) < n; lvl++) {
    memset(dn, -1, sizeof dn);
    int max_right = n - (1 << (lvl + 1));
    int removed = n - (1 << (lvl));
    ll mn = oo;
    dp[0][lvl] = oo;
    for (int i = 1; i < n; i++) {
      if (n - 1 - i > max_right) {
        dp[i][lvl] = oo;
      } else {
        dp[i][lvl] = getmn(n - 1 - removed, i - 1, lvl - 1) + a[i];
      }
      mn = min(mn, dp[i][lvl - 1]);
    }
    ans = dp[n - 1][lvl];
  }
  printf("%lld\n", ans);
}

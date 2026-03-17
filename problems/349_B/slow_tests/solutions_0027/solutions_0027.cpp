#include <bits/stdc++.h>
using namespace std;
int i, j, k, t, n, m, a[15];
int dp[1000005], w[1000005];
int f(int x) {
  int ans = -1, t = 0;
  if (x == 0) return 0;
  if (dp[x]) return dp[x];
  for (int i = 9; i >= 1; i--) {
    if (x - a[i] < 0) continue;
    t = f(x - a[i]);
    if (t > ans) {
      ans = t;
      w[x] = i;
    }
  }
  return dp[x] = ans + 1;
}
int main() {
  scanf("%d", &k);
  for (i = 1; i <= 9; i++) scanf("%d", &a[i]);
  if (!f(k))
    cout << -1;
  else
    while (w[k] > 0) {
      cout << w[k];
      k -= a[w[k]];
    }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[(1 << 18) + 5], pos, n;
long long calc[30], dp[(1 << 18) + 5][20];
long long solve(int u, int bribe) {
  if (u == pos) return 0;
  if (bribe > 18) return 1e18;
  if (dp[u][bribe] != -1) return dp[u][bribe];
  int len = n - u + 1;
  long long res = solve(u - 1, bribe + 1) + a[u];
  if (calc[bribe] >= len) res = min(res, solve(u - 1, bribe));
  return dp[u][bribe] = res;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == -1) pos = i;
  }
  for (int i = 1, aux = n / 2; i < 20; i++, aux /= 2)
    calc[i] = calc[i - 1] + aux;
  cout << solve(n, 0) << endl;
  return 0;
}

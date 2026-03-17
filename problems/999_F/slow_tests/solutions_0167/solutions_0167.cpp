#include <bits/stdc++.h>
using namespace std;
int n, k, c[5005], fa[505], h[15], f[505][5005];
int solve(int in, int st) {
  if (in == n + 1) return 0;
  if (st == n * k + 1) return 0;
  if (f[in][st] != -1) return f[in][st];
  int cur = 0, cnt = 0;
  cur = max(cur, solve(in + 1, st));
  for (int i = st; i <= n * k; i++) {
    if (c[i] > fa[in]) break;
    if (c[i] == fa[in]) {
      cnt++;
      cur = max(cur, solve(in + 1, i + 1) + h[cnt]);
      if (cnt == k) break;
    }
  }
  return f[in][st] = cur;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n * k; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) cin >> fa[i];
  for (int i = 1; i <= k; i++) cin >> h[i];
  sort(c + 1, c + n * k + 1);
  sort(fa + 1, fa + n + 1);
  memset(f, -1, sizeof f);
  cout << solve(1, 1);
  return 0;
}

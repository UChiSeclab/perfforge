#include <bits/stdc++.h>
using namespace std;
int n, m, a;
long long memo[2020][2020];
long long umb[2020];
int rain[2020];
long long dp(int i, int u) {
  if (i == a) return 0;
  long long &ret = memo[i][u];
  if (ret != -1) return ret;
  if (rain[i]) {
    ret = umb[i] + dp(i + 1, i);
    if (u != a) ret = min(ret, umb[u] + dp(i + 1, u));
  } else {
    long long w = (u == a) ? 0 : umb[u];
    ret = w + dp(i + 1, u);
    ret = min(ret, dp(i + 1, a));
    ret = min(ret, umb[i] + dp(i + 1, i));
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> n >> m;
  for (int i = 0; i < n; i++) {
    int L, R;
    cin >> L >> R;
    for (int j = L; j < R; j++) rain[j] = 1;
  }
  for (int i = 0; i < a + 10; i++) umb[i] = 1e14;
  for (int i = 0; i < m; i++) {
    long long x, p;
    cin >> x >> p;
    umb[x] = min(umb[x], p);
  }
  memset(memo, -1, sizeof memo);
  long long ans = dp(0, a);
  if (ans > 1e13) ans = -1;
  cout << ans << endl;
  return 0;
}

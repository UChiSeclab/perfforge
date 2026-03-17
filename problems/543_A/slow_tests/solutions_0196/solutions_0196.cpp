#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (0) {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
  }
}
const clock_t MAXT = (100 * CLOCKS_PER_SEC) / 1000;
const int PX[5] = {0, 0, 1, -1}, PY[5] = {-1, 1, 0, 0}, N = 503, INF = 1e9;
const long long INFL = 1e18, MOD = 1e9 + 7;
const long double EPS = 1e-6;
int n, len, max_err, mod, a[N];
int dp_old[N][N], dp_new[N][N];
inline void add(int& a, int b) {
  a += b;
  while (a >= mod) a -= mod;
}
int main() {
  file();
  cin >> n >> len >> max_err >> mod;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp_new[0][0] = 1;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j <= max_err; ++j)
      for (int k = 0; k <= n; ++k) {
        dp_old[j][k] = dp_new[j][k];
        dp_new[j][k] = 0;
      }
    for (int j = 0; j <= max_err; ++j)
      for (int k = 1; k <= n; ++k) {
        add(dp_old[j][k], dp_old[j][k - 1]);
        if (a[k] + j <= max_err) add(dp_new[j + a[k]][k], dp_old[j][k]);
      }
  }
  int ans = 0;
  for (int i = 0; i <= max_err; ++i)
    for (int j = 0; j <= n; ++j) add(ans, dp_new[i][j]);
  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 5000 + 10, mod = 1000000007;
long long n, a, b, k;
long long c[INF][INF];
int main() {
  cin >> n >> a >> b >> k;
  if (a < b) {
    for (int i = 1; i < b; i++) {
      c[0][i] = 1;
    }
  } else {
    for (int i = b + 1; i <= n; i++) {
      c[0][i] = 1;
    }
  }
  if (a < b) {
    for (int i = 1; i <= k; i++) {
      c[i][b - 1] = 0;
      for (int j = b - 2; j >= 1; j--) {
        int j1 = 2 * j - b + 1, j2 = 2 * j - b + 2;
        c[i][j] = (c[i][j + 1] - c[i - 1][j] + c[i - 1][j + 1] +
                   c[i - 1][j1] * (j1 > 0 ? 1 : 0) +
                   c[i - 1][j2] * (j2 > 0 ? 1 : 0)) %
                  mod;
      }
    }
  } else {
    for (int i = 1; i <= k; i++) {
      c[i][b + 1] = 0;
      for (int j = b + 2; j <= n; j++) {
        int j1 = 2 * j - b - 1, j2 = 2 * j - b - 2;
        c[i][j] = (c[i][j - 1] - c[i - 1][j] + c[i - 1][j - 1] +
                   c[i - 1][j1] * (j1 <= n ? 1 : 0) +
                   c[i - 1][j2] * (j2 <= n ? 1 : 0)) %
                  mod;
      }
    }
  }
  long long ans = c[k][a];
  while (ans < 0) ans += mod;
  cout << ans << endl;
}

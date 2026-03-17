#include <bits/stdc++.h>
using namespace std;
struct re {
  int x, y;
};
const int inf = 1e9 + 10;
const int N = 100 + 10;
int n, a[N], f[N][3][N][N], ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      f[0][0][i][j] = inf;
      f[0][1][i][j] = inf;
    }
  f[0][0][0][0] = f[0][1][0][0] = 0;
  for (int i = 1; i <= n; ++i)
    for (int chan = 0; chan <= n; ++chan)
      for (int le = 0; le <= n; ++le) {
        for (int j = 0; j < 2; ++j) f[i][j][chan][le] = inf;
        if (a[i]) {
          if (a[i] % 2) {
            if (le)
              for (int j = 0; j < 2; ++j)
                f[i][1][chan][le] = min(f[i][1][chan][le],
                                        f[i - 1][j][chan][le - 1] + (j != 1));
          } else {
            if (chan)
              for (int j = 0; j < 2; ++j)
                f[i][0][chan][le] = min(f[i][0][chan][le],
                                        f[i - 1][j][chan - 1][le] + (j != 0));
          }
        } else {
          if (le)
            for (int j = 0; j < 2; ++j)
              f[i][1][chan][le] =
                  min(f[i][1][chan][le], f[i - 1][j][chan][le - 1] + (j != 1));
          if (chan)
            for (int j = 0; j < 2; ++j)
              f[i][0][chan][le] =
                  min(f[i][0][chan][le], f[i - 1][j][chan - 1][le] + (j != 0));
        }
      }
  int ans = inf;
  for (int j = 0; j < 2; ++j) ans = min(ans, f[n][j][n / 2][n - n / 2]);
  cout << ans;
  return 0;
}

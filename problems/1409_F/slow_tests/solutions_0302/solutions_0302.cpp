#include <bits/stdc++.h>
using namespace std;
const int N = 204;
char s[N];
char t[100];
int f[N][N][N];
const int INF = 1 << 30;
auto solve() -> void {
  int n, k;
  cin >> n >> k;
  cin >> s;
  cin >> (t + 1);
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= k; ++j) {
      for (int t2 = 0; t2 <= n; ++t2) f[i][j][t2] = -INF;
    }
  }
  f[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int cnt = 0; cnt <= n; ++cnt) {
        f[i + 1][j][cnt + (t[1] == s[i])] =
            max(f[i + 1][j][cnt + (t[1] == s[i])],
                f[i][j][cnt] + (s[i] == t[2] ? cnt : 0));
        if (j < k) {
          f[i + 1][j + 1][cnt + 1] =
              max(f[i + 1][j + 1][cnt + 1],
                  f[i][j][cnt] + (t[1] == t[2] ? cnt : 0));
          f[i + 1][j + 1][cnt + (t[1] == t[2])] =
              max(f[i + 1][j + 1][cnt + (t[1] == t[2])], f[i][j][cnt] + cnt);
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= k; ++j) {
    for (int t2 = 0; t2 <= n; ++t2) {
      ans = max(ans, f[n][j][t2]);
    }
  }
  cout << ans << '\n';
}
auto main() -> int {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}

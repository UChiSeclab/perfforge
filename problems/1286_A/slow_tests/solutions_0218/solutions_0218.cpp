#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> used(n + 1);
  for (auto i : a) {
    used[i] = 1;
  }
  int dp[n][n + 2][n + 2][2];
  for (int i = 0; i < n; i++) {
    for (int x = 0; x <= n; x++) {
      for (int y = 0; y <= n; y++) {
        dp[i][x][y][0] = n * n;
        dp[i][x][y][1] = n * n;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!i) {
      if (!a[i]) {
        dp[0][1][0][0] = 0;
        dp[0][0][1][1] = 0;
      } else {
        if (a[i] % 2) {
          dp[0][0][1][1] = 0;
        } else {
          dp[0][1][0][0] = 0;
        }
      }
    } else {
      for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
          for (int val = 0; val < 2; val++) {
            if (a[i] && val != a[i] % 2) {
              continue;
            }
            if (!val) {
              dp[i][x + 1][y][val] =
                  min(dp[i][x + 1][y][val], dp[i - 1][x][y][val]);
              dp[i][x + 1][y][val] =
                  min(dp[i][x + 1][y][val], dp[i - 1][x][y][val ^ 1] + 1);
            } else {
              dp[i][x][y + 1][val] =
                  min(dp[i][x][y + 1][val], dp[i - 1][x][y][val]);
              dp[i][x][y + 1][val] =
                  min(dp[i][x][y + 1][val], dp[i - 1][x][y][val ^ 1] + 1);
            }
          }
        }
      }
    }
  }
  vector<int> cnt(2);
  for (int i = 1; i <= n; i++) {
    cnt[i % 2]++;
  }
  cout << min(dp[n - 1][cnt[0]][cnt[1]][0], dp[n - 1][cnt[0]][cnt[1]][1])
       << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int test;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}

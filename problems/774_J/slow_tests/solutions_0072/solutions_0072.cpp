#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int dp[n + 1][101];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 100; j++) dp[i][j] = -1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 100; j++) {
      if (i == 0) {
        if (j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
        continue;
      }
      if (s[i - 1] == 'Y') {
        if (j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
        continue;
      }
      if (s[i - 1] == 'N') {
        if (j == 0) dp[i][j] = 0;
        if (j == 1)
          dp[i][j] = 1;
        else if (j > 1) {
          if (j <= k) {
            if (dp[i - 1][j - 1] == 1)
              dp[i][j] = 1;
            else if (dp[i - 1][j - 1] == 0)
              dp[i][j] = 0;
            else
              dp[i][j] = 2;
          } else {
            if (dp[i - 1][j - 1] == 1)
              dp[i][j] = 1;
            else if (dp[i - 1][j - 1] == 0)
              dp[i][j] = 0;
            else {
              for (int l = 1; l < 101; l++) {
                if (dp[i - 1][l] == 2) dp[i - 1][l] = 0;
              }
              for (int l = 2; l < j; l++) {
                if (dp[i][l] == 2) dp[i][l] = 0;
              }
              dp[i][j] = 0;
            }
          }
        }
      }
      if (s[i - 1] == '?') {
        if (j == 0) dp[i][j] = 2;
        if (dp[i - 1][j - 1] == 2 or dp[i - 1][j - 1] == 1)
          dp[i][j] = 2;
        else
          dp[i][j] = 0;
      }
    }
  }
  int ans = 0;
  int ans1 = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = k + 1; j <= 100; j++) {
      if (dp[i][j] == 1) ans1 = 1;
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i][k] == 1 or dp[i][k] == 2) {
      ans = 1;
    }
  }
  if (ans == 1 and ans1 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

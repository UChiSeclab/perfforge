#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int dp[100 + 5][100 + 5][105];
  memset(dp, 0, sizeof(dp));
  string s;
  cin >> s;
  s += 'Y';
  n++;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int mx = 0; mx <= 100; mx++) {
        if (dp[i][j][mx] == 0) continue;
        if (s[i] == 'N') {
          dp[i + 1][j + 1][mx] = 1;
        }
        if (s[i] == 'Y') {
          dp[i + 1][0][max(j, mx)] = 1;
        }
        if (s[i] == '?') {
          dp[i + 1][0][max(mx, j)] = 1;
          dp[i + 1][j + 1][mx] = 1;
        }
      }
    }
  }
  if (dp[n][0][k]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int n, k, v[maxn];
int dp[maxn][maxn];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> v[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= v[i]; j--) {
      for (int c = k; c >= 0; c--) {
        if (c < v[i])
          dp[j][c] = max(dp[j][c], dp[j - v[i]][c]);
        else
          dp[j][c] =
              max(dp[j][c], max(dp[j - v[i]][c], dp[j - v[i]][c - v[i]]));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 500; i++) {
    if (dp[k][i]) ans++;
  }
  cout << ans << endl;
  for (int i = 0; i <= 500; i++) {
    if (dp[k][i]) cout << i << " ";
  }
  cout << endl;
  return 0;
}

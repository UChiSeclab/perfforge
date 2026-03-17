#include <bits/stdc++.h>
using namespace std;
int dp[2][10001];
signed main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a[i].assign(k, 0);
    for (int j = 0; j < k; j++) cin >> a[i][j];
  }
  vector<vector<int>> val(n);
  for (int i = 0; i < n; i++) val[i].assign(a[i].size() + 1, 0);
  for (int i = 0; i < n; i++) {
    int loc = a[i].size();
    vector<int> pref(loc, 0);
    for (int j = 0; j < loc; j++) {
      pref[j] = a[i][j];
      if (j != 0) pref[j] += pref[j - 1];
    }
    for (int l = 0; l < loc; l++) val[i][l + 1] = max(val[i][l + 1], pref[l]);
    int sum = 0;
    for (int j = loc - 1; j >= 0; j--) {
      sum += a[i][j];
      val[i][loc - j] = max(val[i][loc - j], sum);
    }
    for (int len = 1; len <= loc; len++) {
      for (int l = 0; l + len - 1 < loc; l++) {
        int k = pref[l + len - 1] - (l != 0 ? pref[l - 1] : 0);
        val[i][loc - len] = max(val[i][loc - len], sum - k);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    swap(dp[0], dp[1]);
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= min((int)a[i].size(), j); k++)
        dp[1][j] = max(dp[1][j], dp[0][j - k] + val[i][k]);
    }
  }
  cout << dp[1][m];
}

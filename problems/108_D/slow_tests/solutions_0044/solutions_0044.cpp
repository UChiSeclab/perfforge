#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int sum = 0;
  vector<int> s(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    sum += s[i];
  }
  s[h - 1]--;
  if (sum < n || s[h - 1] < 0) {
    cout << -1.0 << endl;
    return 0;
  }
  vector<vector<double> > comb(101, vector<double>(101, 0.0));
  for (int i = 0; i <= 100; i++) {
    comb[i][0] = 1.0;
    for (int j = 1; j <= i && j <= 100; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
  vector<double> dp(n, 0.0), dpp(n, 0.0);
  dp[0] = dpp[0] = 1.0;
  for (int i = 0; i < m; i++) {
    vector<double> dp2(n, 0.0), dpp2(n, 0.0);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= s[i] && j + k < n; k++) {
        dp2[j + k] += dp[j] * comb[s[i]][k];
        dpp2[j + k] += dpp[j] * comb[s[i]][k];
      }
    }
    dp.swap(dp2);
    if (i != h - 1) {
      dpp.swap(dpp2);
    }
    double mm = *max_element(dp.begin(), dp.end());
    for (int j = 0; j < dp.size(); j++) {
      dp[j] /= mm;
      dpp[j] /= mm;
    }
  }
  printf("%.10f\n", 1.0 - (dpp.back() / dp.back()));
  return 0;
}

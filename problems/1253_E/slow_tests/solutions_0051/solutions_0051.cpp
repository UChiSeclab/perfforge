#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (auto &x : a) {
    cin >> x.first >> x.second;
  }
  sort(a.begin(), a.end());
  memset(dp, 0x3f, sizeof(dp));
  dp[m + 1] = 0;
  for (int i = m; i >= 1; i--) {
    if (i == 1) {
      int v;
      v++;
    }
    for (int j = 0; j < n; j++) {
      if (a[j].first + a[j].second >= i) {
        int req = 0;
        if (a[j].first - a[j].second > i) {
          req = a[j].first - a[j].second - i;
        }
        dp[i] = min(dp[i],
                    req + dp[min(m + 1, a[j].first + a[j].second + req + 1)]);
        if (a[j].first + a[j].second < m) {
          req = max(req, m - (a[j].first + a[j].second));
        }
        dp[i] = min(dp[i], req);
      }
    }
  }
  cout << dp[1] << endl;
  return 0;
}

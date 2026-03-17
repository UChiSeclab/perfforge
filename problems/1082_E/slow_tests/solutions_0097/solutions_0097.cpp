#include <bits/stdc++.h>
using namespace std;
vector<int> g[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  cin >> n >> c;
  vector<int> a(n + 1), pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[a[i]].push_back(i);
    pre[i] = pre[i - 1] + (a[i] == c);
  }
  if (pre[n] == n) {
    cout << n << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 1; i < 500005; i++) {
    int cans = 1, mi = INT_MAX;
    for (int j = 0; j < g[i].size(); j++) {
      if (j) {
        cans = max(cans, j + 1 - pre[g[i][j]] - mi);
      }
      mi = min(mi, j - pre[g[i][j] - 1]);
    }
    ans = max(ans, cans);
  }
  cout << ans + pre[n] << endl;
  return 0;
}

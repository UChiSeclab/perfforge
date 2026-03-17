#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        int ind =
            lower_bound(mp[j].begin(), mp[j].end(), t - y) - mp[j].begin();
        if (ind == mp[j].size()) cnt++;
        mp[j].push_back(t);
        if (j != x / j) {
          ind = lower_bound(mp[x / j].begin(), mp[x / j].end(), t - y) -
                mp[x / j].begin();
          if (ind == mp[x / j].size()) cnt++;
          mp[x / j].push_back(t);
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}

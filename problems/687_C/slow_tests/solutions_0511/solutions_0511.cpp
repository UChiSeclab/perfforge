#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1, 0);
  for (int i = 1; i < n + 1; cin >> arr[i++])
    ;
  sort(arr.begin(), arr.end());
  vector<vector<unordered_set<int>>> dp(k + 1,
                                        vector<unordered_set<int>>(n + 1));
  vector<unordered_set<int>> fin(k + 1);
  fin[0].insert(0);
  dp[0][0].insert(0);
  for (int i = 1; i < k + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (i - arr[j] >= 0 && fin[i - arr[j]].size() > 0) {
        int f = 0;
        for (int k = 0; k < j; k++) {
          for (auto l : dp[i - arr[j]][k]) {
            if (!fin[i].count(l)) {
              f = 1;
              dp[i][j].insert(l);
              fin[i].insert(l);
            }
            if (!fin[i].count(l + arr[j])) {
              f = 1;
              dp[i][j].insert(l + arr[j]);
              fin[i].insert(l + arr[j]);
            }
          }
        }
        if (!fin[i].count(arr[j]) && f == 1) {
          dp[i][j].insert(arr[j]);
          fin[i].insert(arr[j]);
        }
      }
    }
  }
  cout << fin[k].size() << endl;
  vector<int> ans;
  for (auto i : fin[k]) ans.push_back(i);
  sort(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";
  cout << endl;
  return 0;
}

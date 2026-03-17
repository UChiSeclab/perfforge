#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int r, g, b;
int main() {
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    set<int> ans;
    ans.insert(0);
    for (long long j = 1; j * j <= n; ++j) {
      int k = n / j;
      if (n - k * j < j) {
        ans.insert(k);
      }
      k = n / (n / j);
      if (n - k * (n / j) < n / j) {
        ans.insert(k);
      }
    }
    cout << ans.size() << endl;
    vector<int> res(ans.begin(), ans.end());
    for (int j = 0; j < res.size(); ++j) {
      if (j == 0)
        cout << res[j];
      else
        cout << " " << res[j];
    }
    cout << endl;
  }
  return 0;
}

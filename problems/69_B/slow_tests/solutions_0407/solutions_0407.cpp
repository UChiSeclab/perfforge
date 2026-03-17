#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, pair<int, int> > > > holder(n);
  for (int i = 0; i < m; i++) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    l--, r--;
    for (int j = l; j <= r; j++) {
      holder[j].push_back(make_pair(t, make_pair(i, c)));
    }
  }
  for (int i = 0; i < n; i++) {
    sort(holder[i].begin(), holder[i].end());
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!holder[i].empty()) {
      ans += holder[i][0].second.second;
    }
  }
  cout << ans << endl;
  return 0;
}

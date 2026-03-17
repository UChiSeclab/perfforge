#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t n, m;
  cin >> n >> m;
  map<int64_t, vector<pair<int64_t, pair<int64_t, int64_t> > > > mp;
  int64_t idx = 0;
  while (m--) {
    int64_t l, r, t, c;
    cin >> l >> r >> t >> c;
    for (int64_t i = l; i <= r; i++) {
      mp[i].push_back(make_pair(t, make_pair(idx++, c)));
    }
  }
  int64_t profit = 0;
  for (int64_t i = 1; i <= n; i++) {
    if (mp[i].size() > 0) {
      sort(mp[i].begin(), mp[i].end());
      profit += mp[i][0].second.second;
    }
  }
  cout << profit << "\n";
  return 0;
}

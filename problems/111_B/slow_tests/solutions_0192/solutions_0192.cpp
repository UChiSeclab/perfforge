#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, vector<long long>> mp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  for (long long t = 1; t <= n; t++) {
    long long x, y;
    cin >> x >> y;
    long long cnt = 0;
    for (long long j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        long long ind =
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

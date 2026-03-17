#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> v(n);
  for (long long i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
  }
  for (long long i = 0; i < n; i++) {
    long long ans = 0;
    vector<long long> pos(5005, 0);
    for (long long j = i, c = 0;; j = (j + 1) % n, c++) {
      pos[j] = c;
      if ((j + 1) % n == i) break;
    }
    for (long long j = i;; j = (j + 1) % n) {
      long long tans = 0;
      if (v[j].size() != 0) {
        long long fin, dist = INT_MAX;
        for (auto x : v[j]) {
          long long tdist;
          if (pos[x] < pos[j])
            tdist = pos[x] + n - pos[j];
          else
            tdist = pos[x] - pos[j];
          if (tdist < dist) dist = tdist, fin = x;
        }
        if (pos[fin] < pos[j])
          tans = pos[fin] + (v[j].size()) * n;
        else
          tans = (v[j].size() - 1) * n + pos[fin];
        ans = max(ans, tans);
      }
      if ((j + 1) % n == i) break;
    }
    cout << ans << " ";
  }
  return 0;
}

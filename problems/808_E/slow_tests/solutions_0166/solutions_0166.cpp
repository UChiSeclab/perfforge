#include <bits/stdc++.h>
using namespace std;
long long cost[4][300100];
vector<long long> val[4];
long long cal(long long x) {
  long long sz = val[2].size();
  long long l = 1, r = min(x / 2, sz), best = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (cost[2][mid * 2] + cost[1][x - mid * 2] >=
        cost[2][(mid - 1) * 2] + cost[1][x - (mid - 1) * 2]) {
      best = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return cost[2][best * 2] + cost[1][x - best * 2];
}
int main() {
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      long long x, y;
      cin >> x >> y;
      val[x].push_back(y);
    }
    for (long long i = 1; i <= 3; i++) {
      sort(val[i].begin(), val[i].end());
      reverse(val[i].begin(), val[i].end());
      long long now = 0;
      for (long long j = 0; j < val[i].size(); j++) {
        now += val[i][j];
        cost[i][(j + 1) * i] = now;
      }
      for (long long j = 1; j <= m; j++) {
        cost[i][j] = max(cost[i][j], cost[i][j - 1]);
      }
    }
    long long ans = 0;
    for (long long i = 0; i <= m; i++) {
      ans = max(ans, cost[3][i] + cal(m - i));
    }
    cout << ans << endl;
    memset(cost, 0, sizeof(cost));
    for (long long i = 0; i <= 3; i++) val[i].clear();
  }
  return 0;
}

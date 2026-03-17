#include <bits/stdc++.h>
using namespace std;
long long n, r1, r2, r3, travelTime;
vector<long long> monsters;
vector<vector<long long>> dp;
long long go(int pos, int prevBoss) {
  if (pos == n) return -travelTime;
  if (dp[pos][prevBoss] != -1) return dp[pos][prevBoss];
  long long ans = 1e18;
  if (prevBoss) {
    ans = min(ans, r1 * monsters[pos] + r3 + travelTime + r1 + 2L * travelTime +
                       go(pos + 1, 0));
    if (pos == n - 1) ans = min(ans, r1 * monsters[pos] + r3 + travelTime + r1);
    ans = min(ans, r1 * monsters[pos] + r1 + travelTime + r1 + travelTime + r1 +
                       travelTime + go(pos + 1, 0));
    ans = min(ans, r2 + travelTime + r1 + travelTime + r1 + travelTime +
                       go(pos + 1, 0));
  } else {
    ans = min(ans, r1 * monsters[pos] + r3 + travelTime + go(pos + 1, 0));
    if (pos == n - 1)
      ans = min(ans, min(r1 * monsters[pos] + r1, r2) + 2L * travelTime + r1);
    if (pos != n - 1)
      ans = min(ans, r1 * monsters[pos] + r1 + travelTime + go(pos + 1, 1));
    if (pos != n - 1) ans = min(ans, r2 + travelTime + go(pos + 1, 1));
  }
  return dp[pos][prevBoss] = ans;
}
int main() {
  scanf("%lld %lld %lld %lld %lld", &n, &r1, &r2, &r3, &travelTime);
  monsters.resize(n);
  for (int i = 0; i < n; i++) scanf("%lld", &monsters[i]);
  dp.resize(n + 1, vector<long long>(2, -1));
  long long ans = go(0, 0);
  printf("%lld\n", ans);
  return 0;
}

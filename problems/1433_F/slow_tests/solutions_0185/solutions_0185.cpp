#include <bits/stdc++.h>
using namespace std;
const long long MX = 72;
const long long INF = 1e9;
long long cel[MX][MX];
long long precal[MX][MX];
long long memo[MX][MX][MX];
bool used[MX][MX][MX];
long long memo2[MX][MX];
bool used2[MX][MX];
void init() {
  for (long long i = 0; i < MX; i++) {
    for (long long j = 0; j < MX; j++) {
      for (long long k = 0; k < MX; k++) {
        memo[i][j][k] = used[i][j][k] = 0;
      }
    }
  }
}
long long sub(long long a, long long b, long long k) {
  return ((a - b) % k + k) % k;
}
long long add(long long a, long long b, long long k) { return (a + b) % k; }
long long dp(long long pos, long long md, long long cnt, long long k,
             long long m, long long id) {
  if (cnt == 0) {
    if (md == 0) return 0;
    return -INF;
  }
  if (pos == m) {
    if (md == 0) return 0;
    return -INF;
  }
  if (used[pos][md][cnt]) return memo[pos][md][cnt];
  used[pos][md][cnt] = true;
  long long ans = -INF;
  ans = max(ans, dp(pos + 1, sub(md, cel[id][pos], k), cnt - 1, k, m, id) +
                     cel[id][pos]);
  ans = max(ans, dp(pos + 1, md, cnt, k, m, id));
  memo[pos][md][cnt] = ans;
  return ans;
}
long long dp2(long long pos, long long md, long long n, long long k) {
  if (pos == n) {
    if (md == 0) return 0;
    return -INF;
  }
  if (used2[pos][md]) return memo2[pos][md];
  used2[pos][md] = true;
  long long ans = -INF;
  for (long long i = 0; i < k; i++) {
    ans = max(ans,
              dp2(pos + 1, add(md, precal[pos][i], k), n, k) + precal[pos][i]);
    ans = max(ans, dp2(pos + 1, md, n, k));
  }
  memo2[pos][md] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> cel[i][j];
  }
  for (long long i = 0; i < n; i++) {
    init();
    for (long long j = 0; j < k; j++) {
      precal[i][j] = max(dp(0, j, m / 2, k, m, i), 0ll);
    }
  }
  cout << dp2(0, 0, n, k) << "\n";
  return 0;
}

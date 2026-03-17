#include <bits/stdc++.h>
using namespace std;
const long long MAXK = 2569;
const long long MAXN = 69;
const long long INF = 1e9;
long long m, n, s, k;
long long a[MAXN];
long long color[MAXN];
long long dp[MAXN][MAXK];
long long tinh(long long id, long long z) {
  long long x = color[id];
  long long y = a[id];
  if (dp[id][z] != INF) {
    return dp[id][z];
  }
  for (long long j = 1; j <= n; j++) {
    if (a[j] < y && color[j] != x && z >= a[id])
      dp[id][z] = min(dp[id][z], tinh(j, z - a[id]) + abs(id - j));
  }
  if (dp[id][z] == INF) dp[id][z]--;
  return dp[id][z];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  string x;
  cin >> x;
  for (long long i = 1; i <= n; i++) {
    if (x[i - 1] == 'R')
      color[i] = 0;
    else if (x[i - 1] == 'B')
      color[i] = 1;
    else
      color[i] = 2;
  }
  for (long long j = 0; j <= n; j++) {
    for (long long k = 0; k < MAXK; k++) {
      dp[j][k] = INF;
    }
  }
  for (long long i = 1; i <= n; i++) {
    dp[i][a[i]] = abs(i - s);
  }
  long long ans = INF;
  for (long long i = 1; i <= n; i++) {
    for (long long j = k; j < MAXK; j++) {
      if (a[i] <= j) ans = min(ans, tinh(i, j));
    }
  }
  if (ans <= INF - 1000)
    cout << ans;
  else
    cout << -1;
}

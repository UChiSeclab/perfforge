#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long dp[501][5001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long card[5001], f[501], h[11], n, k, i, j, p, q, r, demand[100001],
      supply[100001], ans = 0;
  for (i = 0; i < 100001; i++) demand[i] = supply[i] = 0;
  map<long long, long long> make_pair;
  cin >> n >> k;
  for (i = 0; i < n * k; i++) {
    cin >> card[i];
    supply[card[i]]++;
  }
  for (i = 0; i < n; i++) {
    cin >> f[i];
    demand[f[i]]++;
  }
  h[0] = 0;
  for (i = 1; i < k + 1; i++) cin >> h[i];
  for (j = 0; j < 501; j++) dp[0][j] = 0;
  for (p = 1; p < 501; p++) {
    for (q = 1; q < 5001; q++) {
      dp[p][q] = dp[p - 1][q];
      for (r = 1; r < q + 1; r++) {
        if (r > k) break;
        dp[p][q] = max(dp[p][q], dp[p - 1][q - r] + h[r]);
      }
    }
  }
  for (i = 1; i < 100001; i++) {
    ans += dp[demand[i]][supply[i]];
  }
  cout << ans;
}

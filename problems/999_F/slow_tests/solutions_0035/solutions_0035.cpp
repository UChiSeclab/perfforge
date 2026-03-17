#include <bits/stdc++.h>
#pragma 03
using namespace std;
long long n, k;
long long cnt1[200005];
long long cnt2[200005];
long long c[5005];
long long f[505];
long long h[15];
long long dp[5005][505];
int main() {
  cin >> n >> k;
  for (int i = 0; i < 200005; i++) {
    cnt1[i] = 0;
    cnt2[i] = 0;
  }
  for (long long i = 0; i < k * n; i++) {
    cin >> c[i];
    cnt1[c[i]]++;
  }
  for (long long i = 0; i < n; i++) {
    cin >> f[i];
    cnt2[f[i]]++;
  }
  h[0] = 0;
  for (long long i = 1; i <= k; i++) cin >> h[i];
  for (long long i = 0; i < 505; i++) dp[0][i] = 0;
  for (long long i = 1; i < 5005; i++) {
    for (long long j = 1; j < 505; j++) {
      long long r = min(k, i);
      for (long long a = 0; a <= r; a++)
        dp[i][j] = max(dp[i - a][j - 1] + h[a], dp[i][j]);
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 200005; i++) ans += dp[cnt1[i]][cnt2[i]];
  cout << ans << endl;
  return 0;
}

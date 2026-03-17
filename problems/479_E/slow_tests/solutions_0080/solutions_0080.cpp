#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
long long dp[N][2], sums[N][2];
int main() {
  int n, a, b, k, d, s1, s2;
  cin >> n >> a >> b >> k;
  int f1, f2;
  if (a < b)
    f1 = 1, f2 = b - 1;
  else
    f1 = b + 1, f2 = n;
  int bit1, bit2;
  for (int j = 0; j <= k; j++) {
    bit1 = j & 1;
    bit2 = bit1 ^ 1;
    for (int i = f1; i <= f2; i++) {
      if (j == 0) {
        dp[i][bit1] = 1;
      } else {
        d = abs(b - i);
        s1 = max(f1, i - d + 1);
        s2 = min(f2, i + d - 1);
        dp[i][bit1] = sums[s2][bit2] - sums[s1 - 1][bit2] - dp[i][bit2];
        while (dp[i][bit1] < 0) {
          dp[i][bit1] += mod;
        }
        dp[i][bit1] %= mod;
      }
      if (i == f1)
        sums[i][bit1] = dp[i][bit1];
      else
        sums[i][bit1] = dp[i][bit1] + sums[i - 1][bit1], sums[i][bit1] %= mod;
    }
  }
  cout << dp[a][k & 1] << endl;
  return 0;
}
